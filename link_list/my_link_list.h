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
	int create_link_list(int node_size);
	int print_link_list(int node_size, enum_link_list_mode mode);
	int add_link_list_node(int position);
	int delete_link_list_node(int position)		;
	int free_link_list(int size);
	int insert_link_list_node_tail(int node_num);
	int insert_link_list_node_head(int node_num);
	int reverse_link_list_conversion();
	int recursion_link_list();
	int has_cycle_link_list();
	int create_cycle_link_list(int node_num);
	int free_cycle_link_list(int size);
	
private:
	struct link_list *create_link_list_node();
	struct link_list *recursion_link_list_execution(struct link_list *head);

private:
	struct link_list 	*head;
	struct link_list	*head_cycle;
	int 				max_node_size;
	
};


