#include <iostream>
#include <vector>
#include <algorithm> 
#include <fstream>
#include "DATA.h"

using namespace std;


#define DATA_TYPE int
string PATH = "./rpq.data.txt";
string DATAN[4] = { "data.1", "data.2" , "data.3", "data.4" };


void read_from_file(int I, vector<DATA>& data)
{
    ifstream file(PATH);
    string s;
        while (s != DATAN[I]) file >> s;
    int amount, r, p, q;
        file >> amount;
            for (int i = 0; i < amount; i++)
    {
        file >> r >> p >> q;
        DATA temp(i, r, p, q);
        data.push_back(temp);
    }
}


 void print_from_vector(vector<DATA> data)
 {
     for (int i = 0; i < data.size(); i++)
     {
         data[i].PRINT();
     }
 }

 void sort_one_vector(vector<DATA>& data)
 {
     sort(data.begin(), data.end());
 
 }

 void my_algoritm(vector<DATA> raw_data, vector<DATA>& data)
 {
     // wrzucam nawjiekszy na srodek
     data.push_back(raw_data[raw_data.size()-1]);
     for (int i = 1; i<raw_data.size(); i++)
     {
         if (raw_data[i].R_less_than_Q() == true) data.insert(data.begin(), 1, raw_data[i]);
         else data.push_back(raw_data[i]);
     }
  }



int main()
{
   vector<DATA> raw_data[4];
   vector<DATA> data[4];

    for (int i = 0; i < 1; i++) {
        read_from_file(i, raw_data[i]);
        print_from_vector(raw_data[i]);
        sort_one_vector(raw_data[i]);
        my_algoritm(raw_data[i], data[i]);
        cout << " PO sortowaniu i smiesznym algorytmie << endl;"
        print_from_vector(data[i]);
    }
}
