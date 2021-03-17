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
             if (data[i].PQ > data[i + 1].PQ)
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


 void my_stiupid_algoritm(vector<DATA>& data)
 {
     vector<DATA>raw_data = data;
     // sortuje po najwiekszym RPQ
     sort_one_vector(raw_data);
     // wrzucam nawjiekszy na srodek
     data.push_back(raw_data[raw_data.size()-1]);
     for (int i = raw_data.size()-1; i>=0; i-- )
     {
         // wrzucam nawjiekszy na srodek
         data.push_back(raw_data[raw_data.size() - 1]);
         for (int i = raw_data.size() - 1; i >= 0; i--)
         {
             if (data[i].RP < data[i].PQ) data.insert(data.begin(), 1, raw_data[i]);
             else data.push_back(raw_data[i]);
         }

     }
  }






int main()
{
   vector<DATA> raw_data[4];
   vector<DATA> data[4];

    for (int k = 0; k < 1; k++) { //ma byc<4
        // odczytaj dane
        read_from_file(k, raw_data[k]);
        // tworzy trzy kopie
        vector<DATA>temp_data1 = raw_data[k];
        vector<DATA>temp_data2 = raw_data[k];
        vector<DATA>temp_data3 = raw_data[k];

        vector<int>used_one_id;

        auto_sort_RP(temp_data1);     
        auto_sort_PQ(temp_data2);
     //  my_stiupid_algoritm(temp_data3);

       // print_from_vector(temp_data1);
        cout << endl;
      //  print_from_vector(temp_data2);
        cout << endl;
        print_from_vector(temp_data3);
        cout << endl;
        // wpisywanie najmniejszych RP
        int SIZE = raw_data[k].size();
        cout << SIZE << endl;
        for (int i = temp_data1.size()-1; i>=((2*SIZE)/2)  ;i--)
        {
            used_one_id.push_back(temp_data1[i].id);
        }

      /*  for (int i = 0; i < used_one_id.size();i++)
        {
            cout << used_one_id[i] << endl;
        }*/
      
        //usuwanie juz uzytych      
        
            for (vector<DATA>::iterator it = temp_data2.begin(); it != temp_data2.end();)
            {
                bool T=false;
              //  cout << "kupa" << endl;
                for (vector<int>::iterator itj = used_one_id.begin(); itj != used_one_id.end();)
                {
                    if (*itj==it->id) {
                     //   cout << "kupa w " << endl;
                        it = temp_data2.erase(it);
                    //    cout << "kupa z" << endl;
                        T = true;
                        break;
                    }
                    else
                    {
                        ++itj;// cout << "dupa" << endl;
                     
                    }
                }
                if (T == false)  it++;
               // cout << "zbita" << endl;
            }

        // Wpisywanie najmniejszych PQ
        for (int i = SIZE - 1; used_one_id.size() <= (2 * SIZE / 3);i--)
        {
            used_one_id.push_back(temp_data1[i].id);
        }
        for (int i = SIZE/3; i > 0;i--)
        {
            used_one_id.push_back(temp_data1[i].id);
        }

        ////usuwanie juz uzytych dla data3       
        //for (vector<DATA>::iterator it = temp_data3.begin(); it != temp_data3.end();)
        //{
        //    for (int j = 0; j < used_one_id.size(); j++)
        //    {
        //        if (it->id == used_one_id[j])
        //            it = temp_data3.erase(it);
        //        else
        //            ++it;
        //    }
        //}

        for (vector<DATA>::iterator it = temp_data3.begin(); it != temp_data3.end();)
        {
            bool T = false;
           // cout << "kupa" << endl;
            for (vector<int>::iterator itj = used_one_id.begin(); itj != used_one_id.end();)
            {
                if (*itj == it->id) {
                 //   cout << "kupa w " << endl;
                    it = temp_data3.erase(it);
                 //  cout << "kupa z" << endl;
                    T = true;
                    break;
                }
                else
                {
                    ++itj;// cout << "dupa" << endl;

                }
            }
            if (T == false)  it++;
          //  cout << "zbita" << endl;
        }

        //wpisywanie RP
        for (int i = raw_data[k].size()-1; i > (2*raw_data[k].size() / 3) - 1; i--) {
            data[k].push_back(temp_data1[i]);
                }
        //wpisywanie srodka
        for (int i =  (raw_data[k].size()/3) - 1; i >= 0 ; i--) {
            data[k].push_back(temp_data3[i]);
        }
        //wpsiywanie RQ
        for (int i = (2*raw_data[k].size()/3) - 1; i > (raw_data[k].size() / 3) - 1; i--) {
            data[k].push_back(temp_data2[i]);
        }
          print_from_vector(data[k]);
           cout << cmax(data[k]);
      ////  print_from_vector(raw_data[i]);
      //  sort_one_vector(raw_data[i]);
      //  cout << " PO sortowaniu RPQ" << endl << endl;
      //  print_from_vector(raw_data[i]);
      //  cout << cmax(raw_data[i]);
      // // my_algoritm(raw_data[i], data[i]);
      //  auto_sort_R(raw_data[i]);
      //  cout << " PO sortowaniu R "<< endl << endl;
      //  print_from_vector(raw_data[i]);
      //  cout << cmax(raw_data[i]) << endl;

      //  auto_sort_RP(raw_data[i]);
      //  cout << " PO sortowaniu RP" << endl << endl;
      //  print_from_vector(raw_data[i]);
      //  cout << cmax(raw_data[i]) << endl;

      //  auto_sort_PQ(raw_data[i]);
      //  cout << " PO sortowaniu PQ" << endl << endl;
      //  print_from_vector(raw_data[i]);
      //  cout << cmax(raw_data[i]) << endl;

      //  auto_sort_Q(raw_data[i]);
      //  cout << " PO sortowaniu Q" << endl << endl;
      //  print_from_vector(raw_data[i]);
      //  cout << cmax(raw_data[i]) << endl;
      //  cout << " PO sortowaniu i smiesznym algorytmie << endl;" << endl;
      //  print_from_vector(data[i]);
      //  cout << cmax(data[i]);
    }

    
}
