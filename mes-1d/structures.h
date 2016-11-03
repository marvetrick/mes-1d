#pragma once
#ifndef structures_h
#define structures_h


struct element;
struct node;

struct web
{
	web(int, double, double, double);
	int nh, ne;
	double alpha, t_alpha, q;
	element *elements;
	node *nodes;
	void init_LP();
	void init_LH();
};

struct element
{
	int id1, id2;
	double L, k, S;

	element();
	element(int, int, double, double, double);
	void setElement(int, int, double, double, double);
	double LH[2][2], LP[2];
};

struct node
{
	int BC;
	int id;
	node();
	void setNode(int, int);
};

struct solvation
{
	int n;
	double **GH;
	double *GP;
	double *GT;
	solvation(int n);
	void view_GP();
	void view_GH();
};



#endif