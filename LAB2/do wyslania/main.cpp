#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
//****************************************
//definicje globalne
//****************************************
// definicja typu danych
#define DATA_TYPE int
// zmienne i rozmiary
#define SIZE = 10
int LOOP = 11;
int I_size[11];
// sciezka pliku
string PATH = "./witi.data.txt";
string SOLUTION_PATH = "./solution.txt";
// rozpoznawanie zestawu danych
string DATAN[11] = { "data.10:","data.11:", "data.12:" , "data.13:", "data.14:",
"data.15:", "data.16:" , "data.17:", "data.18:", "data.19:", "data.20:" };
//****************************************
// KLASY
//****************************************
template<typename TYPE>
class DATA {
public:
    TYPE t;
    TYPE w;
    TYPE r;
    int x; // kolejnosc
};
//****************************************
// FUNKCJE
//****************************************
void print_data(int I, DATA<DATA_TYPE>** data) {
    cout << "n = " << I_size[I] << endl;
        for (int i = 0; i < I_size[I]; i++)
    {
        cout << data[I][i].x+1 << ") " << data[I][i].t << " " << data[I][i].w << " " << data[I][i].r << " " << endl;
    }
}
void read_from_file(int I, DATA<DATA_TYPE> **data, fstream &file){
    string s;
    while (s != DATAN[I]) file >> s;   
    file >> I_size[I];
    data[I] = new DATA<DATA_TYPE>[I_size[I]];
    for (int i = 0; i < I_size[I]; i++)
    {
        data[I][i].x = i;
        file >> data[I][i].t >> data[I][i].w >> data[I][i].r;
    }
          
}
void algorytm(int I, DATA<DATA_TYPE>** data)
{
    int bit = 1 << I_size[I];
    int* F = new int[bit];
    F[0] = 0;
    for (int bit_count = 1; bit_count < bit; bit_count++)  
    {
       int pomtime = 0;
        for (int i = 0, b = 1; i < I_size[I]; i++, b *= 2) 
        {
            if (bit_count & b)
            {
                pomtime += data[I][i].t;
            }
        }
        F[bit_count] = 999999;
        for (int i = 0, b = 1; i < I_size[I]; i++, b *= 2)
        {
            if (bit_count & b)
            {
                F[bit_count] = min(F[bit_count], F[bit_count - b] + data[I][i].w * max(pomtime - data[I][i].r, 0));
            }
        }
    }
    cout << "solution: " << F[bit - 1] << endl;
    cout << endl; 
    delete[] F;
}
//****************************************
// MAIN
//****************************************
int main()
{   
    DATA<DATA_TYPE>**data = new DATA<DATA_TYPE>*[10];
    fstream file;
    file.open("data.txt");
    for (int i = 0; i < LOOP; i++)
    {
        read_from_file(i, data, file);
        print_data(i, data);
        algorytm(i, data);
       
     
    }

    file.close();
    return 0;
}

