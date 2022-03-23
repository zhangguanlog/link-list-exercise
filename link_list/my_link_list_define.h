/**************************************************************************
*Copyright:Zhangguanlog Tomorrow Science And Technology Company
*
*Author: Zhangguanlog
*
*File_name: my_link_list_define.h
*
*Date:2022-03-22
*
*Description:创建链表用到的结构体
**************************************************************************/
#pragma once

// 链表结构体
struct link_list
{
	int school_num;				// 学号
	char name[30];				// 名字
	char grade;					// 年级
	double weight;				// 体重
	double height;				// 身高
	int age;					// 年龄
	char sex;					// 性别
	int node_num;				// 结点号
	struct link_list *next;		// 指向下一结点的指针
};

// 链表类型,0为单链表，1为环形链表
enum enum_link_list_mode
{
	enum_single_link_list = 0,
	enum_circle_link_list,
};

