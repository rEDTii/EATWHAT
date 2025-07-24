/* 自己定义的关于文件系统操作的变量和一些封装的函数，后续可能还会在这里面加w25q64写用户配置的功能 */
#ifndef _MYFF_H_
#define _MYFF_H_

#include "fm33fk5xx_fl.h"
#include "ff.h"


extern FATFS fs;
extern FIL file;
extern uint16_t fsize;
extern BYTE fbuffer[255];          // file w/r buffer
extern UINT rd_count, wr_count;               // File R/W count
extern FRESULT res;               // FatFs function common result code
extern FSIZE_t ofs;							// lseek偏移量




// 链表节点结构（动态文件名字符串存储）
typedef struct fileNameNode {
    char* fileName;                  // 动态分配的文件名字符串
    struct fileNameNode* next; // 指向下一个节点
} fileNameNode;

// 文件名链表管理结构（包含头指针和长度）
typedef struct {
    fileNameNode* head;      // 链表头指针
    int size;                  // 链表长度（可选）
} fileList;

extern fileList wavfileList;  //文件名链表


void FatfsInit();
void getwavfileList(void);
void get_rtc_time_str(char* buffer);
void fatfs_test();
void list_directory(const char* dir_name);
void fatfs_show_info(void);
void fatfs_write_one_file();
void SD_showinfo();
void fatfs_read_once();
void fileList_remove(fileList* list, const char* filename); 
void fileList_append(fileList* list, const char* filename);
void fileList_print(const fileList* list);

#endif