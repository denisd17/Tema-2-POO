#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using namespace std;

class Vector {
private:
	int *v;
	int dim;

public:
	Vector();
	Vector(int);
	Vector(const Vector &);
	~Vector();
	void set_size(int);
	int get_size()const;
	void resize();
	friend ostream& operator<<(ostream&, const Vector &);
	friend istream& operator>>(istream&, Vector &);
	int& operator[](int);
	const int& operator[](int)const;
	Vector& operator=(const Vector &);
	void adauga_element(int);
	void citire_afisare_n(int);
	void citire_date();
};

#endif