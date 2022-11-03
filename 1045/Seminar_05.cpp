#include<iostream>
#include<string>

using namespace std;

class Bloc {
private:
	const int nr;
	const int scara;
	string strada;
	bool areSubsol;
	int nrApartamente;
	float* vectorSuprafata;
	static int contor;

public:
	Bloc() :nr(contor++), scara(2) {
		strada = "Necunoscut";
		areSubsol = false;
		nrApartamente = 3;
		vectorSuprafata = new float[nrApartamente];
		for (int i = 0; i < nrApartamente; i++) {
			vectorSuprafata[i] = 20;
		}
	}

	Bloc(string strada, int nrApartamente, float*
		vectorSuprafata, int scaraParam, bool areSubsol) :nr(contor++),
		scara(scaraParam) {
		this->strada = strada;
		this->areSubsol = areSubsol;
		this->nrApartamente = nrApartamente;
		this->vectorSuprafata = new float[this->nrApartamente];
		for (int i = 0; i < this->nrApartamente; i++) {
			this->vectorSuprafata[i] = vectorSuprafata[i];
		}
	}
	~Bloc() {
		delete[] vectorSuprafata;
	}

	void afisareBloc() {
		cout << "Blocul cu numarul " << this->nr << " si cu scara "
			<< this->scara << " se afla pe strada " << this->strada
			<< " si are " << this->nrApartamente << " apartamente"
			<< " cu suprafetele:";
		for (int i = 0; i < this->nrApartamente; i++) {
			cout << this->vectorSuprafata[i] << ", ";
		}
		if (this->areSubsol == true) {
			cout << "blocul are subsol." << endl;
		}
		else {
			cout << "blocul nu are subsol." << endl;
		}
	}

	string getStrada() {
		return this->strada;
	}

	void setStrada(string stradaNoua) {
		if (stradaNoua.length() > 1) {
			this->strada = stradaNoua;
		}
	}

	int getNrApartamente() {
		return this->nrApartamente;
	}

	void setNrApartamente(int nrNouApartamente) {
		if (nrNouApartamente > 0) {
			this->nrApartamente = nrNouApartamente;
		}
	}

	void setVectorSuprafata(int nrApartamente, float* suprafete) {
		setNrApartamente(nrApartamente);
		delete[]this->vectorSuprafata;
		if (suprafete != NULL) {
			this->vectorSuprafata = new float[nrApartamente];
			for (int i = 0; i < nrApartamente; i++) {
				this->vectorSuprafata[i] = suprafete[i];
			}
		}
	}

	float* getVectorSuprafata() {
		return this->vectorSuprafata;
	}

	float getVectorSuprafataIndex(int pozitie) {
		if (pozitie > 0 && pozitie < nrApartamente) {
			return this->vectorSuprafata[pozitie];
		}
		else {
			throw "Indexul este invalid";
			//throw 404;
		}
	}

	static void setContor(int contorNou) {
		contor = contorNou;
	}

	static int getContor() {
		return contor;
	}

};
int Bloc::contor = 1;

void main() {
	Bloc b1;
	cout << b1.getStrada() << endl;
	b1.setStrada("Gheorghe Doja");
	cout << b1.getStrada() << endl;
	try {
		cout << b1.getVectorSuprafataIndex(3) << endl;
		cout << endl << "Mesaj din interiorul try-ului";
	}
	catch (const char* mesaj) {
		cout << mesaj << endl;
	}
	catch (int codExceptie) {
		cout << codExceptie << endl;
	}
	catch (...) {
		cout << "A existat o eroare"<<endl;
	}
	cout << "Mesaj dupa executia b1.getVectorSuprafataIndex(3)";

	//b1.areSubsol;
	b1.setContor(5);
	cout <<endl<< b1.getContor();

	Bloc b2;
	b2.setContor(7);
	cout << endl << b1.getContor();

	Bloc::setContor(7);

}