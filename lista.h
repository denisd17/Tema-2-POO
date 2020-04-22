#ifndef LISTA_H
#define LISTA_H
#include "vector.h"
#include <iostream>
using namespace std;

class Lista {
private:
	Vector *l;

public:
	Lista();
	Lista(int);
	Lista(const Lista&);
	~Lista();
	void set_size(int);
	int get_size()const;
	int get_element_size(int)const;
	friend ostream& operator<<(ostream&, const Lista&);
	friend istream& operator>>(istream&, Lista&);
	void citire_lista(int);
	Lista& operator=(const Lista&);
	Vector& operator[](int);
	const Vector& operator[](int)const;
	void citire_date();

};

#endif