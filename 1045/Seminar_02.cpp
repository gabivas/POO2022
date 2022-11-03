#include<iostream>
using namespace std;

int pozitieValoareMaximaVector(float* vector,
	int dim) {
	int maxim = 0;
	for (int i = 1; i < dim; i++) {
		if (vector[maxim] < vector[i]) {
			maxim = i;
		}
	}
	return maxim;
}

//float* reprezinta vector dinamic
void stergereValoareDinVector(float* &v, int& n,
	int pozitie) {
	float* aux = new float[n - 1];
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (i != pozitie) {
			aux[j] = v[i];
			j++;
		}
	}
	delete[]v;
	v = aux;
	n--;
}

void stergereMaximDinVector(float* &vect, int &dim) {
	int pozitieValoareMaxima = 
		pozitieValoareMaximaVector(vect, dim);
	stergereValoareDinVector(vect, dim, 
		pozitieValoareMaxima);
}

void afisareVector(float vect[], int dim) {
	cout << endl << "Afisare elemente vector:";
	for (int i = 0; i < dim; i++) {
		cout << vect[i] << " ";
	}
}

void afisareSirDeCaractere(const char mesaj[]) {
	cout << endl << mesaj;

}

char* sirCuLitereMari(const char mesajCuLitereMici[]) {
	char* sirCuLitereMari = new char[
		strlen(mesajCuLitereMici) + 1];

	strcpy_s(sirCuLitereMari, strlen(mesajCuLitereMici) + 1,
		mesajCuLitereMici);
	for (int i = 0; i < strlen(sirCuLitereMari); i++) {
		if (sirCuLitereMari[i] >= 'a' 
			&& sirCuLitereMari[i] <= 'z') {
			sirCuLitereMari[i] -= 32;
		}
	}
	return sirCuLitereMari;
 }


void main() {
	int dimensiune = 5;
	//memorie 20B
	float* vector = new float[dimensiune];
	for (int i = 0; i < dimensiune; i++) {
		cin >> vector[i];
	}
	int pozitieValoareMaxima = pozitieValoareMaximaVector(
		vector, dimensiune);
	cout << endl << "Pozitia valorii maxime:"
		<< pozitieValoareMaxima;
	cout << endl << "Vector inainte de stergere maxim:";
	afisareVector(vector, dimensiune);
	stergereMaximDinVector(vector, dimensiune);
	afisareVector(vector, dimensiune);

	//siruri de caractere
	char mesaj[] = "Seminar 02";
	afisareSirDeCaractere(mesaj);
	char* sirDeCaractereCuLitereMari =
		sirCuLitereMari(mesaj);
	afisareSirDeCaractere(sirDeCaractereCuLitereMari);

}