#ifndef GRAF_H
#define GRAF_H
#include "lista.h"
#include "matrice.h"
#include <iostream>
using namespace std;

class Graf {
protected:
	int nr_noduri;

public:
	Graf();
	Graf(int);
	Graf(const Graf&);
	virtual ~Graf();
	virtual void afisare(ostream&)const = 0;
	virtual void citire(istream&) = 0;
	friend ostream& operator<<(ostream&, const Graf&);
	friend istream& operator>>(istream&, Graf&);
	virtual void afis_vector_tati() = 0;
	virtual void citire_date() = 0;
	void set_nr_noduri(int);
	int get_nr_noduri()const;
};

class Graf_Neorientat : public Graf {
private:
	Lista L;

public:
	Graf_Neorientat();
	Graf_Neorientat(int, const Lista&);
	Graf_Neorientat(const Graf_Neorientat&);
	void afisare(ostream&)const;
	void citire(istream&);
	void afis_vector_tati();
	void citire_date();
	Lista get_list()const;
	Graf_Neorientat& operator=(const Graf_Neorientat&);
};

class Graf_Orientat : public Graf {
private:
	Matrice A;

public:
	Graf_Orientat();
	Graf_Orientat(int, const Matrice&);
	Graf_Orientat(const Graf_Orientat&);
	void afisare(ostream&)const;
	void citire(istream&);
	void afis_vector_tati();
	void citire_date();
	Matrice get_matrice()const;
};

bool este_ciclic(int*, int*, const Lista&, int, int);


#endif
