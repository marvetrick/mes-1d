#include "structures.h"
#include <fstream>


web::web(int a, double b, double c, double d )
{
	this->nh = a;
	this->t_alpha = b;
	this->alpha = c;
	this->q = d;
	this->ne = this->nh - 1;
}

void web::init_LP()
{
	for (int i = 0; i < ne; i++) {
		elements[i].LP[0] = 0;
		elements[i].LP[1] = 0;
	}
		
	int tmpID=0;
	int tmpID2=0;
	for (int i = 0; i < nh; i++)
	{
		if (nodes[i].BC == 2)
			tmpID = nodes[i].id;
		if (nodes[i].BC == 1)
			tmpID2 = nodes[i].id;
	}

	for (int i = 0; i < ne; i++) {

		if (elements[i].id1 == tmpID2)
			elements[i].LP[0] -= elements[i].S*t_alpha;
		if (elements[i].id2 == tmpID)
			elements[i].LP[1] += elements[i].S*q;
	}

}

void web::init_LH()
{
	int tmpID;
	for (int i = 0; i < ne; i++) {
		elements[i].LH[0][0] = (elements[i].k*elements[i].S) / elements[i].L;
		elements[i].LH[0][1] = -(elements[i].k*elements[i].S) / elements[i].L;
		elements[i].LH[1][0] = -(elements[i].k*elements[i].S) / elements[i].L;
		elements[i].LH[1][1] = (elements[i].k*elements[i].S) / elements[i].L;
	}
	for (int i = 0; i < nh; i++)
	{
		if (nodes[i].BC == 2)
			tmpID = nodes[i].id;
	}
	for (int i = 0; i < ne; i++) {
		
		if (elements[i].id1 == tmpID)
			elements[i].LH[0][0]+=alpha*elements[i].S;
		else if (elements[i].id2 == tmpID)
			elements[i].LH[1][1] += alpha*elements[i].S;
	}
}

element::element()
{
}

element::element(int id_1w, int id_2w, double L , double k, double S)
{
	this->id1 = id_1w;
	this->id2 = id_2w;
	this->L = L;
	this->k = k;
	this->S = S;

}

void element::setElement(int id_1w, int id_2w, double L, double k, double S)
{
	this->id1 = id_1w;
	this->id2 = id_2w;
	this->L = L;
	this->k = k;
	this->S = S;
}

node::node()
{
}

void node::setNode(int id, int bc)
{
	this->BC = bc;
	this->id = id;
}

