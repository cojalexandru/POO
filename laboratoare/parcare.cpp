#include <iostream>
#include <string>

using namespace std;

// Clasa de baza pentru locurile de parcare
class LocParcare {
protected:
    // Adaugam clasa prietena 'Parcare' pentru a permite parcarii sa acceseze direct atributele protejate din LocParcare
    friend class Parcare;
    string nrInmatriculare;
    int oraIntrare;
    int minutIntrare;
    int oraIesire;
    int minutIesire;
    bool ocupat;

public:
    LocParcare(string nrInmatriculare = "", int oraIntrare = 0, int minutIntrare = 0) {
        this->nrInmatriculare = nrInmatriculare;
        this->oraIntrare = oraIntrare;
        this->minutIntrare = minutIntrare;
        this->oraIesire = 0;
        this->minutIesire = 0;
        this->ocupat = !nrInmatriculare.empty();
    }

	~LocParcare() {}

    void elibereazaLoc(int oraIesire, int minutIesire) {
        this->oraIesire = oraIesire;
        this->minutIesire = minutIesire;
        this->ocupat = false;
    }

    void afisareDetalii() const {
        cout << "Nr. inmatriculare: " << nrInmatriculare;
        cout << ", Ora intrare: " << oraIntrare << ":" << minutIntrare;
        cout << ", Ocupat: " << (ocupat ? "Da" : "Nu");
    }
};

// Clasa derivata de la "LocParcare" pentru locuri de parcare VIP, ce au un tarif mai mare
class LocVIP : public LocParcare {
    friend class Parcare;
    float tarifSuplimentar;

public:
    LocVIP(string nrInmatriculare = "", int oraIntrare = 0, int minutIntrare = 0, float tarifSuplimentar = 10.0)
        : LocParcare(nrInmatriculare, oraIntrare, minutIntrare) {
        this->tarifSuplimentar = tarifSuplimentar;
    }

    void afisareInformatii() const {
        afisareDetalii();
        cout << ", Tarif suplimentar: " << tarifSuplimentar << " lei" << endl;
    }
};

// Clasa parcare
class Parcare {
private:
    LocParcare* locuriNormal;
    LocVIP* locuriVIP;
    int numarLocuriNormal;
    int numarLocuriVIP;
    float tarifOra;
    float tarifSuplimentarVIP;

public:
    // Constructor unde initializam tablourile pentru locurile normale si locurile VIP
    Parcare(int numarLocuriNormal, int numarLocuriVIP, float tarifOra, float tarifSuplimentarVIP)
        : numarLocuriNormal(numarLocuriNormal), numarLocuriVIP(numarLocuriVIP),
        tarifOra(tarifOra), tarifSuplimentarVIP(tarifSuplimentarVIP) {
        locuriNormal = new LocParcare[numarLocuriNormal];
        locuriVIP = new LocVIP[numarLocuriVIP];
    }

    // Destructor
    ~Parcare() {
        delete[] locuriNormal;
        delete[] locuriVIP;
    }

    // Functie pentru a afisa locurile
    void afiseazaLocuri() const {
        // Afisam prima data locurile normale, daca locul normal nu este ocupat scriem doar "Liber", altfel folosim functia de afisareDetalii
        cout << "Locuri Normale:\n";
        for (int i = 0; i < numarLocuriNormal; ++i) {
            cout << "Loc " << i << ": ";
            if (locuriNormal[i].ocupat) {
                locuriNormal[i].afisareDetalii();
                cout << endl;
            }
            else {
                cout << "Liber" << endl;
            }
        }
        // Dupa afisam locurile VIP, si analog ca la locurile normale
        cout << "\nLocuri VIP:\n";
        for (int i = 0; i < numarLocuriVIP; ++i) {
            cout << "Loc VIP " << i << ": ";
            if (locuriVIP[i].ocupat) {
                locuriVIP[i].afisareInformatii();
            }
            else {
                cout << "Liber" << endl;
            }
        }
    }

    // Functia pentru a ocupa un loc, returneaza un bool pentru a sti daca locul a fost ocupat cu succes sau nu
    bool ocupaLoc(bool esteVIP, int numarLoc, string nrInmatriculare, int oraIntrare, int minutIntrare) {
        if (esteVIP) {
            if (numarLoc < 0 || numarLoc >= numarLocuriVIP) {
                cout << "Numarul locului VIP invalid!" << endl;
                return false;
            }
            if (locuriVIP[numarLoc].ocupat) {
                cout << "Locul VIP este deja ocupat!" << endl;
                return false;
            }
            locuriVIP[numarLoc] = LocVIP(nrInmatriculare, oraIntrare, minutIntrare, tarifSuplimentarVIP);
            cout << "Locul VIP " << numarLoc << " a fost ocupat cu masina " << nrInmatriculare << endl;
        }
        else {
            if (numarLoc < 0 || numarLoc >= numarLocuriNormal) {
                cout << "Numarul locului normal invalid!" << endl;
                return false;
            }
            if (locuriNormal[numarLoc].ocupat) {
                cout << "Locul normal este deja ocupat!" << endl;
                return false;
            }
            locuriNormal[numarLoc] = LocParcare(nrInmatriculare, oraIntrare, minutIntrare);
            cout << "Locul normal " << numarLoc << " a fost ocupat cu masina " << nrInmatriculare << endl;
        }
        return true;
    }

