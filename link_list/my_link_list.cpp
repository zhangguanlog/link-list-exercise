/**************************************************************************
*Copyright:Zhangguanlog Tomorrow Science And Technology Company
*
*Author: Zhangguanlog
*
*File_name: my_link_list.cpp
*
*Date:2022-03-22
*
*Description:链表类的实现
**************************************************************************/
#include <iostream>
#include <malloc.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include "my_link_list.h"

using namespace std;

my_link_list::my_link_list()
{
	// 初始化链表头
	memset(head->name, 0, sizeof(head->name));
	char name[10] = "liyu";
	head->node_num = 1;
	head->age = 21;
	head->grade = 3;
	head->height = 179;
	memcpy(head->name, name, strlen(name));
	head->school_num = 11010900;
	head->sex = 'W';
	head->weight = 78;
	head->next = NULL;
}

my_link_list::~my_link_list()
{

}

int my_link_list::create_link_list(int node_size)
{
	int i;
	struct link_list *p = NULL;
	struct link_list *q = NULL;
	string name = "Zhangliang";

	p = head;
	max_node_size = node_size;
	
	for (i = 0; i < node_size - 1; i++)
	{	
		q = (struct link_list*)malloc(sizeof(struct link_list));
		q->node_num = i + 2;
		q->age = i + 18;
		q->grade = 3;
		q->height = 182;
		q->weight = 65.5;
		memcpy(q->name, name.c_str(), name.size());
		q->school_num = 11010901 + i;
		q->sex = 'M';
		p->next = q;
		p = q;
	}
		
	p->next = NULL;

	return 0;
}

int my_link_list::print_link_list(int node_size)
{
	int i = 0;
	struct link_list *p = head;

	for (i = 0; i < node_size; i++)
	{
		cout << p->node_num << " " << p->age << " " << p->grade << " " << p->height << " " << p->name << " " << p->node_num << " ";
		cout << p->school_num << " " << p->sex << " " << p->weight << endl;
		p = p->next;
	}

	return 0;
}

struct link_list *my_link_list::create_link_list_node()
{
	struct link_list *p = (struct link_list *)malloc(sizeof(struct link_list));

	memset(p->name, 0, sizeof(p->name));

	p->age = 23;
	p->grade = 4;
	p->height = 184;
	p->weight = 68.9;
	p->node_num = 11;
	p->school_num = 11010100;
	p->sex = 'W';
	memcpy(p->name, "HengHa", 6 * sizeof(char)); // 6为向名字中拷贝字符串的长度

	return p;
}

int my_link_list::add_link_list_node(int position)
{
	struct link_list *p = head;
	struct link_list *q = NULL;
	struct link_list *create_node;
	int node;

	if (position > max_node_size + 1 || position <= 1)
	{
		cout << "插入位置大于链表大小或者插入头结点！" << endl;
		return -1;
	}

	create_node = create_link_list_node();

	for (node = 0; node < position -2; node++)
	{
		p = p->next;
	}

	q = p->next;

	p->next = create_node;

	create_node->next = q;	

	return 0;
}

int my_link_list::delete_link_list_node(int position)
{
	struct link_list *p = head;
	struct link_list *q = NULL;
	struct link_list *delete_node;
	int node;

	if (position > max_node_size + 1 || position <= 1)
	{
		cout << "删除位置大于链表大小或者插入头结点！" << endl;
		return -1;
	}

	for (node = 0; node < position - 2; node++) // position的前一个位置停下来
	{
		p = p->next;
	}

	delete_node = p->next;
	q = p->next->next;
	p->next = q;

	free(delete_node);

	return 0;
}

int my_link_list::insert_link_list_node_tail(int node_num)
{
	struct link_list *p = head;
	struct link_list *q;
	int node;

	//  p指向头结点，所以指到最后一个结点的时候需要max_node -1;
	for (node = 0; node < max_node_size - 1; node++)
	{
		p = p->next;
	}

	for (node = 0; node < node_num; node++)
	{
		q = (struct link_list*)malloc(sizeof(struct link_list));
		memset(q->name, 0, sizeof(q->name));
		q->age = 110;
		q->grade = 4;
		q->height = 190;
		q->weight = 78.3;
		memcpy(q->name, "DaHu", 4); // 4为拷入名字的大小
		q->sex = 'W';
		q->node_num = max_node_size + node + 1;
		q->school_num = 11010200;
		p->next = q;
		p = q;
	}

	return 0;
}

int my_link_list::insert_link_list_node_head(int node_num)
{
	int node;
	struct link_list *old;
	struct link_list *p = head;
	struct link_list *q;
	old = p->next;

	for (node = 0; node < node_num; node++)
	{
		q = (struct link_list*)malloc(sizeof(struct link_list));
		memset(q->name, 0, sizeof(q->name));
		q->node_num = 1001 + node;
		q->grade = 0;
		p->next = q;
		p = q;
	}
	cout << sizeof(p) << " " << sizeof(struct link_list) << endl;
	p->next = old;

	return 0;
}

int my_link_list::free_link_list(int size)
{
	int node;
	struct link_list *p = head->next;
	struct link_list *q;

	cout << "free:" << endl;
	for (node = 0; node < size - 2; node++)
	{
		q = p;
		p = p->next;
		free(q);
	}

	cout << "free ok!" << endl;
	return 0;
}


