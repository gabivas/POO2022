#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;


struct Castravete {
	float seminte;
	char* gust;
	int culoare;
};

void afisareCastravete(Castravete c);

int sumaNr() {
	int vector[] = {1,2,3,4};
	int dimensiune = 4;
	int suma = vector[0];
	for (int i = 1; i < dimensiune; i++) {
		suma += vector[i];
	}
	return suma;
}

int main() {
	Castravete c1;
	c1.culoare = 1;
	c1.seminte = 20;
	c1.gust = new char[strlen("dulce") + 1];
	strcpy(c1.gust, "dulce");
	afisareCastravete(c1);
	delete[]c1.gust;

	int var1 = 15;
	cout << endl << var1;
	int* var2 = &var1;
	cout << endl << var2;
	cout << endl << &var1;
	//dereferentiere
	cout << endl << *var2;

	int valoare = 0;
	int* valoarePointer = nullptr;
	cout << endl << valoarePointer;
	if (valoarePointer != nullptr)
	{
		cout << endl << *valoarePointer;
	}
	cout << endl << sumaNr();
	cout << endl << "Codul s-a executat!";

	//return 0;
}

void afisareCastravete(Castravete c) {
	cout << "Castravetele de culoare " << c.culoare << " are " << c.seminte << " seminte" 
		<< " si gust " << c.gust << endl;

}