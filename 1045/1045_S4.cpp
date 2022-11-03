#include<iostream>
#include<string>

using namespace std;

class Bloc {
public:
	const int nr;
	const int scara;
	string strada;
	bool areSubsol;
	int nrApartamente;
	float* vectorSuprafata;
	static int contor;

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
			<<" cu suprafetele:";
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
};
int Bloc::contor = 1;

void main() {
	Bloc b1;
	Bloc b2("Domneasca", 3, new float[3] {20, 50, 30}, 2, true);
	b1.afisareBloc();
	b2.afisareBloc();
	cout << endl << "Numar de blocuri: " << Bloc::contor-1;

	Bloc* pb1 = &b1;
	Bloc* pb2 = new Bloc("Dorobanti", 2, new float[2] {40, 70}, 4, false);
	pb1->afisareBloc();
	pb2->afisareBloc();
	cout << endl << "Numar de blocuri: " << Bloc::contor - 1;

	//Bloc b3("Magheru");
	//b3.afisareBloc();

	delete pb2;
}