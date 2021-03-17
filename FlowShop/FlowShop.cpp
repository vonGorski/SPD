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

 void auto_sort_R(vector<DATA>& data)
 {
    for(int j=0; j<data.size()-1; j++)
    {
        for (int i = 0; i < data.size() - j - 1; i++) {
            if (data[i].R < data[i + 1].R)
            {
                DATA temp = data[i + 1];
                data[i + 1] = data[i];
                data[i] = temp;

            }
        }
     }
 }

 void auto_sort_RP(vector<DATA>& data)
 {
     for (int j = 0; j < data.size() - 1; j++)
     {
         for (int i = 0; i < data.size() - j - 1; i++) {
             if (data[i].RP < data[i + 1].RP)
             {
                 DATA temp = data[i + 1];
                 data[i + 1] = data[i];
                 data[i] = temp;

             }
         }
     }
 }

 void auto_sort_PQ(vector<DATA>& data)
 {
     for (int j = 0; j < data.size() - 1; j++)
     {
         for (int i = 0; i < data.size() - j - 1; i++) {
             if (data[i].PQ < data[i + 1].PQ)
             {
                 DATA temp = data[i + 1];
                 data[i + 1] = data[i];
                 data[i] = temp;

             }
         }
     }

 }

 void auto_sort_Q(vector<DATA>& data)
 {
     for (int j = 0; j < data.size() - 1; j++)
     {
         for (int i = 0; i < data.size() - j - 1; i++) {
             if (data[i].Q < data[i + 1].Q)
             {
                 DATA temp = data[i + 1];
                 data[i + 1] = data[i];
                 data[i] = temp;

             }
         }
     }
 
 }


 void my_algoritm(vector<DATA> raw_data, vector<DATA>& data)
 {
     // wrzucam nawjiekszy na srodek
     data.push_back(raw_data[raw_data.size()-1]);
     for (int i = raw_data.size()-1; i>=0; i-- )
     {
         vector<DATA> temp;
         temp = data;
         temp.insert(temp.begin(), 1, raw_data[i]);
         data.push_back(raw_data[i]);
         if (cmax(data) >> cmax(temp))  data = temp;
     }
  }






int main()
{
   vector<DATA> raw_data[4];
   vector<DATA> data[4];

    for (int i = 0; i < 2; i++) { //ma byc<4
        read_from_file(i, raw_data[i]);
      //  print_from_vector(raw_data[i]);
        sort_one_vector(raw_data[i]);
        cout << " PO sortowaniu RPQ" << endl << endl;
        print_from_vector(raw_data[i]);
        cout << cmax(raw_data[i]);
       // my_algoritm(raw_data[i], data[i]);
        auto_sort_R(raw_data[i]);
        cout << " PO sortowaniu R "<< endl << endl;
        print_from_vector(raw_data[i]);
        cout << cmax(raw_data[i]) << endl;

        auto_sort_RP(raw_data[i]);
        cout << " PO sortowaniu RP" << endl << endl;
        print_from_vector(raw_data[i]);
        cout << cmax(raw_data[i]) << endl;

        auto_sort_PQ(raw_data[i]);
        cout << " PO sortowaniu PQ" << endl << endl;
        print_from_vector(raw_data[i]);
        cout << cmax(raw_data[i]) << endl;

        auto_sort_Q(raw_data[i]);
        cout << " PO sortowaniu Q" << endl << endl;
        print_from_vector(raw_data[i]);
        cout << cmax(raw_data[i]) << endl;
      //  cout << " PO sortowaniu i smiesznym algorytmie << endl;" << endl;
      //  print_from_vector(data[i]);
      //  cout << cmax(data[i]);
    }

    
}
