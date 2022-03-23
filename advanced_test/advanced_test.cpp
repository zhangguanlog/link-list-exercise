#include <iostream>
#include <stdlib.h>
#include "../link_list/my_link_list.h"

using namespace std;

int main(int argc, char *argv[])
{
	int node_size;
	enum_link_list_mode mode;

	if (argc > 1)
	{
		node_size = atoi(argv[1]);
	}
	else
	{
		node_size = 15;
	}
	

	mode = enum_circle_link_list; // 环形链表

	my_link_list test;

	test.create_cycle_link_list(node_size);

	test.print_link_list(node_size, mode);
	
	test.has_cycle_link_list();

	test.free_cycle_link_list(node_size);

	return 0;
}


