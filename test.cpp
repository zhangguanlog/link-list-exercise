#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "my_link_list.h"

using namespace std;

int main(int argc, char *argv[])
{
	int result;
	int add_node_position;
	int delete_node_position;

	if (argc < 3)
	{
		cout << "参数输入错误！" << endl;
		return -1;
	}
	
	add_node_position = atoi(argv[1]);
	delete_node_position = atoi(argv[2]);
	
	my_link_list test;

	test.create_link_list(10);

	test.print_link_list(10);

	result = test.add_link_list_node(add_node_position);
	if (!result)
	{
		cout << "add after:" << endl;
		test.print_link_list(11);
	}


	result = test.delete_link_list_node(delete_node_position);
	if (!result)
	{
		cout << "delete after:" << endl;

		test.print_link_list(10);
	}

	test.free_link_list(10);

	return 0;
}



