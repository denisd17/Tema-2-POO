#include <iostream>
#include "vector.h"
#include "matrice.h"
#include "lista.h"
#include "graf.h"
using namespace std;

void citire_n_vectori()
{
	int nr;
	cout << "Introduceti numarul de obiecte: ";
	cin >> nr;
	Vector *obiecte;

	try {
		obiecte = new Vector[nr];
	}
	catch (bad_alloc&)
	{
		cout << "EROARE: Eroare in alocarea memoriei!";
		cin.get();
		exit(1);
	}

	for (int i = 0; i < nr; i++)
		cin >> obiecte[i];

	for (int i = 0; i < nr; i++)
		cout << obiecte[i];

}

void citire_n_matrice()
{
	int nr;
	cout << "Introduceti numarul de obiecte: ";
	cin >> nr;
	Matrice *obiecte;

	try {
		obiecte = new Matrice[nr];
	}
	catch (bad_alloc&)
	{
		cout << "EROARE: Eroare in alocarea memoriei!";
		cin.get();
		exit(1);
	}

	for (int i = 0; i < nr; i++)
		cin >> obiecte[i];

	for (int i = 0; i < nr; i++)
		cout << obiecte[i];

}

void citire_n_liste()
{
	int nr;
	cout << "Introduceti numarul de obiecte: ";
	cin >> nr;
	Lista *obiecte;

	try {
		obiecte = new Lista[nr];
	}
	catch (bad_alloc&)
	{
		cout << "EROARE: Eroare in alocarea memoriei!";
		cin.get();
		exit(1);
	}

	for (int i = 0; i < nr; i++)
		cin >> obiecte[i];

	for (int i = 0; i < nr; i++)
		cout << obiecte[i];

}

void citire_n_grafuri_neorientate()
{
	int nr;
	cout << "Introduceti numarul de obiecte: ";
	cin >> nr;
	Graf_Neorientat *obiecte;

	try {
		obiecte = new Graf_Neorientat[nr];
	}
	catch (bad_alloc&)
	{
		cout << "EROARE: Eroare in alocarea memoriei!";
		cin.get();
		exit(1);
	}

	for (int i = 0; i < nr; i++)
		cin >> obiecte[i];

	for (int i = 0; i < nr; i++)
		cout << obiecte[i];

}

void citire_n_grafuri_orientate()
{
	int nr;
	cout << "Introduceti numarul de obiecte: ";
	cin >> nr;
	Graf_Orientat *obiecte;

	try {
		obiecte = new Graf_Orientat[nr];
	}
	catch (bad_alloc&)
	{
		cout << "EROARE: Eroare in alocarea memoriei!";
		cin.get();
		exit(1);
	}

	for (int i = 0; i < nr; i++)
		cin >> obiecte[i];

	for (int i = 0; i < nr; i++)
		cout << obiecte[i];

}

int main()
{
	citire_n_matrice();

	

	int n;

	cin >> n;

	return 0;


}