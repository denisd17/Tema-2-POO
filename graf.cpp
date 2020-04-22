#include <iostream>
#include "graf.h"
using namespace std;

//------------CLASA ABSTRACTA GRAF------------//

//CONSTRUCTOR
Graf::Graf()
{
	nr_noduri = 0;
}

//CONSTRUCTOR PARAMETRIZAT
Graf::Graf(int nr)
{
	nr_noduri = nr;
}

//CONSTRUCTOR DE COPIERE
Graf::Graf(const Graf& g)
{
	int nr = g.get_nr_noduri();
	nr_noduri = nr;
}

//DESTRUCTOR
Graf::~Graf()
{
	nr_noduri = 0;
}


ostream& operator<<(ostream& out, const Graf& g)
{
	g.afisare(out);
	return out;
}

istream& operator>>(istream& in, Graf& g)
{
	g.citire(in);
	return in;
}

void Graf::set_nr_noduri(int nr)
{
	nr_noduri = nr;
}

int Graf::get_nr_noduri()const
{
	return nr_noduri;
}

//------------CLASA GRAF_NEORIENTAT------------//

//CONSTRUCTOR DE BAZA
Graf_Neorientat::Graf_Neorientat() :Graf(){}

//CONSTRUCTOR PARAMETRIZAT
//PRIMESTE CA PARAMETRI NR DE NODURI SI O LISTA DE ADIACENTA
Graf_Neorientat::Graf_Neorientat(int nr, const Lista& l1) :Graf(nr)
{
	L = l1;
}

//CONSTRUCTOR DE COPIERE
//DACA APARE O PROBLEMA REMOVE APEL CONSTRUCTOR CLASA ABSTRACTA
Graf_Neorientat::Graf_Neorientat(const Graf_Neorientat& g) :Graf(g)
{
	L = g.get_list();
}

//SUPRAINCARCARE << PENTRU AFISARE
void Graf_Neorientat::afisare(ostream& out)const
{
	out << "---GRAF NEORIENTAT---\n";
	out << "Nr. de noduri al grafului este: " << nr_noduri << "\n";
	out << L;
}

//SUPRAINCARCARE >> PENTRU CITIRE
void Graf_Neorientat::citire(istream& in)
{
	cout << "Introduceti numarul de noduri: ";
	in >> nr_noduri;
	
	try {
		if (nr_noduri < 0)
			throw 10;
	}
	catch (int)
	{
		cout << "EROARE: Input invalid";
		cin.get();
		exit(1);
	}

	L.citire_lista(nr_noduri);
}

//METODA PTR. AFISAREA VECTORULUI DE TATI
void Graf_Neorientat::afis_vector_tati()
{
	cout << "Introduceti nodul radacina: ";
	int radacina;
	cin >> radacina;
	
	try {
		if(radacina >= this->get_nr_noduri() || radacina < 0)
			throw 10;
	}
	catch (int)
	{
		cout << "Eroare, nu exista nodul: " << radacina << "\n";
		return;
	}
	
	int ok = 0;
	nr_noduri = this->get_nr_noduri();
	int *v = new int[nr_noduri];
	int *viz = new int[nr_noduri];

	for (int i = 0; i < nr_noduri; i++)
	{
		v[i] = 0;
		viz[i] = 0;
	}

	Lista l = this->get_list();


	if (!este_ciclic(v, viz, l, radacina, -1))
	{
		ok = 1;

		for (int i = 0; i < nr_noduri; i++)
			if (viz[i] == 0)
				ok = 0;
	}

	if (ok == 1)
	{
		cout << "Vectorul de tati este:\n";
		
		for (int i = 0; i < nr_noduri; i++)
			cout << i << " ";

		cout << endl;
		
		for (int i = 0; i < nr_noduri; i++)
			cout << v[i] << " ";
	}
	else
		cout << "Acest graf nu are structura de arbore!";

	delete[] v;
	delete[] viz;
	
}

//
void Graf_Neorientat::citire_date()
{
	cout << "to do";
}

//GETTER PENTRU LISTA DE ADIACENTA
Lista Graf_Neorientat::get_list()const
{
	return L;
}

//SUPRAINCARCARE =
Graf_Neorientat& Graf_Neorientat::operator=(const Graf_Neorientat& g)
{
	if (this != &g)
	{
		nr_noduri = g.get_nr_noduri();
		L = g.get_list();
	}

	return *this;
}

//------------CLASA GRAF_ORIENTAT------------//

//CONSTRUCTOR DE BAZA
Graf_Orientat::Graf_Orientat() :Graf(){}

//CONSTRUCTOR PARAMETRIZAT
Graf_Orientat::Graf_Orientat(int nr, const Matrice& m1) : Graf(nr)
{
	A = m1;
}

//CONSTRUCTOR DE COPIERE
Graf_Orientat::Graf_Orientat(const Graf_Orientat& g) :Graf(g)
{
	A = g.get_matrice();
}

//AFISARE
void Graf_Orientat::afisare(ostream& out)const
{
	out << "---GRAF ORIENTAT---\n";
	out << "Nr. de noduri al grafului este: " << nr_noduri << "\n";
	out << A;
}

//CITIRE
void Graf_Orientat::citire(istream& in)
{
	cout << "Introduceti numarul de noduri: ";
	in >> nr_noduri;
	
	try {
		if (nr_noduri < 0)
			throw 10;
	}
	catch (int)
	{
		cout << "EROARE: Input invalid";
		cin.get();
		exit(1);
	}

	A.citire_matrice_patratica(nr_noduri);
}

//
void Graf_Orientat::afis_vector_tati()
{
	cout << "EROARE: Graful Orientat nu poate fi arbore.\n";
}

//
void Graf_Orientat::citire_date()
{

}

//GETTER PENTRU MATRICEA DE ADIACENTA
Matrice Graf_Orientat::get_matrice()const
{
	return A;
}

bool este_ciclic(int *v,int *viz,const Lista& l, int nod_curent, int parinte)
{
	viz[nod_curent] = 1;
	v[nod_curent] = parinte;
	int nr = l[nod_curent].get_size();

	for (int i = 0; i < nr; i++)
	{
		if (viz[l[nod_curent][i]] == 0)
		{
			v[l[nod_curent][i]] = nod_curent;
			if (este_ciclic(v, viz, l, l[nod_curent][i], nod_curent))
				return true;
		}
		else if (l[nod_curent][i] != parinte)
			return true;
	}
	return false;
}

