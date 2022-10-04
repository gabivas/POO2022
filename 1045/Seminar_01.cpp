#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>

using namespace std;

struct Elev {
	char* nume;
	int varsta;
	float medie;
};


void afisare(Elev elev);

int suma() {
	int vector[] = { 1,2,3,4,5,6,7,8,9,10 };
	int dimensiuneVector = 10;
	int suma = 0;
	for (int i = 0; i < dimensiuneVector; i++) {
		suma = suma + vector[i];
	}
	return suma;
}

int main() {
	
	Elev elev;
	elev.medie = 10;
	elev.varsta = 18;
	elev.nume = new char[strlen("Mihai")+1];
	strcpy(elev.nume, "Mihai");

	//apel functie
	afisare(elev);

	delete[]elev.nume;
	//afisare(elev);

	int var1 = 10;
	cout << var1 << endl;
	int* var2 = &var1;
	//dereferentiere
	cout << *var2 << endl;
	cout << var1 << endl;

	cout << " Suma:" << endl;
	int valoare = 0;
	int* pointerIntreg = nullptr;
	cout << endl << pointerIntreg;
	if (pointerIntreg != nullptr) {
		cout << *pointerIntreg;
	}
	int sumaNr = suma();
	cout << endl << "Suma este:" << sumaNr;
	cout << endl << "Codul a fost executat";


	//return 0;
}

void afisare(Elev e) {
	cout << "Elevul " << e.nume << " are varsta " << e.varsta
		<< " si media " << e.medie << endl;
}
