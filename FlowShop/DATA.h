#pragma once
#include <list>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


class DATA 
{
public:
	int R;
	int P;
	int Q;
	int RPQ;
	int lp;

	DATA(int n,int r,int p,int q ) {
		R = r;
		P = p;
		Q = q;
		lp = n;
		RPQ = R + P + Q;
			}

	void PRINT()
	{
		 cout << R << " " << P <<
			 " " << Q << "   RPQ = " 
			 << RPQ << endl;
	}

	bool R_less_than_Q()
	{
		if (R < Q) return true;
		else return false;
	}


	bool operator > (const DATA str) const
	{
		return (RPQ > str.RPQ);
	}
	bool operator < (const DATA str) const
	{
		return (RPQ < str.RPQ);
	}

};

