#include<iostream>
#include<string>
using namespace std;

class Cozonac {
private:
	const int id;
	string tip;
	int nrIngrediente;
	float* grameIngrediente;
	static int nrCozonaci;

public:
	Cozonac() :id(nrCozonaci++) {
		//cout << endl << "S-a apelat constructorul default";

		tip = "Cozonac Standard";
		this->nrIngrediente = 5;
		this->grameIngrediente = new float[nrIngrediente];
		for (int i = 0; i < nrIngrediente; i++) {
			this->grameIngrediente[i] = 100;
		}
	}

	~Cozonac() {
		delete[]grameIngrediente;
	}

	void afisareCozonac() {
		cout << id << ". " << tip << " are " << nrIngrediente << " ingrediente cu urmatoarele grame: ";
		for (int i = 0; i < nrIngrediente; i++) {
			cout << grameIngrediente[i] << ", ";
		}
		cout << endl;
	}

	Cozonac operator=(const Cozonac& c) {
		this->nrIngrediente = c.nrIngrediente;
		if (this->grameIngrediente != NULL) {
			delete[]this->grameIngrediente;
		}
		this->grameIngrediente = new float[c.nrIngrediente];
		for (int i = 0; i < c.nrIngrediente; i++) {
			this->grameIngrediente[i] = c.grameIngrediente[i];
		}
		this->tip = c.tip;

		return *this;

	}

	Cozonac(const Cozonac& c) :id(nrCozonaci++) {
		//cout << endl << "S-a apelat constructorul de copiere";
		this->nrIngrediente = c.nrIngrediente;
		this->grameIngrediente = new float[c.nrIngrediente];
		for (int i = 0; i < c.nrIngrediente; i++) {
			this->grameIngrediente[i] = c.grameIngrediente[i];
		}
		this->tip = c.tip;
	}

	Cozonac operator+(int nrIngrediente) {
		Cozonac c = *this;
		delete[] c.grameIngrediente;
		c.nrIngrediente += nrIngrediente;
		c.grameIngrediente = new float[c.nrIngrediente];
		//this->nrIngrediente = 3;
		//c.nrIngrediente = 5;
		for (int i = 0; i < this->nrIngrediente; i++) {
			c.grameIngrediente[i] = this->grameIngrediente[i];
		}
		for (int i = this->nrIngrediente; i < c.nrIngrediente; i++) {
			c.grameIngrediente[i] = 200;
		}
		return c;
	}

	Cozonac operator*(int valoare) {
		Cozonac c = *this;
		for (int i = 0; i < c.nrIngrediente; i++) {
			c.grameIngrediente[i] *= valoare;
		}
		return c;
	}

	float getGrameIngredienteIndex(int index) {
		if (index >= 0 && index < nrIngrediente) {
			return this->grameIngrediente[index];
		}
		else {
			throw "index incorect";
		}
	}

	float& operator[](int index) {
		//return this->getGrameIngredienteIndex(index);
		if (index >= 0 && index < nrIngrediente) {
			return this->grameIngrediente[index];
		}
		else {
			throw "index incorect";
		}
	}

	float getTotalGrame() {
		float suma = 0;
		for (int i = 0; i < nrIngrediente; i++) {
			//suma += this->grameIngrediente[i];
			suma += (*this)[i];
		}
		return suma;
	}

	bool operator>(Cozonac c) {
		return this->getTotalGrame() > c.getTotalGrame();
	}

	float operator()() {
		return getTotalGrame();
	}

	float operator()(int index) {
		return (*this)[index];
	}

	bool operator()(int index1, int index2) {
		return getGrameIngredienteIndex(index1) < getGrameIngredienteIndex(index2);
		//return (*this)[index1] < (*this)[index2];
	}

	//preincrementare
	Cozonac operator++() {
		for (int i = 0; i < this->nrIngrediente; i++) {
			this->grameIngrediente[i]++;
		}
		return *this;
	}

	//postincrementare
	Cozonac operator++(int) {
		Cozonac aux = *this;
		for (int i = 0; i < this->nrIngrediente; i++) {
			this->grameIngrediente[i]++;
		}
		return aux;
	}
	explicit operator int() {
		return nrIngrediente;
	}

	explicit operator float() {
		return this->getTotalGrame();
	}

	friend ostream& operator<<(ostream& afisare, const Cozonac& c);
	friend istream& operator>>(istream& citire, Cozonac& c) {
		cout << "Tip cozonac:";
		citire >> c.tip;
		cout << "Nr ingrediente:";
		citire >> c.nrIngrediente;
		delete[]c.grameIngrediente;
		c.grameIngrediente = new float[c.nrIngrediente];
		for (int i = 0; i < c.nrIngrediente; i++) {
			cout << "Grame ingredient "<< i<<":";
			citire >> c.grameIngrediente[i];
		}
		return citire;
	}


};
int Cozonac::nrCozonaci = 1;
 ostream& operator<<(ostream& afisare, const Cozonac& c) {
	 afisare << c.id << ". " << c.tip << " are " << c.nrIngrediente << " ingrediente cu urmatoarele grame: ";
	 for (int i = 0; i < c.nrIngrediente; i++) {
		 afisare << c.grameIngrediente[i] << ", ";
	 }
	 afisare << endl;

	 return afisare;
}

Cozonac operator+(int nrIngrediente, Cozonac cozonac) {
	Cozonac c;
	//se foloseste codul de la liniile 61-77
	c = cozonac + nrIngrediente;
	return c;

}

void main() {
	Cozonac c1, c2, c3;
	c1.afisareCozonac();
	Cozonac c4 = c1 + 5;
	c4.afisareCozonac();
	Cozonac c5 = 4 + c1;
	c5.afisareCozonac();
	Cozonac c6 = c1 * 2;
	c6.afisareCozonac();
	cout << c6[1];
	if (c5 > c6) {
		cout << endl << "c5 este mai mare";
	}
	else {
		cout << endl << "c6 este mai mare";
	}
	cout << endl << c6();//afisam gramele totale ale obiectului c6
	cout << endl << c6(3); // afisam gramele de pe poz 3
	//cout << c6(1, 3);
	if (c6(1, 3) == 1) {
		cout << endl << "Valoarea de pe pozitia 1 este mai mica";
	}
	else {
		cout << endl << "Valoarea de pe pozitia 3 este mai mica";
	}
	c6[1] = 99;

	cout << endl << "Inainte de operatorul ++"
		<< endl;

	c5.afisareCozonac();
	c6.afisareCozonac();

	//preincrementare
	c5=++c6;

	c5.afisareCozonac();
	c6.afisareCozonac();

	//postincrementare
	c5=c6++;

	c5.afisareCozonac();
	c6.afisareCozonac();
	//float f1 = 5.5f;
	//int i1 = (int)f1;
	int nrIngrediente = (int)c6;
	float sumaGrame = (float)c6;
	cout << endl << nrIngrediente;
	cout << endl << sumaGrame;

	Cozonac cozonac;
	//cin >> cozonac;
	cout << cozonac;

	Cozonac** vectorCozonaci= new Cozonac*[3];
	vectorCozonaci[0] = new Cozonac();
	vectorCozonaci[1] = new Cozonac();
	vectorCozonaci[2] = new Cozonac();

	vectorCozonaci[1]->afisareCozonac();
	for (int i = 0; i < 3; i++) {
		delete vectorCozonaci[i];
	}
	delete[]vectorCozonaci;

}