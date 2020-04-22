#include "lista.h"
#include "vector.h"
#include <iostream>
using namespace std;

//CONSTRUCTOR
Lista::Lista()
{
	l = NULL;
}

//CONSTRUCTOR PARAMETRIZAT
Lista::Lista(int nr_noduri)
{
	try {
		l = new Vector[nr_noduri + 1];
	}
	catch (bad_alloc&)
	{
		cout << "EROARE: Eroare in alocarea memoriei!";
		cin.get();
		exit(1);
	}
	l[nr_noduri].set_size(-1);
}

//CONSTRUCTOR DE COPIERE
Lista::Lista(const Lista& l1)
{
	int new_dim = l1.get_size();
	try {
		l = new Vector[new_dim + 1];
	}
	catch (bad_alloc&)
	{
		cout << "EROARE: Eroare in alocarea memoriei!";
		cin.get();
		exit(1);
	}
	l[new_dim].set_size(-1);

	for (int i = 0; i < new_dim; i++)
		l[i] = l1[i];
}

//DESTRUCTOR
Lista::~Lista()
{
	delete[] l;
}

//RESETARE A DIMENSIUNII
void Lista::set_size(int new_dim)
{
	delete[] l;
	try {
		l = new Vector[new_dim + 1];
	}
	catch (bad_alloc&)
	{
		cout << "EROARE: Eroare in alocarea memoriei!";
		cin.get();
		exit(1);
	}
	l[new_dim].set_size(-1);
}

//GETTER PENTRU DIMENSIUNE LISTA
int Lista::get_size()const
{
	int dim = 0;
	while (l[dim].get_size() != -1)
	{
		dim += 1;
	}
	return dim;
}

//GETTER PENTRU DIMENSIUNEA UNUI ELEMENT DIN LISTA
int Lista::get_element_size(int index)const
{
	return 1;
}

//OVERLOAD <<
ostream& operator<<(ostream& out, const Lista& l1)
{
	int dim = l1.get_size();
	for (int i = 0; i < dim; i++)
	{
		out << "Vecinii nodului " << i << " sunt: ";
		out << l1[i];
	}
	out << "\n";
	return out;
}

//CITIREA UNEI LISTE CU NR DE ELEMENTE FURNIZAT PRIN PARAMETRI
void Lista::citire_lista(int nr)
{
	this->set_size(nr);
	for (int i = 0; i < nr; i++)
		cin >> l[i];
}

//OVERLOAD >>
istream& operator>>(istream& in, Lista& l1)
{
	int nr_n;
	cout << "Introduceti numarul de noduri al grafului: ";
	in >> nr_n;

	l1.set_size(nr_n);

	for (int i = 0; i < nr_n; i++)
		in >> l1[i];

	return in;
}

//OPERATOR =
Lista& Lista::operator=(const Lista& l1)
{
	if (this != &l1)
	{
		int new_dim = l1.get_size();
		this->set_size(new_dim);

		for (int i = 0; i < new_dim; i++)
			l[i] = l1[i];
	}

	return *this;
}

//OPERATOR INDEXARE
Vector& Lista::operator[](int index)
{
	return l[index];
}

//OPERATOR INDEXARE
const Vector& Lista::operator[](int index)const
{
	return l[index];
}

//CITIRE DATE
void Lista::citire_date()
{
	int nr_n = this->get_size();

	cout << "Citire date lista cu " << nr_n << " elemente\n";

	for (int i = 0; i < nr_n; i++)
		cin >> l[i];

}