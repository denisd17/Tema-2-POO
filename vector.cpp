#include <iostream>
#include "vector.h"
using namespace std;

//CONSTRUCTOR DE BAZA
Vector::Vector()
{
	dim = 0;
	v = NULL;
}

//CONSTRUCTOR PARAMETRIZAT
Vector::Vector(int n)
{
	dim = n;
	
	try {
		v = new int[n];
	}
	catch (bad_alloc&)
	{
		cout << "EROARE: Eroare in alocarea memoriei!";
		cin.get();
		exit(1);
	}
}

//CONSTRUCTOR DE COPIERE
Vector::Vector(const Vector &v1)
{
	int new_dim = v1.get_size();
	
	try {
		v = new int[new_dim];
	}
	catch (bad_alloc&)
	{
		cout << "EROARE: Eroare in alocarea memoriei!";
		cin.get();
		exit(1);
	}

	dim = new_dim;
	for (int i = 0; i < new_dim; i++)
	{
		v[i] = v1[i];
	}
}

//DESTRUCTOR
Vector::~Vector()
{
	dim = 0;
	delete[] v;
}

//FUNCTIE CE SETEAZA MARIMEA VECTORULUI
void Vector::set_size(int new_dim)
{
	if (new_dim == -1 and dim == 0)
	{
		dim = new_dim;
	}
	else
	{
		dim = new_dim;
		delete[] v;
		
		try {
			v = new int[new_dim];
		}
		catch (bad_alloc&)
		{
			cout << "EROARE: Eroare in alocarea memoriei!";
			cin.get();
			exit(1);
		}

	}
}

//FUNCTIE CE RETURNEAZA DIMENSIUNEA VECTORULUI
int Vector::get_size()const
{
	return dim;
}

//FUNCTIE CE CRESTE MARIMEA VECTORULUI CU 1
void Vector::resize()
{
	dim += 1;
	int *aux;
	
	try {
		aux = new int[dim];
	}
	catch (bad_alloc&)
	{
		cout << "EROARE: Eroare in alocarea memoriei!";
		cin.get();
		exit(1);
	}

	for (int i = 0; i < dim - 1; i++)
		aux[i] = v[i];
	
	delete[] v;
	v = aux;
}

//SUPRAINCARCARE OPERATOR << PENTRU AFISARE ELEMENTE
ostream& operator<<(ostream &out,const Vector &v1)
{
	int n = v1.get_size();

	for (int i = 0; i < n; i++)
		out << v1[i] << " ";
	
	out << "\n";

	return out;
}

//SUPRAINCARCARE OPERATOR >> PENTRU CITIRE ELEMENTE
istream& operator>>(istream &in, Vector &v1)
{
	int new_dim;
	
	cout << "Introduceti numarul de elemente: ";
	in >> new_dim;

	v1.set_size(new_dim);

	for (int i = 0; i < new_dim; i++)
		in >> v1[i];

	return in;
}

//SUPRAINCARCARE OPERATOR INDEXARE L-VALUE
int& Vector::operator[](int index)
{
	return v[index];
}

//SUPRAINCARCARE OPERATOR INDEXARE R-VALUE
const int& Vector::operator[](int index)const
{
	return v[index];
}

//SUPRAINCARCARE OPERATOR = 
Vector& Vector::operator =(const Vector &v1)
{
	if (this != &v1)
	{
		int new_dim = v1.get_size();
		this->set_size(new_dim);
		for (int i = 0; i < new_dim; i++)
			v[i] = v1[i];
	}
	return *this;
}

//FUNCTIE CE ADAUGA ELEMENTE IN VECTOR UTILIZAND RESIZE
void Vector::adauga_element(int el)
{
	this->resize();
	v[dim - 1] = el;
}

//FUNCTIE UTILIZATA PENTRU A CITI N ELEMENTE SI A LE AFISA
void Vector::citire_afisare_n(int nr_el)
{
	this->set_size(nr_el);
	
	for (int i = 0; i < nr_el; i++)
	{
		cin >> v[i];
	}

	for (int i = 0; i < nr_el; i++)
	{
		cout << v[i] << " ";
	}
	
	cout << "\n";
}

void Vector::citire_date()
{
	int n = this->get_size();
	cout << "Introduceti " << n << " elemente:\n";

	for (int i = 0; i < n; i++)
		cin >> v[i];
}
