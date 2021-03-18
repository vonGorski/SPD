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


 int cmax(vector<DATA> data)
 {
     int m = 0, c = 0;
     for (int i = 0; i < data.size(); i++)
     {
         m = max(m, data[i].R) + data[i].P;
         c = max(c, m + data[i].Q);

     }
     return c;
 }


 int flowshop(vector<DATA> &data)
 {
     int cmax1 = cmax(data), cmax2 = 0;
     for (int loop = 0; loop < (data.size()/3 ); loop++) {

         for (vector<DATA>::iterator i_terator = data.begin(); i_terator != data.end(); ) {
             for (vector<DATA>::iterator j_terator = data.begin(); j_terator != data.end(); )
             {
                 //DATA temp=data[i]
                 cmax1 = cmax(data);
                 iter_swap(i_terator, j_terator);
                 cmax2 = cmax(data);
                 if (cmax1 < cmax2)  iter_swap(i_terator, j_terator);
                 j_terator++;
             }
             i_terator++;
         }
     }
     return cmax(data);
 }




int main()
{
   vector<DATA> data[4];
   int sum_cmax=0;
   for (int k = 0; k < 4; k++) { //ma byc<4
       // odczytaj dane
       read_from_file(k, data[k]);
       // tworzy trzy kopies
  
       sum_cmax += flowshop(data[k]);
       print_from_vector(data[k]);
       cout << "Wynik dla danej bazy danych" << endl;
       cout << cmax(data[k]) << endl;
   }
   cout << endl << "Wynik koncowy sumy czasow" << sum_cmax <<endl;
}
