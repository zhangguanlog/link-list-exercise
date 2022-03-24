#include <iostream>
#include <stdlib.h>
#include "../link_list/my_link_list.h"

using namespace std;

int main(int argc, char *argv[])
{
	int node_size;
	enum_link_list_mode mode;
	int delete_back_position;

	if (argc > 2)
	{
		node_size = atoi(argv[1]);
		delete_back_position = atoi(argv[2]);
	}
	else
	{
		node_size = 15;
		delete_back_position = 3;
	}
	
	mode = enum_circle_link_list; // 环形链表

	my_link_list test;

	// 创建环形链表
	test.create_cycle_link_list(node_size);

	// 打印创建的环形链表
	cout << "环形链表：" << endl;
	test.print_link_list(node_size, mode);

	// 判断环形链表中是否有环
	test.has_cycle_link_list();

	// 创建单链表
	test.create_link_list(node_size);

	// 打印创建的单向链表
	cout << "单向链表：" << endl;
	test.print_link_list(node_size, enum_single_link_list);

	// 寻找链表的中点
	cout << "链表的中点：" << endl;
	test.find_link_list_middle_node();

	// 删除单链表中指定的倒数第n个结点
	test.delete_link_list_back_node(delete_back_position);

	// 打印删除倒数第n个结点后的链表
	cout << "删除后的结果：" << endl;
	test.print_link_list(node_size - 1, enum_single_link_list);

	// 释放环形链表
	test.free_cycle_link_list(node_size);

	// 释放单向链表
	test.free_link_list(node_size - 1);

	return 0;
}


