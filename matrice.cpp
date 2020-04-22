#include <iostream>
#include "matrice.h"
using namespace std;

//CONSTRUCTOR
Matrice::Matrice()
{
	n = 0;
	m = 0;
	a = NULL;
}

//CONSTRUCTOR PARAMETRIZAT
Matrice::Matrice(int x, int y)
{
	n = x;
	m = y;
	try {
		a = new int*[n];
	}
	catch (bad_alloc&)
	{
		cout << "EROARE: Eroare in alocarea memoriei!";
		cin.get();
		exit(1);
	}

	for (int i = 0; i < n; i++)
	{
		try {
			a[i] = new int[m];
		}
		catch (bad_alloc&)
		{
			cout << "EROARE: Eroare in alocarea memoriei!";
			cin.get();
			exit(1);
		}
	}
}

//CONSTRUCTOR DE COPIERE
Matrice::Matrice(const Matrice& m1)
{
	n = m1.get_randuri();
	m = m1.get_coloane();
	
	try {
		a = new int*[n];
	}
	catch (bad_alloc&)
	{
		cout << "EROARE: Eroare in alocarea memoriei!";
		cin.get();
		exit(1);
	}
	for (int i = 0; i < n; i++)
	{
		try {
			a[i] = new int[m];
		}
		catch (bad_alloc&)
		{
			cout << "EROARE: Eroare in alocarea memoriei!";
			cin.get();
			exit(1);
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = m1(i, j);
}

//DESTRUCTOR
Matrice::~Matrice() 
{
	for (int i = 0; i < n; i++)
		delete[] a[i];

	delete[] a;
	n = 0;
	m = 0;
}

//GETTER PENTRU NR. RANDURI
int Matrice::get_randuri()const
{
	return n;
}

//GETTER PENTRU NR. COLOANE
int Matrice::get_coloane()const
{
	return m;
}

//MODIFICARE SIZE MATRICE (OVERWRITE)
void Matrice::set_size(int x, int y)
{
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete a;

	n = x;
	m = y;
	try {
		a = new int*[n];
		for (int i = 0; i < n; i++)
			a[i] = new int[m];
	}
	catch (bad_alloc&)
	{
		cout << "EROARE: Eroare in alocarea memoriei!";
		cin.get();
		exit(1);
	}
}

//UMPLE MATRICEA CU ZEROURI
void Matrice::fill_with_zeros()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = 0;
}

//SUPRAINCARCARE << PENTRU AFISARE
ostream& operator<<(ostream& out, const Matrice& a)
{
	int n = a.get_randuri();
	int m = a.get_coloane();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			out << a(i, j) << " ";
		out << "\n";
	}
	out << "\n";
	return out;

}

//SUPRAINCARCARE >> PENTRU CITIRE
istream& operator>>(istream& in, Matrice& a)
{
	int n, m;
	cout << "Introduceti numarul de linii al matricei: ";
	in >> n;
	cout << "Introduceti numarul de coloane al matricei: ";
	in >> m;
	a.set_size(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cout << "A[" << i << "][" << j << "]: ";
			in >> a(i, j);
		}

	return in;
}

//SUPRAINCARCARE =
Matrice& Matrice::operator =(const Matrice& m1)
{
	if (this != &m1)
	{
		int new_n = m1.get_randuri();
		int new_m = m1.get_coloane();

		this->set_size(new_n, new_m);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				a[i][j] = m1(i, j);
	}
	
	return *this;
}

//OPERATOR INDEXARE
int& Matrice::operator()(int x, int y)
{
	return a[x][y];
}

//OPERATOR INDEXARE
const int Matrice::operator()(int x, int y)const
{
	return a[x][y];
}

void Matrice::citire_matrice_patratica(int nr)
{
	this->set_size(nr, nr);
	
	for (int i = 0; i < nr; i++)
		for (int j = 0; j < nr; j++)
		{
			cout << "A[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}
}

void Matrice::citire_date()
{
	int n = this->get_randuri();
	int m = this->get_coloane();

	cout << "Citire matrice cu " << n << " randuri si " << m << " coloane:\n";
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cout << "A[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}
}