#include <iostream>
#include <string>

using namespace std;

// clasa principala
class Persoana
{
protected:
	string nume;
	int varsta;
public:
	Persoana(string nume, int varsta)
	{
		this->nume = nume;
		this->varsta = varsta;
	}

	void afiseazaInformatii()
	{
		cout << "Nume: " << nume << ", Varsta: " << varsta << endl;
	}
};

// clasa derivata
class Student : public Persoana {
private:
	float medie;
	// clasa prietena
	friend class Admin;
public:
	Student(string nume, int varsta, float medie) : Persoana(nume, varsta)
	{
		this->medie = medie;
	}

	void afiseazaInformatii()
	{
		cout << "Nume: " << nume << ", Varsta: " << varsta << ", Medie: " << medie << endl;
	}
};

class Admin
{
public:
	// Folosind '&' inseamna ca lucram cu o referinta, adica un alias pentru o variabila existenta - NU O COPIE
	void modificaMedie(Student& s, float nouaMedie)
	{
		cout << "Modific media pentru " << s.nume << " de la " << s.medie << " la " << nouaMedie << endl;
		s.medie = nouaMedie;
	}

	void afiseazaDetaliiStudent(const Student& s)
	{
		cout << "ADMIN -> STUDENT: " << s.nume << ", Varsta: " << s.varsta << ", Medie: " << s.medie << endl;
	}
};

int main()
{
	// Cream 2 obiecte
	Student s1("Mihai", 20, 7.5);
	Student s2("Victor", 21, 10);

	// Afisam informatiile despre obiecte
	s1.afiseazaInformatii();
	s2.afiseazaInformatii();

	// Admin-ul modifica media:
	Admin admin;
	admin.modificaMedie(s2, 5);
	admin.afiseazaDetaliiStudent(s2);

}