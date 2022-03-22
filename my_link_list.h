#pragma once
#include "my_link_list_define.h"

class my_link_list
{
public:
		my_link_list();
		~my_link_list();
public:
	int create_link_list(int node_size);
	int print_link_list(int node_size);

private:
	struct link_list *head;
	
};


