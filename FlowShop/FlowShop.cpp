#include <iostream>
#include <vector>
#include <algorithm> 
#include <fstream>
#include "DATA.h"

using namespace std;
//****************************************
//definicje globalne
//****************************************
// definicja typu danych
#define DATA_TYPE int
// sciezka pliku
string PATH = "./rpq.data.txt";
string SOLUTION_PATH = "./solution.txt";
// rozpoznawanie zestawu danych
string DATAN[4] = { "data.1", "data.2" , "data.3", "data.4" };

//****************************************
// FUNKCJE
//****************************************

// funkcja odczytu pakietu danych z pliku
void read_from_file(int I, vector<DATA<DATA_TYPE>>& data)
{
    ifstream file(PATH);
    string s;
    // pomojaj znaki do momentu napotkania definicji paczki data.i
        while (s != DATAN[I]) file >> s;
    int amount, r, p, q;
        file >> amount;
            for (int i = 0; i < amount; i++)
    {
        file >> r >> p >> q;
        // pomocniczy kontener
        DATA<DATA_TYPE> temp(i, r, p, q);
        data.push_back(temp);
    }
}

//wypisanie wszystkich elementow wektora
 void print_from_vector(vector<DATA<DATA_TYPE>> data)
 {
     
     for (int i = 0; i < data.size(); i++)
     {
         data[i].PRINT();
     }
 }

 //liczenie dlugosci pracy dla danej kolejki
 int cmax(vector<DATA<DATA_TYPE>> data)
 {
     int m = 0, c = 0;
     for (int i = 0; i < data.size(); i++)
     {
         m = max(m, data[i].R) + data[i].P;
         c = max(c, m + data[i].Q);

     }
     return c;
 }

 //zapis do pliku
 void write_to_file(vector<DATA<DATA_TYPE>>data[]) 
 {
     ofstream file_to_write(SOLUTION_PATH);
     for (int i = 0; i < 4; i++)
     {
         file_to_write << DATAN[i] << endl <<
             data[i].size() << endl;
         for (vector<DATA<DATA_TYPE>>::iterator i_terator = data[i].begin(); i_terator != data[i].end();)
         {
             file_to_write <<
                 i_terator->R << " " <<
                 i_terator->P << " " <<
                 i_terator->Q << endl;
             i_terator++;
         }

     }
 
 }


 //****************************************
 //     ALGORYTM
 //****************************************

 //zwraca optymalna dlugosc kolejki
 //jednoczesnie dziala na oryginalnym wektorze
 //wiec kolejnosc jest zachowana
 DATA_TYPE flowshop(vector<DATA<DATA_TYPE>> &data)
 {   // zmiene pomocniczne
     int cmax1 = 0, cmax2 = 0;
     // 1/8 wielkosci zbioru danych to optymalna liczba do znalezienia najlepszego rozwiazania
     for (int DEPTH = 0; DEPTH < (data.size()/8 ); DEPTH++) {
         // dla kazdego polozenia w kolejce
         for (vector<DATA<DATA_TYPE>>::iterator i_terator = data.begin(); i_terator != data.end(); ) {
             // sprawdz czy kazdy inny element pasuje lepiej
             for (vector<DATA<DATA_TYPE>>::iterator j_terator = data.begin(); j_terator != data.end(); )
             {
                 //sprawdz dotychczasowa dlugosc pracy
                 cmax1 = cmax(data);
                 //zamien miejscami elementy
                 iter_swap(i_terator, j_terator);
                 //sprawdz nowa dlugosc kolejki
                 cmax2 = cmax(data);
                 //jezeli jest gorsza to cofnij zmiane
                 if (cmax1 < cmax2)  iter_swap(i_terator, j_terator);
                 j_terator++;
             }
             i_terator++;
         }
     }
     // zwroc optymalna dlugosc kolejki
     return cmax(data);
 }


 //****************************************
 // MAIN
 //****************************************

int main()
{
    // wektor dla kazdego zestawu danych
   vector<DATA<DATA_TYPE>> data[4];
   // laczny czas podlegajacy ocenie
   int sum_cmax=0;
   for (int k = 0; k < 4; k++) { //ma byc<4
       // odczytaj dane
       read_from_file(k, data[k]);
       
       // wywolanie algorytmu i zliczenie lacznego czasu
       // algorytm dziala na oryginale szeregujac kolejke
       sum_cmax += flowshop(data[k]);
       // wypisanie danych
       print_from_vector(data[k]);
       cout << "Wynik dla danej bazy danych" << endl;
       cout << cmax(data[k]) << endl;
   }
   cout << endl << "Wynik koncowy sumy czasow: " << sum_cmax <<endl;
   write_to_file(data);

}
