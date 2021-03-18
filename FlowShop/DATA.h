#pragma once
#include <list>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

//klasa pomocnicza
template<typename TYPE>
class DATA
{
public:
	TYPE R;
	TYPE P;
	TYPE Q;
	//****************************************
	/// POMOCNICZE DANE 
	/// (w obecnym algorytmie nie wykorzystane)
	//****************************************
	//TYPE RPQ;
	//TYPE RP;
	//TYPE PQ;
	//int RQ

	//numer wykonania pracy
	int id;

	// konstruktor
	DATA(TYPE n, TYPE r, TYPE p, TYPE q ) {
		R = r;
		P = p;
		Q = q;
		id = n;
		//RPQ = R + P + Q;
		//RP = R + P;
		//PQ = P + Q;
		//RQ = R / Q;
			}
	// wypisanie elementow klasy
	void PRINT()
	{
		cout << id << "  " 
		<< R << "  " << P <<
		 "  " << Q << endl;
	}


	//****************************************
	// metody i przeciazenia operatorów
	// w obecnym stanie nie wykorzystywane
	//****************************************
	//bool R_less_than_Q()
	//{
	//	if (R < Q) return true;
	//	else return false;
	//}

	//bool operator > (const DATA str) const
	//{
	//	return (RPQ > str.RPQ);
	//	//return (RQ > str.RQ);
	//}
	//bool operator < (const DATA str) const
	//{
	//	return (RPQ < str.RPQ);
	//	//return (RQ > str.RQ);
	//}

};

