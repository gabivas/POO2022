#include<iostream>
using namespace std;

 enum TipZahar{ CU_ZAHAR, FARA_ZAHAR};
 class Cafenea {
 private:
	 const int id;
	 char* numeCafenea = nullptr;
	 static int contor;
	 int nrMese = 0;
	 TipZahar tipZahar = TipZahar::FARA_ZAHAR;

 public:
	 Cafenea(const char* numeCafenea, int nrMese, TipZahar tipZahar) :id(contor++) {
		 this->numeCafenea = new char[strlen(numeCafenea) + 1];
		 strcpy_s(this->numeCafenea, strlen(numeCafenea) + 1, numeCafenea);
		 this->nrMese = nrMese;
		 this->tipZahar = tipZahar;
	 }

	 Cafenea() :id(contor++) {
		 this->numeCafenea = new char[strlen("Fara nume") + 1];
		 strcpy_s(this->numeCafenea, strlen("Fara nume") + 1, "Fara nume");
		 //this->nrMese = nrMese;
		 //this->tipZahar = tipZahar;
	 }

	 ~Cafenea() {
		 delete[]numeCafenea;
	 }

	 void afisare() {
		 cout << endl << id << ". " << numeCafenea << " are " << nrMese << " mese.";
		 if (tipZahar == TipZahar::CU_ZAHAR) {
			 cout << " Se ofera doar cafea cu zahar.";
		 }
		 else {
			 cout << " Se ofera doar cafea fara zahar.";
		 }
	 }

	 Cafenea(const Cafenea& c) :id(contor++) {
		 this->numeCafenea = new char[strlen(c.numeCafenea) + 1];
		 strcpy_s(this->numeCafenea, strlen(c.numeCafenea) + 1, c.numeCafenea);
		 this->nrMese = c.nrMese;
		 this->tipZahar = c.tipZahar;
	 }

	 Cafenea operator=(const Cafenea& c) {
		 if (this->numeCafenea != nullptr) {
			 delete[]this->numeCafenea;
		 }
		 this->numeCafenea = new char[strlen(c.numeCafenea) + 1];
		 strcpy_s(this->numeCafenea, strlen(c.numeCafenea) + 1, c.numeCafenea);
		 this->nrMese = c.nrMese;
		 this->tipZahar = c.tipZahar;

		 return *this;
	 }

	 Cafenea operator+(const Cafenea& c) {
		 Cafenea cafenea;
		 cafenea.nrMese = this->nrMese + c.nrMese;
		 cafenea.numeCafenea = new char[strlen(this->numeCafenea) + 1];
		 strcpy_s(cafenea.numeCafenea, strlen(this->numeCafenea) + 1, this->numeCafenea);
		 cafenea.tipZahar = this->tipZahar;

		 return cafenea;
	 }
 };
int Cafenea::contor = 1;

void main() {
	Cafenea c1("Starbucks", 10, TipZahar::CU_ZAHAR);
	c1.afisare();
	Cafenea c2 = c1;
	c2.afisare();
	Cafenea c3;
	c3.afisare();
	c3 = c1;
	c3.afisare();

	Cafenea c4 = c1 + c2;
	c4.afisare();
}