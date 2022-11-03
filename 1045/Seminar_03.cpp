#include<iostream>
#include<string>

using namespace std;

class Laptop {
public:
	string marca;
	int memorieRam;
	float rezolutie;

	void afisareLaptop() {
		cout << "Laptopul " << marca << " are " << memorieRam
			<< " GB memorie Ram si rezolutia " << rezolutie<<endl;
	}

	void crestereRezolutie(float valoareDeAdaugat) {
		rezolutie += valoareDeAdaugat;
	}
//private:
//protected:
};

void afisareLaptop(Laptop laptop) {
	cout << "Laptopul " << laptop.marca << " are " << laptop.memorieRam
		<< " GB memorie Ram si rezolutia " << laptop.rezolutie << endl;
}

void main() {
	Laptop laptop1;
	laptop1.marca = "Lenovo";
	laptop1.memorieRam = 16;
	laptop1.rezolutie = 1080;

	Laptop* laptopP;
	laptopP = new Laptop();
	//1.dereferentiere
	(*laptopP).marca = "Samsung";
	//prin accesare
	laptopP->memorieRam = 8;
	laptopP->rezolutie = 2060;

	Laptop* lp2 = laptopP;
	//lp2->memorieRam = 10;
	Laptop* lp3 = &laptop1;
	//lp3->marca = "Lenovo ThinkPad";

	//metode din exteriorul clasei
	afisareLaptop(laptop1);
	afisareLaptop(*laptopP);

	lp2->afisareLaptop();
	lp3->afisareLaptop();

	Laptop* vectorLaptopuri;
	int dimensiune = 3;
	vectorLaptopuri = new Laptop[dimensiune];
	for (int i = 0; i < dimensiune; i++) {
		vectorLaptopuri[i].marca = "Asus";
		vectorLaptopuri[i].memorieRam = (i + 1) * 8;
		vectorLaptopuri[i].rezolutie = (i + 1) * 1024;
	}
	cout << endl << "Afisare vector:" << endl;
	for (int i = 0; i < dimensiune; i++) {
		vectorLaptopuri[i].afisareLaptop();
	}
	delete[] vectorLaptopuri;

	for (int i = 0; i < dimensiune; i++) {
		vectorLaptopuri[i].afisareLaptop();
	}

}