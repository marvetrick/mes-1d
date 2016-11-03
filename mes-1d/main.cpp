#include <iostream>
#include <fstream>
#include "structures.h"
using namespace std;
/*
plik tekstowy:
ILOSC WEZLOW
ALFA 
T ALFA
Q
ID1 ID2 S K L
ID_W FLAGA_WAR_BRZEG
ID_W FLAGA_WAR_BRZEG
*/


int main() {
	int il_wezlow, id1, id2, idw, bc;
	double alfa, t_alfa, q, l, s, k;
	fstream plik;
	plik.open("siatka.txt", std::ios::in);
	if (plik.good() == true)
	{
		cout << "Uzyskano dostep do pliku!" << endl;
		plik >> il_wezlow;
		plik >> alfa;
		plik >> t_alfa;
		plik >> q;
		web Web(il_wezlow, alfa, t_alfa, q);
		Web.nodes = new node[Web.nh];
		Web.elements = new element[Web.ne];
		for (int i = 0; i < il_wezlow - 1; i++)
		{
			plik >> id1;
			plik >> id2;
			plik >> s;
			plik >> k;
			plik >> l;
			Web.elements[i].setElement(id1, id2, s, k, l);
			
		}
		for (int i = 0; i < il_wezlow; i++)
		{
			plik >> idw;
			plik >> bc;
			Web.nodes[i].setNode(idw, bc);
		}
		Web.init_LH();
		Web.init_LP();
		for (int i = 0; i < 2; i++) {
			
			for (int j = 0; j < 2; j++) {
			//	cout << Web.elements[1].LH[i][j] << "\t";
				cout << Web.elements[i].LP[j] << "\t";
			}
			cout << "\n";
		}

	}
	else cout << "Dostep do pliku zostal zabroniony!" << endl;

	
	
	
	system("pause");
	return 0;
}
