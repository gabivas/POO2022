#include<iostream>
#include<string>

using namespace std;

class Animal {
public:
	string tip;
	int varsta;
	float greutate;
//private:
	void afisareAnimal() {
		cout << tip << " are " << varsta << " ani si "
			<< greutate << " kg." << endl;
	}

	void crestereGreutate(float valoareCrestere) {
		greutate += valoareCrestere;
	}
//protected:
};

void afisareAnimal(Animal a) {
	cout << a.tip << " are " << a.varsta << " ani si "
		<< a.greutate << " kg." << endl;
}

void main() {
	Animal a1;
	a1.greutate = 2;
	a1.tip = "Pisica";
	a1.varsta = 3;

	Animal* a2;
	a2 = new Animal();
	//dereferentiere
	(*a2).greutate = 4;
	//accesare
	a2->tip = "Caine";
	a2->varsta = 5;

	//shallow copy
	Animal* a3 = a2;
	//a3->varsta = 6;
	Animal* a4 = &a1;
	//a4->varsta = 6;

	afisareAnimal(a1);

	a1.crestereGreutate(3);
	afisareAnimal(a1);
	afisareAnimal(*a2);

	a3->afisareAnimal();
	a4->afisareAnimal();

	Animal* vectorAnimale;
	int dimensiune = 3;
	vectorAnimale = new Animal[dimensiune];
	for (int i = 0; i < dimensiune; i++) {
		vectorAnimale[i].varsta = i + 1;
		vectorAnimale[i].greutate = i + 1;
		vectorAnimale[i].tip = "Generic";
	}
	cout << endl << "Afisare vector:" << endl;
	for (int i = 0; i < dimensiune; i++) {
		vectorAnimale[i].afisareAnimal();
	}
	delete[] vectorAnimale;

}