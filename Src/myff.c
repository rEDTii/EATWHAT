/* 自己定义的关于文件系统操作的变量和一些封装的函数，后续可能还会在这里面加w25q64写用户配置的功能 */
#include "myff.h"
#include "main.h"
#include "sd_driver.h"
#include "task.h"
#include "GUI_APP.h"


FATFS fs;
FIL file;
uint16_t fsize = 0;
BYTE fbuffer[255] = {0};          // file w/r buffer
UINT rd_count, wr_count;               // File R/W count
FRESULT res;               // FatFs function common result code
FSIZE_t ofs;							// lseek偏移量

fileList wavfileList;  //文件名链表

/*检查文件格式*/
bool endsWith(const char *str, const char *suffix) {
    if (!str || !suffix) return 0;
    size_t len_str = strlen(str);
    size_t len_suffix = strlen(suffix);
    // 若字符串比后缀短，直接返回0
    if (len_str < len_suffix) return 0;
    // 定位到末尾的子串起始位置，比较是否一致
    return strcmp(str + len_str - len_suffix, suffix) == 0;
}



// fatfs挂载
void FatfsInit() {
		/* 上电后在任务中挂载文件系统，并一直处于挂载状态，可以提高多媒体终端的响应速度（避免重复初始化SD卡） */
		res = f_mount(&fs, "0:", 1);
		if (res != FR_OK) {
				printf("Mount failed, error number: %d\r\n", res);
		}
		else{
				printf("fatfs mount ok\r\n");
		}	
}


void SD_showinfo() {
		printf("SD card info:\r\n");
 	
		 /*----------------- Read CSD/CID MSD registers ------------------*/	   
		printf( "\tCardType is :%d \r\n", SD0_CardInfo.CardType );
		printf( "\tDeviceSize is :%d \r\n", SD0_CardInfo.CSD.DeviceSize );
		printf( "\tCapacity is about:%d GB\r\n", (SD0_CardInfo.CSD.DeviceSize + 1) / 2048 );
		printf( "\tCardBlockSize is :%d \r\n", SD0_CardInfo.BlockSize );
		printf( "\tManufacturerID is :%d \r\n", SD0_CardInfo.CID.ManufacturerID );			
}


// 时间转换函数（将FATFS的日期时间格式转换为可读字符串）
static void format_time(WORD fdate, WORD ftime, char* buffer) {
    uint16_t year = (fdate >> 9) + 1980;  // 年份从1980开始
    uint8_t month = (fdate >> 5) & 0x0F;  // 月份1-12
    uint8_t day = fdate & 0x1F;           // 日1-31
    uint8_t hour = ftime >> 11;           // 小时0-23
    uint8_t minute = (ftime >> 5) & 0x3F;  // 分钟0-59
    uint8_t second = (ftime & 0x1F) * 2;  // 秒0-58（以2秒为单位）

    sprintf(buffer, "%04d-%02d-%02d %02d:%02d:%02d", 
            year, month, day, hour, minute, second);
}




void list_directory(const char* dir_name) {
//    FRESULT res;
    DIR dir;
    FILINFO fno;
    char time_buf[20];

    res = f_opendir(&dir, dir_name);
    if (res != FR_OK) {
        printf("Open dir error: %d\r\n", res);
    }

    printf("\n%-5s %-30s %12s %-20s\n", 
           "Type", "Name", "Size", "Modified");
    printf("------------------------------------------------------------\n");

    while (1) {
        res = f_readdir(&dir, &fno);
        if (res != FR_OK || fno.fname[0] == 0) break;

        // 格式化时间
        format_time(fno.fdate, fno.ftime, time_buf);

        // 打印详细信息
        printf("[%-4s] %-30s %10u B  %s\n",
               (fno.fattrib & AM_DIR) ? "DIR" : "FILE",
               fno.fname,
               fno.fsize,
               time_buf);
    }

    if (res != FR_OK) {
        printf("Read dir error: %d\r\n", res);
    }

    res = f_closedir(&dir);
    if (res != FR_OK) {
        printf("Close dir error: %d\r\n", res);
    }
}

