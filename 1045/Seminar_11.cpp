#include<iostream>

using namespace std;

class Animal {
private:
	float greutate;

public:
	Animal(){}
	Animal(float greutate):greutate(greutate){}
	float getGreutate() {
		return greutate;
	 }

	void setGreutate(float greutate) {
		if (greutate > 0) {
			this->greutate = greutate;
		}
	}

};

class GradinaZoo {
private:
	//GradinaZoo are un Animal, relatie 1:1
	//Animal animal;
	//GradinaZoo are mai multe obiecte de tip Animal, relatie 1:m
	Animal** vectorAnimale;
	int nrAnimale;

public:
	GradinaZoo() {
		nrAnimale = 0;
		vectorAnimale = NULL;
	}
	GradinaZoo(int nrAnimale, Animal** vector) {
		this->nrAnimale = nrAnimale;
		this->vectorAnimale = new Animal*[nrAnimale];
		for (int i = 0; i < nrAnimale; i++) {
			this->vectorAnimale[i] = vector[i];
		}
	}
	~GradinaZoo() {
		if (vectorAnimale) {
			delete[]vectorAnimale;
		}
	}

	GradinaZoo(const GradinaZoo& g) {
		this->nrAnimale = g.nrAnimale;
		this->vectorAnimale = new Animal*[g.nrAnimale];
		for (int i = 0; i < g.nrAnimale; i++) {
			this->vectorAnimale[i] = g.vectorAnimale[i];
		}
	}
	
	GradinaZoo& operator=(const GradinaZoo& g) {
		if (this->vectorAnimale) {
			delete[] vectorAnimale;
		}
		this->nrAnimale = g.nrAnimale;
		this->vectorAnimale = new Animal*[g.nrAnimale];
		for (int i = 0; i < g.nrAnimale; i++) {
			this->vectorAnimale[i] = g.vectorAnimale[i];
		}

		return *this;
	}

	Animal*& operator[](int pozitie) {
		if (pozitie >= 0 && pozitie < nrAnimale) {
			return vectorAnimale[pozitie];
		}
		throw "Pozitia nu se afla in interval";
	}

};

void main() {
	Animal** vectorAnimale;
	int nrAnimale = 4;
	vectorAnimale = new Animal*[nrAnimale];
	vectorAnimale[0] = new Animal(15);
	vectorAnimale[1] = new Animal(23);
	vectorAnimale[2] = new Animal(8);
	vectorAnimale[3] = new Animal(31);

	GradinaZoo zoo(nrAnimale, vectorAnimale);
	for (int i = 0; i < nrAnimale; i++) {
		cout << endl << "Greutate animal de pe pozitia " << i
			<< " :" << zoo[i]->getGreutate();
	}

	zoo[2]= new Animal(7);
	cout << endl << "Dupa modificare";
	for (int i = 0; i < nrAnimale; i++) {
		cout << endl << "Greutate animal de pe pozitia " << i
			<< " :" << zoo[i]->getGreutate();
	}
	for (int i = 0; i < nrAnimale; i++) {
		delete vectorAnimale[i];
	}
	delete[]vectorAnimale;
}