#ifndef MATRICE_H
#define MATRICE_H
#include <iostream>
using namespace std;

class Matrice {
private:
	int n, m;
	int **a;

public:
	Matrice();
	Matrice(int , int);
	Matrice(const Matrice&);
	~Matrice();
	int get_randuri()const;
	int get_coloane()const;
	void set_size(int, int);
	void fill_with_zeros();
	friend ostream& operator<<(ostream&, const Matrice&);
	friend istream& operator>>(istream&, Matrice&);
	Matrice& operator =(const Matrice&);
	int& operator ()(int, int);
	const int operator()(int, int)const;
	//TO DO
	void citire_matrice_patratica(int);
	void citire_afisare_n(int);
	void citire_date();//UTILIZAT PTR MATRICE INITIALIZATA CU CONSTRUCTOR PARAMETRIZAT
};



#endif