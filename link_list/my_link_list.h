/**************************************************************************
*Copyright:Zhangguanlog Tomorrow Science And Technology Company
*
*Author: Zhangguanlog
*
*File_name: my_link_list.h
*
*Date:2022-03-22
*
*Description:提供操作链表的类
**************************************************************************/
#pragma once
#include "my_link_list_define.h"

class my_link_list
{
public:
		my_link_list();
		~my_link_list();
public:
	int create_link_list(int node_size);						// 创建链表
	int print_link_list(int node_size);							// 打印链表的所有结点的值
	int add_link_list_node(int position);						// 再第position个位置插入一个结点
	int delete_link_list_node(int position)		;				// 删除第position个位置的结点
	int free_link_list(int size);								// 释放整个链表
	int insert_link_list_node_tail(int node_num);				// 像链表插入node_num个结点
	int insert_link_list_node_head(int node_num);				// 向链表头部插入node_num个结点
	
private:
	struct link_list *create_link_list_node();

private:
	struct link_list 	*head;									// 链表头节点
	int 				max_node_size;							// 创建的整个链表的大小
	
};


