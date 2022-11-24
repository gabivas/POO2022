#include<iostream>
#include<string>

using namespace std;

//clasa abstracta
class Calculator {
private:
	float greutate;

public:

	Calculator(float valoare): greutate(valoare) {
		//this->greutate = valoare;
	}

	virtual float getGreutate() {
		return greutate;
	}

	void setGreutate(float valoare) {
		if (valoare > 0) {
			this->greutate = valoare;
		}
	}

	//functie virtuala pura
	virtual float getGreutateCustom() = 0;

};

class Laptop : public Calculator {
private:
	const int id;
	string culoare;
	static int contor;

public:
	float getGreutateCustom() {
		float greutateConstanta = 1;
		return greutateConstanta + this->getGreutate();
	}

	Laptop() :id(contor++), Calculator(2) {
		this->culoare = "Negru";
	}
	Laptop(string culoare, float greutate) :id(contor++), Calculator(greutate) {
		this->culoare = culoare;
	}

	~Laptop() {

	}

	void afisare() {
		cout << id << ". Laptopul are " << getGreutate() << "kg si culoare " << culoare << "." << endl;
	}

	void setCuloare(string culoare) {
		if (culoare.length() > 3) {
			this->culoare = culoare;
		}
	}

	string getCuloare() {
		return culoare;
	}

	Laptop(const Laptop& l) :id(contor++), Calculator(3) {
		this->culoare = l.culoare;
	}

	Laptop operator=(const Laptop& l) {
		this->culoare = l.culoare;

		return *this;
	}

	friend ostream& operator<<(ostream& afisare, const Laptop& laptop);


};
int Laptop::contor = 1;

ostream& operator<<(ostream& afisare, const Laptop& laptop) {
	afisare << laptop.id << ". Laptopul are culoarea " << laptop.culoare << "." << endl;
	return afisare;

}

class ExceptieValoareNegativa {
public:
	string mesaj;
	ExceptieValoareNegativa(string mesaj) {
		this->mesaj = mesaj;
	}
};


class LaptopCustom : public Laptop{
private:
	bool areMouse;
	int nrProcesoare;

public:
	LaptopCustom() :Laptop("Alb", 5) {
		areMouse = false;
		nrProcesoare = 4;
	}

	LaptopCustom(int nrP): Laptop(), areMouse(false), nrProcesoare(nrP) {
		//areMouse = false;
		//this->nrProcesoare = nrProcesoare;
	}

	LaptopCustom(int nrP, bool areM, string culoare, float gr) : Laptop(culoare, gr) {
		areMouse = areM;
		this->nrProcesoare = nrP;
	}

	LaptopCustom(const LaptopCustom& lc):Laptop(lc) {
		this->areMouse = lc.areMouse;
		this->nrProcesoare = lc.nrProcesoare;
	}

	LaptopCustom operator=(const LaptopCustom& lc) {
		Laptop::operator=(lc);
		this->areMouse = lc.areMouse;
		this->nrProcesoare = lc.nrProcesoare;
		return *this;
	}
	~LaptopCustom() {

	}

	void setNrProcesoare(int valoare) {
		if (valoare > 0) {
			this->nrProcesoare = valoare;
		}
		else {
			throw ExceptieValoareNegativa("Valoarea este mai mica de 1");
		}
	}
	int getNrProcesoare() {
		return nrProcesoare;
	}

};

ostream& operator<<(ostream& afisare, LaptopCustom& lc) {
	afisare << (Laptop)lc;
	afisare << lc.getNrProcesoare();
	return afisare;

}

void main() {
	Laptop l;
	//cout << l.getGreutateCustom();

	Calculator* c = new LaptopCustom();
	//Calculator* c1 = new Calculator(5);

	cout << c->getGreutateCustom();

	c = &l;
	cout << c->getGreutateCustom();


	//Laptop* laptop;
	//laptop = new Laptop();
	//delete laptop;
	//laptop = new Laptop[5];

	Calculator** vectorCalculatoare;
	vectorCalculatoare = new Calculator*[3];
	vectorCalculatoare[0] = new Laptop("Roz", 3);
	vectorCalculatoare[1] = new Laptop();
	vectorCalculatoare[2] = new LaptopCustom();

	for (int i = 0; i < 3; i++) {
		cout <<endl<< vectorCalculatoare[i]->getGreutateCustom();

	}
	//eliberare memorie;
}