void fatfs_show_info(void) {
		printf("\r\n-------- SD card fatfs info --------\r\n");
		SD_showinfo();
		list_directory("0:");
}


void fatfs_test() {
		printf("\r\n--------SD card fatfs test start.--------\r\n");
		/* 第一步，挂载SD卡，最后一个参数1表示立即挂载 */
		// 初始化中已挂载
//		SD_showinfo();
		
		/* 打开文件测试 */
		res = f_open(&file, "0:test.txt", FA_READ | FA_WRITE | FA_OPEN_ALWAYS);
		if (res != FR_OK) {
				printf("File open filed, error number:%d.\r\n", res);
		}
		
		/* 读取数据测试 */
		fsize = f_size(&file);
		f_read(&file, fbuffer, fsize, &rd_count);
		if (rd_count != 0) {
				printf("File read %d bytes ok, read context: %s\r\n",rd_count ,fbuffer);
				// 清空buffer
				memset(fbuffer, 0, fsize);
		}
		else {
				printf("File read empty.\r\n");
		}		
		// 关闭当前文件
		f_close(&file);
		
		
		/* 新建一个文件写数据测试 */
		res = f_open(&file, "0:wtest.txt", FA_WRITE | FA_OPEN_ALWAYS);
		if (res != FR_OK) {
				printf("File open filed, error number:%d.\r\n", res);
		}
		
		char* wr_buf = "What can I say";
		f_write(&file, wr_buf, strlen(wr_buf), &wr_count);
		if (wr_count == 0) {
				printf("File write empty.\r\n");
		}
		f_close(&file);
		
		
		/* 追加测试 */
		res = f_open(&file, "0:wtest.txt", FA_WRITE | FA_OPEN_APPEND);
		if (res != FR_OK) {
				printf("File open filed, error number:%d.\r\n", res);
		}
		
		wr_buf = ", man?";
		f_write(&file, wr_buf, strlen(wr_buf), &wr_count);
		if (wr_count == 0) {
				printf("File write failed.\r\n");
		}

		
		/* lseek测试 */
		ofs = 5;	// 这个偏移量可以用来记录WAV头里面长度字段位置，先占位，写入结束后lseek回来修改长度字段
		f_lseek(&file, ofs);
		wr_buf = "what ";
		f_write(&file, wr_buf, strlen(wr_buf), &wr_count);
		if (wr_count == 0) {
				printf("File write failed.\r\n");
		}
		f_close(&file);
		
		// 读取写入的what what  say man
		res = f_open(&file, "0:wtest.txt", FA_READ | FA_OPEN_ALWAYS);
		if (res != FR_OK) {
				printf("File open filed, error number:%d.\r\n", res);
		}
		
		fsize = f_size(&file);
		f_read(&file, fbuffer, fsize, &rd_count);
		if (rd_count != 0) {
				printf("File read %d bytes ok, read context: %s\r\n",rd_count ,fbuffer);
				memset(fbuffer, 0, fsize);
		}
		else {
				printf("File read empty.\r\n");
		}		
		// 关闭当前文件
		f_close(&file);
		
		
		/* 新建目录测试 */
		res = f_mkdir("0:test_dir");
		if (res != FR_OK) {
				printf("Directory mk filed, error number:%d.\r\n", res);
		}
		
		/* 新建一个长文件名测试 */
		res = f_open(&file, "0:中文名中文名中文名中文名.txt", FA_WRITE | FA_OPEN_ALWAYS);
		if (res != FR_OK) {
				printf("File open filed, error number:%d.\r\n", res);
		}
		wr_buf = "This is a long name file.";
		f_write(&file, wr_buf, strlen(wr_buf), &wr_count);
		if (wr_count == 0) {
				printf("File write empty.\r\n");
		}
		f_close(&file);
		
		
		/* 打印目录测试 */
		list_directory("0:");
		
		/* 删除文件测试 */
		res = f_unlink("0:wtest.txt");
		if (res != FR_OK) {
				printf("File remove filed, error number:%d.\r\n", res);
		}
		res = f_unlink("0:test_dir");
		if (res != FR_OK) {
				printf("Directory remove filed, error number:%d.\r\n", res);
		}
		
		// 再打印一次目录
		list_directory("0:");
}

