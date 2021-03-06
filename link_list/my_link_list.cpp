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
	// 初始化单链表头head	
	head = (struct link_list*)malloc(sizeof(link_list));
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

	// 初始化环形链表头cycle_head
	head_cycle = (struct link_list*)malloc(sizeof(link_list));
	memset(head_cycle->name, 0, sizeof(head_cycle->name));
	char name1[10] = "Tangtang";
	head_cycle->node_num = 10;
	head_cycle->age = 21;
	head_cycle->grade = 3;
	head_cycle->height = 179;
	memcpy(head_cycle->name, name1, strlen(name1));
	head_cycle->school_num = 11010900;
	head_cycle->sex = 'W';
	head_cycle->weight = 78;
	head_cycle->next = NULL;
}

my_link_list::~my_link_list()
{

}

/*******************************************************************
*Function:       	create_link_list 
*Description:    	创建链表
*Table Accessed:  
*Calls:          	需要创建链表的函数
*Input:          	链表的大小 
*Table Updated: 
*Return:         	正常返回0
*Output:         	0
*Others:         	无 
*******************************************************************/
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

/*******************************************************************
*Function:       	print_link_list 
*Description:    	打印链表所有内容
*Table Accessed:  
*Calls:          	需要打印链表所有内容的函数
*Input:          	链表的大小 
*Table Updated: 
*Return:         	正常返回0
*Output:         	0
*Others:         	无 
*******************************************************************/
int my_link_list::print_link_list(int node_size, enum_link_list_mode mode)
{
	int i = 0;
	struct link_list *p;	
	
	if (mode == enum_circle_link_list)
	{
		p = head_cycle;
	}
	else if (mode == enum_single_link_list)
	{
		p = head;
	}

	for (i = 0; i < node_size; i++)
	{
		cout << p->node_num << " " << p->age << " " << p->grade << " " << p->height << " " << p->name << " " << p->node_num << " ";
		cout << p->school_num << " " << p->sex << " " << p->weight << endl;
		p = p->next;
	}

	return 0;
}

/*******************************************************************
*Function:       	create_link_list_node 
*Description:    	创建链表的一个结点
*Table Accessed:  
*Calls:          	需要创建链表的一个结点的函数
*Input:          	无 
*Table Updated: 
*Return:         	正常返回创建的结点的指针
*Output:         	创建的结点的指针
*Others:         	无 
*******************************************************************/
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

/*******************************************************************
*Function:       	add_link_list_node 
*Description:    	向链表中添加一个新的结点
*Table Accessed:  
*Calls:          	需要向链表中添加一个新的结点的函数
*Input:          	需要创建的位置
*Table Updated: 
*Return:         	正常返回0
*Output:         	0
*Others:         	无 
*******************************************************************/
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

/*******************************************************************
*Function:       	delete_link_list_node 
*Description:    	删除链表中的一个结点
*Table Accessed:  
*Calls:          	需要删除链表中的一个结点的函数
*Input:          	需要删除的结点的位置
*Table Updated: 
*Return:         	正常返回0，异常返回-1
*Output:         	0
*Others:         	无 
*******************************************************************/
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

/*******************************************************************
*Function:       	insert_link_list_node_tail 
*Description:    	向链表尾部增加多个结点
*Table Accessed:  
*Calls:          	需要向链表尾部增加多个结点的函数
*Input:          	需要增加结点的个数
*Table Updated: 
*Return:         	正常返回0，异常返回-1
*Output:         	0
*Others:         	无 
*******************************************************************/
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

/*******************************************************************
*Function:       	insert_link_list_node_tail 
*Description:    	向链表头部增加多个结点
*Table Accessed:  
*Calls:          	需要向链表头部增加多个结点的函数
*Input:          	需要增加结点的个数
*Table Updated: 
*Return:         	正常返回0，异常返回-1
*Output:         	0
*Others:         	无 
*******************************************************************/
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

/*******************************************************************
*Function:       	reverse_link_list_conversion 
*Description:    	对链表进行反序，通过单个结点的遍历反序，最后将
					头指针改变
*Table Accessed:  
*Calls:          	需要反序的链表
*Input:          	无  
*Table Updated: 
*Return:         	返回0正常，返回-1空链表
*Output:         	无 
*Others:         	无 
*******************************************************************/
int my_link_list::reverse_link_list_conversion()
{
	struct link_list *next_node = NULL;
	struct link_list *pre_node = NULL;
	struct link_list *node = head;

	if (!(head->next))
	{
		cout << "空链表，请检查！" << endl;
		return 0;
	}

	while (node)
	{
		next_node = node->next;
		node->next = pre_node;
		pre_node = node;
		node = next_node;
	}

	head = pre_node;
	return 0;
}

/*******************************************************************
*Function:       	recursion_link_list_execution 
*Description:    	对链表进行反序，通过递归的方式反序，对于当前每一
					个节点，只要让它后面的每一个节点都掉一个头，然后
					拿到掉头之后的头结点，然后指向我就可以
*Table Accessed:  
*Calls:          	需要反序的链表
*Input:          	无  
*Table Updated: 
*Return:         	返回新的头结点正常，返回NULL发生错误
*Output:         	新的链表 
*Others:         	无 
*******************************************************************/
struct link_list *my_link_list::recursion_link_list_execution(struct link_list *head_node)
{
	if (!(head_node))
	{
		cout << "空链表" << endl;
		return NULL;
	}

	if (!(head_node->next))
	{
		return head_node;
	}

	struct link_list *next = head_node->next;
	struct link_list *new_head = recursion_link_list_execution(next);
	next->next = head_node;
	head_node->next = NULL;

	return new_head;
}

