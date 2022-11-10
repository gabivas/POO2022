#include<iostream>
using namespace std;

enum Memorie{MEM_64,MEM_128,MEM_256};

class Telefon {
private:
	const int id;
	char* marca=nullptr;
	float pret=0.0;
	Memorie memorie=Memorie::MEM_64;
	static int nrTelefoane;

public:
	Telefon(const char* marca, float pret, Memorie memorie):id(nrTelefoane++) {
		this->marca = new char[strlen(marca) + 1];
		strcpy_s(this->marca, strlen(marca) + 1, marca);
		this->pret = pret;
		this->memorie = memorie;
	}

	Telefon() :id(nrTelefoane++) {
		this->marca = new char[strlen("Fara marca") + 1];
		strcpy_s(this->marca, strlen("Fara marca") + 1, "Fara marca");
		//this->pret = pret;
		//this->memorie = memorie;
	}

	~Telefon() {
		delete[]marca;
	}

	Telefon operator=(const Telefon t) {
		if (this->marca != nullptr) {
			delete[]this->marca;
		}
		this->marca = new char[strlen(t.marca) + 1];
		strcpy_s(this->marca, strlen(t.marca) + 1, t.marca);
		this->pret = t.pret;
		this->memorie = t.memorie;

		return *this;
	}

	void afisare() {
		cout <<endl<< id << ". Telefonul cu marca " << marca << " are pretul "
			<< pret;
		if (memorie == MEM_64) {
			cout << " si memoria de 64 GB.";
		}
		else if (memorie == Memorie::MEM_128) {
			cout << " si memoria de 128 GB.";
		}
		else {
			cout << " si memoria de 256 GB.";
		}
	}

	Telefon(const Telefon& t) :id(nrTelefoane++) {
		this->marca = new char[strlen(t.marca) + 1];
		strcpy_s(this->marca, strlen(t.marca) + 1, t.marca);
		this->pret = t.pret;
		this->memorie = t.memorie;
	}
	Telefon operator+(const Telefon& t){
		Telefon telefon;
		telefon.pret = this->pret + t.pret;
		telefon.marca = new char[strlen(t.marca) + 1];
		strcpy_s(telefon.marca, strlen(t.marca) + 1, t.marca);
		telefon.memorie = this->memorie>t.memorie?this->memorie:t.memorie;

		return telefon;
	}
};
int Telefon::nrTelefoane = 1;

void main() {
	Telefon t1("Samsung",2300,MEM_128);
	t1.afisare();
	Telefon t2 = t1;
	//cout << endl << &t1 << endl << &t2;
	t2.afisare();

	Telefon t3;
	t3 = t1;
	t3.afisare();

	Telefon t4 = t1 + t2;
	t4.afisare();
}