#pragma once

struct link_list
{
	int school_num;
	char name[30];
	char grade;
	double weight;
	double height;
	int age;
	char sex;
	int node_num;
	struct link_list *next;
};