/*******************************************************************
*Function:       	recursion_link_list 
*Description:    	对链表进行反序，通过递归的方式反序,接口函数
*Table Accessed:  
*Calls:          	需要反序的链表
*Input:          	无  
*Table Updated: 
*Return:         	返回0正常，返回-1空链表
*Output:         	新的链表 
*Others:         	无 
*******************************************************************/
int my_link_list::recursion_link_list()
{
	struct link_list *new_head = NULL;

	new_head = recursion_link_list_execution(head);
	if (!(new_head))
	{
		return -1;
	}

	head = new_head;

	return 0;
}

/*******************************************************************
*Function:       	has_cycle_link_list 
*Description:    	判断链表中是否有环，快指针每次走两步，慢指针走一步，
					快指针和慢指针相等的时候说明链表有环，快指针走到空
					的位置，说明链表没环。
*Table Accessed:  
*Calls:          	
*Input:          	无  
*Table Updated: 
*Return:         	返回0表示没有，返回1表示有环,返回-1表示空链表
*Output:         	新的链表 
*Others:         	无 
*******************************************************************/
int my_link_list::has_cycle_link_list()
{
	struct link_list *quik_str = head_cycle;
	struct link_list *slow_str = head_cycle;

	if (head_cycle->next == NULL)
	{
		cout << "空链表！" << endl;
		return -1;
	}

	while (1)
	{
		quik_str = quik_str->next->next;
		slow_str = slow_str->next;

		if (quik_str->next == NULL)
		{
			cout << "link no cycle!" << endl;
			return 0;
		}
		else if (quik_str == slow_str)
		{
			cout << "link has cycle" << endl;
			return 1;
		}
	}

}

/*******************************************************************
*Function:       	create_cycle_link_list 
*Description:    	创建环形链表
*Table Accessed:  
*Calls:
*Input:          	创建的链表的大小链表的大小  
*Table Updated: 
*Return:         	正常返回0
*Output:         	0 
*Others:         	无 
*******************************************************************/
int my_link_list::create_cycle_link_list(int node_num)
{
	int num;
	struct link_list *p = head_cycle;
	struct link_list *q;

	for (num = 0; num < node_num; num++)
	{
		q = (struct link_list *)malloc(sizeof(link_list));
		q->node_num = num + 11;
		p->next = q;
		p = q;
	}

	p->next = head_cycle;

	return 0;
}

/*******************************************************************
*Function:       	delete_link_list_back_node 
*Description:    	删除链表的倒数第n个结点,思路：让快指针和慢指针
					的步数差恰好为n，然后快指针走到链表结尾的时候，
					慢指针恰好走到距离链表结尾n的位置。
*Table Accessed:  
*Calls:          	
*Input:          	倒数第n个位置  
*Table Updated: 
*Return:         	正常返回0,异常返回-1
*Output:         	0 
*Others:         	无 
*******************************************************************/
int my_link_list::delete_link_list_back_node(int back_position)
{
	link *rear_ptr = head;
	link *pre_ptr = head;
	link *p;
	int cnt = 0;

	if (head->next == NULL)
	{
		cout << "空链表！delete_link_list_back_node" << endl;
		return -1;
	}

	if (back_position <= 0)
	{
		cout << "删除位置输入错误！"<< endl;
		return -1;
	}

	while (1)
	{		
		if (rear_ptr->next == NULL)
		{
			break;
		}

		if (cnt < back_position)
		{
			rear_ptr = rear_ptr->next;
		}
		else 
		{
			rear_ptr = rear_ptr->next;
			pre_ptr = pre_ptr->next;
		}
		cnt ++;
	}

	p = pre_ptr->next;
	
	pre_ptr->next = pre_ptr->next->next;

	free(p);

	return 0;
}

/*******************************************************************
*Function:       	find_link_list_middle 
*Description:    	寻找链表的中点结点,思路：快指针每次走两步，慢
					指针每次走一步，当快指针走到链表尽头的时候，慢
					指针恰好走到走到链表的重点。
*Table Accessed:  
*Calls:          	
*Input:          	无
*Table Updated: 
*Return:         	正常返回0,异常返回-1
*Output:         	0 
*Others:         	无 
*******************************************************************/
int my_link_list::find_link_list_middle_node()
{
	link *fast = head;
	link *slow = head;

	while ((fast != NULL) && (fast->next != NULL))
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	cout << slow->age << " " << slow->node_num << endl;
	
	return 0;
}


/*******************************************************************
*Function:       	free_link_list 
*Description:    	释放链表
*Table Accessed:  
*Calls:          	需释放链表的链表
*Input:          	整个链表的大小  
*Table Updated: 
*Return:         	正常返回0
*Output:         	0 
*Others:         	无 
*******************************************************************/
int my_link_list::free_link_list(int size)
{
	int node;
	struct link_list *p = head->next;
	struct link_list *q;

	cout << "free:" << endl;
	for (node = 0; node < size - 1; node++)
	{
		q = p;
		p = p->next;
		free(q);
	}

	cout << "free ok!" << endl;
	return 0;
}

/*******************************************************************
*Function:       	free_cycle_link_list 
*Description:    	释放环形链表
*Table Accessed:  
*Calls:          	需释放链表的函数
*Input:          	链表的大小  
*Table Updated: 
*Return:         	正常返回0
*Output:         	0 
*Others:         	无 
*******************************************************************/
int my_link_list::free_cycle_link_list(int size)
{
	int node;
	struct link_list *p = head_cycle->next;
	struct link_list *q;

	cout << "cycle free:" << endl;
	for (node = 0; node < size - 1; node++)
	{
		q = p;
		p = p->next;
		free(q);
	}

	cout << "cycle free ok!" << endl;
	return 0;
}


