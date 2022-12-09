#include<iostream>

using namespace std;

class Asigurare {
private:
	float valoarePolita;
public:
	Asigurare() {}

	Asigurare(float valoare) :valoarePolita(valoare) {}

	float getValoarePolita() {
		return valoarePolita;
	}

	void setValoarePolita(float valoare) {
		if (valoare > 0) {
			valoarePolita = valoare;
		}
	}
};

class ParcAuto {
private:
	int nrMasini;
	//1 parc auto are o asigurare, relatie 1:1
	// Asigurare asigurare

	//1 parc auto are mai multe asigurari, relatia este 1:m
	Asigurare** vectorAsigurari;

public:
	ParcAuto() {
		nrMasini = 0;
		vectorAsigurari = NULL;
	}

	ParcAuto(int nrMasini, Asigurare** asigurari) {
		this->nrMasini = nrMasini;
		this->vectorAsigurari = new Asigurare*[this->nrMasini];
		for (int i = 0; i < this->nrMasini; i++) {
			this->vectorAsigurari[i] = asigurari[i];
		}
	}
	~ParcAuto() {
		if (vectorAsigurari) {
			delete[] vectorAsigurari;
		}
	}

	Asigurare*& operator[](int pozitie) {
		if (pozitie >= 0 && pozitie < nrMasini) {
			return vectorAsigurari[pozitie];
		}
		throw "Index incorect";
	}

	ParcAuto(const ParcAuto& parc) {
		this->nrMasini = parc.nrMasini;
		this->vectorAsigurari = new Asigurare*[this->nrMasini];
		for (int i = 0; i < this->nrMasini; i++) {
			this->vectorAsigurari[i] = parc.vectorAsigurari[i];
		}
	}

	ParcAuto& operator=(const ParcAuto& parc) {
		if (this->vectorAsigurari) {
			delete[]this->vectorAsigurari;
		}
		this->nrMasini = parc.nrMasini;
		this->vectorAsigurari = new Asigurare*[this->nrMasini];
		for (int i = 0; i < this->nrMasini; i++) {
			this->vectorAsigurari[i] = parc.vectorAsigurari[i];
		}
		return *this;
	}

};

void main() {
	Asigurare** vectorAsigurari;
	int nrAsigurari = 3;
	vectorAsigurari = new Asigurare*[nrAsigurari];
	vectorAsigurari[0] = new Asigurare(2500);
	vectorAsigurari[1] = new Asigurare(5000);
	vectorAsigurari[2] = new Asigurare(7500);

	ParcAuto parc(nrAsigurari, vectorAsigurari);

	for (int i = 0; i < nrAsigurari; i++) {
		cout << endl << "Valoare polita de asigurare de pe pozitia " << i << "  :"
			<< parc[i]->getValoarePolita();
	}

	parc[1] = new Asigurare(7000);
	cout << endl << "Dupa modificare:" << endl;
	for (int i = 0; i < nrAsigurari; i++) {
		cout << endl << "Valoare polita de asigurare de pe pozitia " << i << "  :"
			<< parc[i]->getValoarePolita();
	}

	//dezalocari
	for (int i = 0; i < nrAsigurari; i++) {
		delete vectorAsigurari[i];
	}
	delete[] vectorAsigurari;
}