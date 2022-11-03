#include<iostream>
#include<string>
using namespace std;

class Automobil {
public:
	const string nrMatricol;
	const int id;
	string marca;
	int nrLuni;
	float* kmPeLuna;
	static int contor;

	Automobil() :id(contor++), nrMatricol("AAA") {
		marca = "Default";
		nrLuni = 3;
		kmPeLuna = new float[nrLuni];
		for (int i = 0; i < nrLuni; i++) {
			kmPeLuna[i] = 1000;
		}
	}
	
	Automobil(string nrMatricol,string marca,
	int nrLuni, float* kmPeLuna) :id(contor++), 
		nrMatricol(nrMatricol) {
		this->marca = marca;
		this->nrLuni = nrLuni;
		this->kmPeLuna = new float[this->nrLuni];
		for (int i = 0; i < nrLuni; i++) {
			this->kmPeLuna[i] = kmPeLuna[i];
		}
		delete[] kmPeLuna;
	}
	
	~Automobil() {
		delete[] this->kmPeLuna;
	}

	void afisareAutomobil() {
		cout << "Automobilul cu numarul matricol "
			<< this->nrMatricol << ", marca "
			<< this->marca << ", id-ul "
			<< this->id << " are urmatorii km pe luna:";
		for (int i = 0; i < this->nrLuni; i++) {
			cout << this->kmPeLuna[i] << ", ";
		}
		cout << " pentru cele " << this->nrLuni
			<< " luni"<<endl;
	}

};
int Automobil::contor = 1;

void main() {
	//se apeleaza constructorul default
	Automobil a1;
	Automobil a2("B01POO", "BMW", 3, new float[3]{1200, 1100.5, 1001});

	a1.afisareAutomobil();
	a2.afisareAutomobil();
	cout << endl << Automobil::contor-1;
	Automobil* pa1 = &a1;
	Automobil* pa2 = new Automobil("B02POO", "Audi",
		2, new float[2] {1115.5, 1010});

	pa1->afisareAutomobil();
	pa2->afisareAutomobil();
	cout << endl << Automobil::contor - 1;

	//Automobil a3("BBB");
	//a3.afisareAutomobil();
	delete pa2;
	
}
