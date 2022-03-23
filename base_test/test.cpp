/**************************************************************************
*Copyright:Zhangguanlog Tomorrow Science And Technology Company
*
*Author: Zhangguanlog
*
*File_name: test.cpp
*
*Date:2022-03-22
*
*Description:测试链表相关操作代码，操作说明：输入第二个参数为要创建的
*			链表的结点的个数，第三个参数为添加结点的位置，第四个为
*			删除结点的位置,第五个参数为需要添加结点的个数
**************************************************************************/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../link_list/my_link_list.h"

using namespace std;

/*******************************************************************
*Function:       	print_help 
*Description:    	打印操作指导函数
*Table Accessed:  
*Calls:          	需要打印操作指导函数的函数
*Input:          	无 
*Table Updated: 
*Return:         	无
*Output:         	无
*Others:         	无 
*******************************************************************/
void print_help()
{
	cout << "******************************************************************************" << endl;
	cout << "请按照如下格式输入" << endl;
	cout << "./link_list 有五个参数" << endl;
	cout << "第二个参数为要创建的链表的结点的个数，第三个参数为添加结点的位置" << endl;
	cout << "第四个为删除结点的位置,第五个参数为需要添加结点的个数" << endl;
	cout << "******************************************************************************" << endl;
}


/*******************************************************************
*Function:       	main 
*Description:    	测试链表操作的主函数
*Table Accessed:  
*Calls:          	
*Input:          	创建的链表的长度，删除链表的结点位置，增加链表
					节点的位置等
*Table Updated: 
*Return:         	无
*Output:         	无
*Others:         	无 
*******************************************************************/
int main(int argc, char *argv[])
{
	int result;
	int add_node_position;
	int delete_node_position;
	int node_size;
	int insert_num;

	if ((argc == 2) && (!strncmp(argv[1], "-h", 2)))
	{
		print_help();
		return -1;
	}

	if (argc != 5)
	{
		cout << "参数输入错误！请输入 ./link_list -h 获取帮助！" << endl;
		return -1;
	}

	node_size = atoi(argv[1]);				// 链表的长度
	add_node_position = atoi(argv[2]);		// 加入的结点的位置
	delete_node_position = atoi(argv[3]);	// 删除的结点的位置
	insert_num = atoi(argv[4]);				// 增加结点的个数
	
	my_link_list test;

	// 创建链表
	test.create_link_list(node_size);

	// 打印创建的链表
	test.print_link_list(node_size);

	// 像链表中增加结点
	result = test.add_link_list_node(add_node_position);
	if (!result)
	{
		// 增加成功后打印添加后的链表
		cout << "add after:" << endl;
		test.print_link_list(node_size + 1);
	}

	// 删除链表的某个结点
	result = test.delete_link_list_node(delete_node_position);
	if (!result)
	{
		// 删除成功后打印删除后的链表
		cout << "delete after:" << endl;
		test.print_link_list(node_size);
	}

	// 向链表尾部添加insert_num个结点
	test.insert_link_list_node_tail(insert_num);

	// 添加后打印链表
	cout << "tail insert after:" << endl;
	test.print_link_list(node_size + insert_num);

	// 向链表头结点后添加insert_num个结点
	test.insert_link_list_node_head(insert_num);

	// 打印添加后的链表
	cout << "head insert after:" << endl;
	test.print_link_list(node_size + 2 * insert_num);

	// 按照前后顺序反转链表
	test.reverse_link_list_conversion();
	cout << "reverse link list:" << endl;
	test.print_link_list(node_size + 2 * insert_num);

	// 链表反序，递归的方式
	test.recursion_link_list();
	cout << "recursion reverse link list:" << endl;
	test.print_link_list(node_size + 2 * insert_num);

	// 释放链表
	test.free_link_list(node_size + 2 * insert_num);

	return 0;
}



