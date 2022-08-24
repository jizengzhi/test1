#ifndef _LINKLIST_H_
#define _LINKLIST_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 1000 //通讯录中最大存储人数
//功能
enum OP
{
	EXIT,	
	ADD,
	SHOW,
	FIND,
	DELE,
	REVISE
};

//个人信息
typedef struct User
{
	char id[10];
	char name[10];
	char sex[3];
	int age;
	char tel[12];
	char addr[30];
}User;


typedef int DataType;
//定义结点结构体
typedef struct node
{
    User user; //数据域
    struct node *next; //指针域
}linklist;

linklist* LinklistCreate();
//判断单链表是否为空
bool LinklistIsEmpty(linklist *head);


//头插法添加用户
void LinklistInsertHead(linklist *head);
//查看用户
void LinklistPrint(linklist *head);
//按照姓名搜索用户
User * LinklistNameSearch(linklist *head);
//修改用户信息
void LinklistUpdata(linklist *head);
//删除用户信息
void LinklistDelete(linklist *head);
//读取文件
void LoadFromFile(linklist *head);
//保存到文件
void In_read(linklist *head);

void menu();


#endif