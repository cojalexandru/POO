// 3 modificatori:
// 1. Private: Datele sunt accesibile doar in aceeasi clasa
// 2. Protected: Datele sunt accesibile in aceeasi clasa si in clasele derivate
// 3. Public : Datele sunt accesibile in aceeasi clasa, in clasele derivate (mostenite) si in exterior
#include <iostream>
#include <string>

using namespace std;

class Persoana
{
	protected:
		string nume;
		int varsta;
	public:
		// Cream un constructor
		Persoana(string nume, int varsta)
		{
			this->nume = nume;
			this->varsta = varsta;
		}
		// Metoda de afisare
		void afisare_detalii()
		{
			cout << "Nume: " << nume << ", Varsta: " << varsta << endl;
		}
};

// Cream o clasa derivata/mostenita din Clasa Persoana
class Student : public Persoana
{
	private:
		float medie;
	public:
		// Constructor :
		Student(string nume, int varsta, float medie) : Persoana(nume, varsta)
		{
			this->medie = medie;
		}
		// Suprascrierea metodei de afisare:
		void afiseaza_informatii()
		{
			cout << "Nume: " << nume << ", Varsta: " << varsta << ", Media: " << medie << endl;
		}
		float getMedie()
		{
			return this->medie;
		}
};

int main()
{
	// Cream un obiect de tip Student
	Student s("Ion", 21, 10);
	s.afiseaza_informatii();

	// Creare obiecte, citire proprietati si afisare
	int n;
	cout << "Introduceti numarul de studenti: "; cin >> n;
	Student** studenti = new Student * [n];

	for (int i = 0; i < n; i++)
	{
		string nume;
		int varsta;
		float medie;
		cout << "Introduceti numele studentului: "; cin >> nume;
		cout << "Introduceti varsta studentului: "; cin >> varsta;
		cout << "Introduceti media studentului: "; cin >> medie;
		studenti[i] = new Student(nume, varsta, medie);
		cout << "Studentul " << nume << " a fost inregistrat!" << endl << endl;
	}

	cout << "Ati introdus urmatorii studenti: " << endl;
	for (int i = 0; i < n; i++)
		studenti[i]->afiseaza_informatii();

	// Calculul mediei adunate a studentilor
	float medie_totala = 0;
	for (int i = 0; i < n; i++)
		medie_totala += studenti[i]->getMedie();
	medie_totala /= n;

	// Plecand de la exemplul asta sa se scrie un program in C++ pentru gestiunea unei gradini zoologice, folosind clase, obiecte si conceptul de mostenire.
	// O clasa Animal -> Pasari (lungimea aripilor, durata de viata), Caini (rasa, tipul cainelui (vanatoare, asistenta etc.)

	cout << "Media totala a studentilor este: " << medie_totala;
	return 0;
}