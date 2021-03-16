// Zad1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Data
{
public:
	Data() { time = 0; }
	Data(const Data& rhs);
	Data(Data&& rhs);
	~Data() = default;
	void upload(int r, int p, int q);
	int getTime() { return time; }
	void rpqAlgorithm();
	void show();

private:
	vector<int> r;
	vector<int> p;
	vector<int> q;
	int time;
};

Data::Data(const Data& rhs)
{
	r = rhs.r;
	p = rhs.p;
	q = rhs.q;
	time = rhs.time;
}
Data::Data(Data&& rhs)
{
	r = rhs.r;
	p = rhs.p;
	q = rhs.q;
	time = rhs.time;
}
void Data::upload(int r, int p, int q)
{
	this->r.push_back(r);
	this->p.push_back(p);
	this->q.push_back(q);
}
void Data::rpqAlgorithm()
{

}
void Data::show()
{
	for (int i = 0; i < r.size(); i++)
	{
		cout << r.at(i) << " " << p.at(i) << " " << q.at(i) << endl;
	}
}


int main()
{
	ifstream file("data.txt");
	if (!file.is_open())
	{
		cerr << "Nie otwarto pliku." << endl;
		exit(787);
	}

	int amount = 0;
	vector<Data> data_vec;
	int r, p, q;
	Data data;

	//wczytanie danych z pliku do klasy Data
	while (!file.eof())
	{
		//poprawnie odczytano ilosc danych
		if (file >> amount)
		{
			for (int i = 0; i < amount; i++)
			{
				file >> r >> p >> q;
				data.upload(r, p, q);
			}
			data_vec.push_back(data);

			//TUTAJ WYKONANIE ALGORYTMU DLA DANYCH
		}
		else
		{
			//file nie wczytal danych lub dane sa bledne (czyszczenie strumienia i porzucenie znakow)
			//np. dla napisu "data.1" w pliku 
			file.clear();
			file.ignore(numeric_limits<streamsize>::max(),'\n');
		}

	}
	file.close();
	/* WYSWIETLENIE WCZYTANYCH DANYCH */
	for (int i = 0; i < data_vec.size(); i++)
	{
		data_vec.at(i).show();
	}
	//##################################

	int sum = 0;
	cout << "WYNIKI" << endl;
	cout << "Ilosc danych: " << data_vec.size() << endl; //4
	for (int i = 0; i < data_vec.size(); i++)
	{
		cout << i + 1 << ". Czas: " << data_vec.at(i).getTime() << endl;
		sum += data_vec.at(i).getTime();
	}
	cout << "Suma: " << sum << endl;


	
}


// utworzyc polaczenie z plikiem przez sciezke DONE
// utworzyc strukture na te dane DONE
// wczytac je DONE
// wykonaæ algorytm do danych
// przedstawiæ wyniki