void fatfs_write_one_file() {	
	/* 新建一个文件以当前时间命名 */
	char current_time_str_buff[36];
	get_rtc_time_str(current_time_str_buff);
	
	res = f_open(&file, current_time_str_buff, FA_WRITE | FA_OPEN_ALWAYS);
	if (res != FR_OK) {
			printf("File open filed, error number:%d.\r\n", res);
	}
	
	char* wr_buf = "We can substitute txt with WAV.";
	f_write(&file, wr_buf, strlen(wr_buf), &wr_count);
	if (wr_count == 0) {
			printf("File write empty.\r\n");
	}
	f_close(&file);
}

void fatfs_read_once() {
	/* 打开文件测试 */
		res = f_open(&file, "0:test.txt", FA_READ | FA_WRITE | FA_OPEN_ALWAYS);
		if (res != FR_OK) {
				printf("File open filed, error number:%d.\r\n", res);
		}
		
		/* 读取数据测试 */
		fsize = f_size(&file);
		f_read(&file, fbuffer, fsize, &rd_count);
		if (rd_count != 0) {
				printf("File read %d bytes ok, read context: %s\r\n",rd_count ,fbuffer);
				// 清空buffer
				memset(fbuffer, 0, fsize);
		}
		else {
				printf("File read empty.\r\n");
		}		
		// 关闭当前文件
		f_close(&file);
}


/********************************************************
	文件链表函数
*********************************************************/

// 创建新节点（核心工具函数）
fileNameNode* _create_node(const char* filename) {
    fileNameNode* node = (fileNameNode*)pvPortMalloc(sizeof(fileNameNode));
    if (!node) return NULL;
	
		size_t len = strlen(filename);
			
		// 动态分配内存并复制      
    node->fileName = (char *)pvPortMalloc(len + 1);   
		strcpy(node->fileName ,filename);
    if (!node->fileName) {
        vPortFree(node);
        return NULL;
    }
    node->next = NULL;
    return node;
}


// 增：在链表尾部添加文件名
void fileList_append(fileList* list, const char* filename) {
    fileNameNode* node = _create_node(filename);
    if (!node) return;

    if (!list->head) {
        list->head = node;
    } else {
        fileNameNode* cur = list->head;
        while (cur->next) cur = cur->next;  // 找到尾节点
        cur->next = node;
    }
    list->size++;
}

// 删：通过文件名删除节点
void fileList_remove(fileList* list, const char* filename) {
    fileNameNode *cur = list->head, *prev = NULL;
    while (cur) {
        if (strcmp(cur->fileName, filename) == 0) {
            if (prev) {
                prev->next = cur->next;  // 中间节点
            } else {
                list->head = cur->next;  // 头节点
            }
            vPortFree(cur->fileName);
            vPortFree(cur);
            list->size--;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

// 打印链表内容（调试用）
void fileList_print(const fileList* list) {
    printf("File List (%d items):\n", list->size);
    fileNameNode* cur = list->head;
    for (uint16_t i = 0; cur; ++i, cur = cur->next) {
        printf("[%d] %s\n", i, cur->fileName);
    }
}


/*获取文件链表以待ui显示*/
void getwavfileList(void){
		DIR dir;
		FILINFO fno;
	
		wavfileList.size = 0;
		
		res = f_opendir(&dir, "0:/recorder");
		if (res != FR_OK) {
					printf("Open dir error: %d\r\n", res);
					f_unmount("0:");
					return;
		}
		
		while (1) {
				res = f_readdir(&dir, &fno);
				if (res != FR_OK || fno.fname[0] == 0) break;

				if(fno.fattrib & AM_DIR) continue;
				// 筛选出WAV or wav结尾文件
				if( (!(endsWith(fno.fname,".wav"))) && (!(endsWith(fno.fname,".WAV"))) ) continue;
			
				fileList_append(&wavfileList,fno.fname);
				printf("%s\r\n",fno.fname);
		}
		res = f_closedir(&dir);
}






