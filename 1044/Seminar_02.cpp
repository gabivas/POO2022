#include<iostream>
using namespace std;

int pozitieElementMaximDinVector(float* vect, int dim) {
	int max = 0;
	for (int i = 1; i < dim; i++) {
		if (vect[max] < vect[i]) {
			max = i;
		}
	}
	return max;
}

void stergereElementDePePozitie(int pozitie,
	int &dimensiune, float* &vector) {
	float* aux = new float[dimensiune - 1];
	int j = 0;
	for (int i = 0; i < dimensiune; i++) {
		if (i != pozitie) {
			aux[j] = vector[i];
			j++;
		}
	}
	delete[]vector;
	//aux are adresa #BBB
	//vector are adresa #AAA
	vector = aux;
	//vector are adresa #BBB
	dimensiune--;
}

void stergereMaximDinVector(float* &vect, int& dim) {
	int pozitieMaxim = pozitieElementMaximDinVector(
		vect, dim);
	stergereElementDePePozitie(pozitieMaxim, dim, vect);
}

void afisareVector(float vector[], int dim) {
	cout << endl << "Afisare vector:";
	for (int i = 0; i < dim; i++) {
		cout << vector[i] << " ";
	}
}

void afisareSirCaractere(const char mesaj[]) {
	cout << endl << mesaj;
}

char* sirCuLitereMari(const char mesaj[]) {
	char* sirCuLitereMari = new char[strlen(mesaj) + 1];
	strcpy_s(sirCuLitereMari, strlen(mesaj) + 1,
		mesaj);
	for (int i = 0; i < strlen(sirCuLitereMari); i++) {
		if (sirCuLitereMari[i] >= 'a'
			&& sirCuLitereMari[i] <= 'z') {
			sirCuLitereMari[i] -= 32;
		}
	}
	return sirCuLitereMari;
}

void main() {
	float* vector;
	int dimensiune = 5;
	//memorie 20B
	vector = new float[dimensiune];
	for (int i = 0; i < dimensiune; i++) {
		cin >> vector[i];
	}

	int pozitieMaxim = pozitieElementMaximDinVector(
		vector, dimensiune);
	cout << endl << "Pozitia maximului din vector:"
		<< pozitieMaxim;

	stergereMaximDinVector(vector, dimensiune);
	afisareVector(vector, dimensiune);


	//siruri de caractere
	char mesaj[] = "Seminar_02";
	afisareSirCaractere(mesaj);
	cout << endl << (int)mesaj[5];
	//printf("%d", mesaj[5]);
	char* sirCaractereCuLitereMari =
		sirCuLitereMari(mesaj);
	afisareSirCaractere(sirCaractereCuLitereMari);
	
}