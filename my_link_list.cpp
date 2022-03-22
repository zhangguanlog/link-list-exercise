#include <iostream>
#include <malloc.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include "my_link_list.h"

using namespace std;

my_link_list::my_link_list()
{
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
		cout << p->school_num << " " << p->sex << endl;
		p = p->next;
	}

	return 0;
}