    // Functia pentru eliberarea unui loc, returneaza tariful ce trebuie platit de sofer
    float elibereazaLoc(bool esteVIP, int numarLoc, int oraIesire, int minutIesire) {
        if (esteVIP) {
            if (numarLoc < 0 || numarLoc >= numarLocuriVIP || !locuriVIP[numarLoc].ocupat) {
                cout << "Locul VIP invalid sau liber!" << endl;
                return -1;
            }
            int minuteIntrare = locuriVIP[numarLoc].oraIntrare * 60 + locuriVIP[numarLoc].minutIntrare;
            int minuteIesire = oraIesire * 60 + minutIesire;
            int durataMinute = minuteIesire - minuteIntrare;

            if (durataMinute <= 0) {
                cout << "Ora iesirii este inainte de ora intrarii!" << endl;
                return -1;
            }

            float durataOre = durataMinute / 60.0f;
            float tarif = durataOre * tarifOra + locuriVIP[numarLoc].tarifSuplimentar;

            locuriVIP[numarLoc].elibereazaLoc(oraIesire, minutIesire);
            cout << "Locul VIP " << numarLoc << " a fost eliberat" << endl;
            return tarif;
        }
        else {
            if (numarLoc < 0 || numarLoc >= numarLocuriNormal || !locuriNormal[numarLoc].ocupat) {
                cout << "Locul normal invalid sau liber!" << endl;
                return -1;
            }
            int minuteIntrare = locuriNormal[numarLoc].oraIntrare * 60 + locuriNormal[numarLoc].minutIntrare;
            int minuteIesire = oraIesire * 60 + minutIesire;
            int durataMinute = minuteIesire - minuteIntrare;

            if (durataMinute <= 0) {
                cout << "Ora iesirii este inainte de ora intrarii!" << endl;
                return -1;
            }

            float durataOre = durataMinute / 60.0;
            float tarif = durataOre * tarifOra;

            locuriNormal[numarLoc].elibereazaLoc(oraIesire, minutIesire);
            cout << "Locul normal " << numarLoc << " a fost eliberat" << endl;
            return tarif;
        }
    }
};

int main() {
    // Luam datele de la utilizator
    int numarLocuriNormal, numarLocuriVIP;
    float tarifOra, tarifSuplimentarVIP;

    cout << "Introduceti numarul de locuri normale: ";
    cin >> numarLocuriNormal;
    cout << "Introduceti numarul de locuri VIP: ";
    cin >> numarLocuriVIP;
    cout << "Introduceti tariful pe ora (lei): ";
    cin >> tarifOra;
    cout << "Introduceti tariful suplimentar VIP (lei): ";
    cin >> tarifSuplimentarVIP;

    // Cream parcarea cu datele introduse de utilizator
    Parcare parcare(numarLocuriNormal, numarLocuriVIP, tarifOra, tarifSuplimentarVIP);

    int optiune;
    do {
        cout << "\nMeniu Gestionare Parcare:\n";
        cout << "1. Afiseaza locurile\n";
        cout << "2. Ocupa un loc\n";
        cout << "3. Elibereaza un loc\n";
        cout << "0. Iesire\n";
        cout << "Optiunea dvs: ";
        cin >> optiune;

        switch (optiune) {
        case 1:
            parcare.afiseazaLocuri();
            break;
        case 2: {
            int numarLoc, ora, minut;
            string nrAuto;
            char esteVIP;

            cout << "Numar loc: ";
            cin >> numarLoc;
            cout << "Numar auto: ";
            cin >> nrAuto;
            cout << "Ora intrare (0-23): ";
            cin >> ora;
            cout << "Minut intrare (0-59): ";
            cin >> minut;
            cout << "VIP? (d/n): ";
            cin >> esteVIP;

            if (ora < 0 || ora > 23 || minut < 0 || minut > 59) {
                cout << "Timp invalid!" << endl;
                break;
            }

            parcare.ocupaLoc((esteVIP == 'd' || esteVIP == 'D'), numarLoc, nrAuto, ora, minut);
            break;
        }
        case 3: {
            int numarLoc, ora, minut;
            char esteVIP;

            cout << "Numar loc: ";
            cin >> numarLoc;
            cout << "VIP? (d/n): ";
            cin >> esteVIP;
            cout << "Ora iesire (0-23): ";
            cin >> ora;
            cout << "Minut iesire (0-59): ";
            cin >> minut;

            if (ora < 0 || ora > 23 || minut < 0 || minut > 59) {
                cout << "Timp invalid!" << endl;
                break;
            }

            float cost = parcare.elibereazaLoc((esteVIP == 'd' || esteVIP == 'D'), numarLoc, ora, minut);
            if (cost >= 0) {
                cout << "Total de plata: " << cost << " lei" << endl;
            }
            break;
        }
        case 0:
            cout << "La revedere!" << endl;
            break;
        default:
            cout << "Optiune invalida!" << endl;
        }
    } while (optiune != 0);
}