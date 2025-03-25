#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Animal
{
protected:
    string prolecla;
    int numar_cusca;
    int varsta;

public:
    Animal(string prolecla, int numar_cusca, int varsta)
    {
        this->prolecla = prolecla;
        this->numar_cusca = numar_cusca;
        this->varsta = varsta;
    }

	void afisare_detalii() const
    {
        cout << "Prolecla: " << prolecla << ", Numar cusca: " << numar_cusca << ", Varsta: " << varsta;
    }
};

class Pasare : public Animal
{
    float lungime_aripi;
    int durata_viata;

public:
    Pasare(string prolecla, int numar_cusca, int varsta, float lungime_aripi, int durata_viata) :
        Animal(prolecla, numar_cusca, varsta),
        lungime_aripi(lungime_aripi),
        durata_viata(durata_viata) {
    }

    void introducere_date()
    {
        cout << "Introduceti datele pasarii:\n";
        cout << "Prolecla: ";
        cin >> prolecla;
        cout << "Numar cusca: ";
        cin >> numar_cusca;
        cout << "Varsta: ";
        cin >> varsta;
        cout << "Lungimea aripilor: ";
        cin >> lungime_aripi;
        cout << "Durata de viata: ";
        cin >> durata_viata;
    }

    void afiseaza_informatii()
    {
        afisare_detalii();
        cout << ", Lungimea aripilor: " << lungime_aripi << ", Durata de viata: " << durata_viata << " ani" << endl;
    }
};

class Caine : public Animal
{
    string rasa;
    bool este_dresabil;

public:
    Caine(string prolecla, int numar_cusca, int varsta, string rasa, bool este_dresabil) :
        Animal(prolecla, numar_cusca, varsta),
        rasa(rasa),
        este_dresabil(este_dresabil) {
    }

    void introducere_date()
    {
        cout << "Introduceti datele cainelui:\n";
        cout << "Prolecla: ";
        cin >> prolecla;
        cout << "Numar cusca: ";
        cin >> numar_cusca;
        cout << "Varsta: ";
        cin >> varsta;
        cout << "Rasa: ";
        cin >> rasa;
        cout << "Este dresabil? (1-Da, 0-Nu): ";
        cin >> este_dresabil;
    }

    void afiseaza_informatii()
    {
        afisare_detalii();
        cout << ", Rasa: " << rasa << ", Dresabil: " << (este_dresabil ? "Da" : "Nu") << endl;
    }
};

class Primata : public Animal
{
    string specie;
    bool este_sociala;

public:
    Primata(string prolecla, int numar_cusca, int varsta, string specie, bool este_sociala) :
        Animal(prolecla, numar_cusca, varsta),
        specie(specie),
        este_sociala(este_sociala) {
    }

    void introducere_date()
    {
        cout << "Introduceti datele primatei:\n";
        cout << "Prolecla: ";
        cin >> prolecla;
        cout << "Numar cusca: ";
        cin >> numar_cusca;
        cout << "Varsta: ";
        cin >> varsta;
        cout << "Specie: ";
        cin >> specie;
        cout << "Este sociala? (1-Da, 0-Nu): ";
        cin >> este_sociala;
    }

    void afiseaza_informatii()
    {
        afisare_detalii();
        cout << ", Specie: " << specie << ", sociala: " << (este_sociala ? "Da" : "Nu") << endl;
    }
};

class Antilopa : public Animal
{
    float viteza_alergare;
    string habitat;

public:
    Antilopa(string prolecla, int numar_cusca, int varsta, float viteza_alergare, string habitat) :
        Animal(prolecla, numar_cusca, varsta),
        viteza_alergare(viteza_alergare),
        habitat(habitat) {
    }

    void introducere_date()
    {
        cout << "Introduceti datele antilopei:\n";
        cout << "Prolecla: ";
        cin >> prolecla;
        cout << "Numar cusca: ";
        cin >> numar_cusca;
        cout << "Varsta: ";
        cin >> varsta;
        cout << "Viteza de alergare: ";
        cin >> viteza_alergare;
        cout << "Habitat: ";
        cin >> habitat;
    }

    void afiseaza_informatii()
    {
        afisare_detalii();
        cout << ", Viteza de alergare: " << viteza_alergare << " km/h, Habitat: " << habitat << endl;
    }
};

class Felina : public Animal
{
    string specie;

public:
    Felina(string prolecla, int numar_cusca, int varsta, string specie) :
        Animal(prolecla, numar_cusca, varsta),
        specie(specie) {
    }

    void introducere_date()
    {
        cout << "Introduceti datele felinei:\n";
        cout << "Prolecla: ";
        cin >> prolecla;
        cout << "Numar cusca: ";
        cin >> numar_cusca;
        cout << "Varsta: ";
        cin >> varsta;
        cout << "Specie felina: ";
        cin >> specie;
    }

    void afiseaza_informatii()
    {
        afisare_detalii();
        cout << ", Specie: " << specie << endl;
    }
};

int main()
{
    vector<Pasare*> pasari;
    vector<Caine*> caini;
    vector<Primata*> primate;
    vector<Antilopa*> antilope;
    vector<Felina*> feline;

    int optiune_zoo, optiune_submeniu;

    do {
        cout << "\nMeniu Gestionare Zoo:\n";
        cout << "1. Gestionare Pasari\n";
        cout << "2. Gestionare Caini\n";
        cout << "3. Gestionare Primate\n";
        cout << "4. Gestionare Antilope\n";
        cout << "5. Gestionare Feline\n";
        cout << "0. Iesire\n";
        cout << "Optiunea dvs: ";
        cin >> optiune_zoo;

        switch (optiune_zoo) {
        case 1:
        {
            do {
                cout << "\nMeniu Gestionare Pasari:\n";
                cout << "1. Adauga pasare\n";
                cout << "2. Afiseaza pasari\n";
                cout << "3. Sterge pasare dupa ID\n";
                cout << "4. Elibereaza memoria ocupata de pasari\n";
                cout << "0. Inapoi\n";
                cout << "Optiunea dvs: ";
                cin >> optiune_submeniu;

                switch (optiune_submeniu) {
                case 1:
                {
                    Pasare* noua_pasare = new Pasare("", 0, 0, 0, 0);
                    noua_pasare->introducere_date();
                    pasari.push_back(noua_pasare);
                    break;
                }
                case 2:
                {
                    if (pasari.empty()) {
                        cout << "Nu exista pasari inregistrate!" << endl;
                    }
                    else {
                        for (size_t i = 0; i < pasari.size(); i++) {
                            cout << "Pasarea (ID: " << i << ") : ";
                            pasari[i]->afiseaza_informatii();
                        }
                    }
                    break;
                }
                case 3:
                {
                    if (pasari.empty()) {
                        cout << "Nu exista pasari inregistrate!" << endl;
                    }
                    else {
                        int id_stergere;
                        cout << "Introduceti ID-ul pasarii de sters: ";
                        cin >> id_stergere;

                        if (id_stergere >= 0 && id_stergere < pasari.size()) {
                            delete pasari[id_stergere];
                            pasari.erase(pasari.begin() + id_stergere);
                            cout << "Pasarea cu ID-ul " << id_stergere << " a fost stearsa!" << endl;
                        }
                        else {
                            cout << "ID invalid!" << endl;
                        }
                    }
                    break;
                }
                case 4:
                {
                    for (Pasare* pasare : pasari) {
                        delete pasare;
                    }
                    pasari.clear();
                    cout << "Memoria ocupata de pasari a fost eliberata!" << endl;
                    break;
                }
                }
            } while (optiune_submeniu != 0);
            break;
        }
        case 2:
        {
            do {
                cout << "\nMeniu Gestionare Caini:\n";
                cout << "1. Adauga caine\n";
                cout << "2. Afiseaza caini\n";
                cout << "3. Sterge caine dupa ID\n";
                cout << "4. Elibereaza memoria ocupata de caini\n";
                cout << "0. Inapoi\n";
                cout << "Optiunea dvs: ";
                cin >> optiune_submeniu;

                switch (optiune_submeniu) {
                case 1:
                {
                    Caine* nou_caine = new Caine("", 0, 0, "", false);
                    nou_caine->introducere_date();
                    caini.push_back(nou_caine);
                    break;
                }
                case 2:
                {
                    if (caini.empty()) {
                        cout << "Nu exista caini inregistrati!" << endl;
                    }
                    else {
                        for (size_t i = 0; i < caini.size(); i++) {
                            cout << "Cainele (ID: " << i << ") : ";
                            caini[i]->afiseaza_informatii();
                        }
                    }
                    break;
                }
                case 3:
                {
                    if (caini.empty()) {
                        cout << "Nu exista caini inregistrati!" << endl;
                    }
                    else {
                        int id_stergere;
                        cout << "Introduceti ID-ul cainelui de sters: ";
                        cin >> id_stergere;

                        if (id_stergere >= 0 && id_stergere < caini.size()) {
                            delete caini[id_stergere];
                            caini.erase(caini.begin() + id_stergere);
                            cout << "Cainele cu ID-ul " << id_stergere << " a fost sters!" << endl;
                        }
                        else {
                            cout << "ID invalid!" << endl;
                        }
                    }
                    break;
                }
                case 4:
                {
                    for (Caine* caine : caini) {
                        delete caine;
                    }
                    caini.clear();
                    cout << "Memoria ocupata de caini a fost eliberata!" << endl;
                    break;
                }
                }
            } while (optiune_submeniu != 0);
            break;
        }
        case 3:
        {
            do {
                cout << "\nMeniu Gestionare Primate:\n";
                cout << "1. Adauga primata\n";
                cout << "2. Afiseaza primate\n";
                cout << "3. Sterge primata dupa ID\n";
                cout << "4. Elibereaza memoria ocupata de primate\n";
                cout << "0. Inapoi\n";
                cout << "Optiunea dvs: ";
                cin >> optiune_submeniu;

                switch (optiune_submeniu) {
                case 1:
                {
                    Primata* nou_primata = new Primata("", 0, 0, "", false);
                    nou_primata->introducere_date();
                    primate.push_back(nou_primata);
                    break;
                }
                case 2:
                {
                    if (primate.empty()) {
                        cout << "Nu exista primate inregistrate!" << endl;
                    }
                    else {
                        for (size_t i = 0; i < primate.size(); i++) {
                            cout << "Primata (ID: " << i << ") : ";
                            primate[i]->afiseaza_informatii();
                        }
                    }
                    break;
                }
                case 3:
                {
                    if (primate.empty()) {
                        cout << "Nu exista primate inregistrate!" << endl;
                    }
                    else {
                        int id_stergere;
                        cout << "Introduceti ID-ul primatei de sters: ";
                        cin >> id_stergere;

                        if (id_stergere >= 0 && id_stergere < primate.size()) {
                            delete primate[id_stergere];
                            primate.erase(primate.begin() + id_stergere);
                            cout << "Primata cu ID-ul " << id_stergere << " a fost stearsa!" << endl;
                        }
                        else {
                            cout << "ID invalid!" << endl;
                        }
                    }
                    break;
                }
                case 4:
                {
                    for (Primata* primata : primate) {
                        delete primata;
                    }
                    primate.clear();
                    cout << "Memoria ocupata de primate a fost eliberata!" << endl;
                    break;
                }
                }
            } while (optiune_submeniu != 0);
            break;
        }
        case 4:
        {
            do {
                cout << "\nMeniu Gestionare Antilope:\n";
                cout << "1. Adauga antilopa\n";
                cout << "2. Afiseaza antilope\n";
                cout << "3. Sterge antilopa dupa ID\n";
                cout << "4. Elibereaza memoria ocupata de antilope\n";
                cout << "0. Inapoi\n";
                cout << "Optiunea dvs: ";
                cin >> optiune_submeniu;

                switch (optiune_submeniu) {
                case 1:
                {
                    Antilopa* noua_antilopa = new Antilopa("", 0, 0, 0, "");
                    noua_antilopa->introducere_date();
                    antilope.push_back(noua_antilopa);
                    break;
                }
                case 2:
                {
                    if (antilope.empty()) {
                        cout << "Nu exista antilope inregistrate!" << endl;
                    }
                    else {
                        for (size_t i = 0; i < antilope.size(); i++) {
                            cout << "Antilopa (ID: " << i << ") : ";
                            antilope[i]->afiseaza_informatii();
                        }
                    }
                    break;
                }
                case 3:
                {
                    if (antilope.empty()) {
                        cout << "Nu exista antilope inregistrate!" << endl;
                    }
                    else {
                        int id_stergere;
                        cout << "Introduceti ID-ul antilopei de sters: ";
                        cin >> id_stergere;

                        if (id_stergere >= 0 && id_stergere < antilope.size()) {
                            delete antilope[id_stergere];
                            antilope.erase(antilope.begin() + id_stergere);
                            cout << "Antilopa cu ID-ul " << id_stergere << " a fost stearsa!" << endl;
                        }
                        else {
                            cout << "ID invalid!" << endl;
                        }
                    }
                    break;
                }
                case 4:
                {
                    for (Antilopa* antilopa : antilope) {
                        delete antilopa;
                    }
                    antilope.clear();
                    cout << "Memoria ocupata de antilope a fost eliberata!" << endl;
                    break;
                }
                }
            } while (optiune_submeniu != 0);
            break;
        }
        case 5:
        {
            do {
                cout << "\nMeniu Gestionare Feline:\n";
                cout << "1. Adauga felina\n";
                cout << "2. Afiseaza feline\n";
                cout << "3. Sterge felina dupa ID\n";
                cout << "4. Elibereaza memoria ocupata de feline\n";
                cout << "0. Inapoi\n";
                cout << "Optiunea dvs: ";
                cin >> optiune_submeniu;

                switch (optiune_submeniu) {
                case 1:
                {
                    Felina* noua_felina = new Felina("", 0, 0, "");
                    noua_felina->introducere_date();
                    feline.push_back(noua_felina);
                    break;
                }
                case 2:
                {
                    if (feline.empty()) {
                        cout << "Nu exista feline inregistrate!" << endl;
                    }
                    else {
                        for (size_t i = 0; i < feline.size(); i++) {
                            cout << "Felina (ID: " << i << ") : ";
                            feline[i]->afiseaza_informatii();
                        }
                    }
                    break;
                }
                case 3:
                {
                    if (feline.empty()) {
                        cout << "Nu exista feline inregistrate!" << endl;
                    }
                    else {
                        int id_stergere;
                        cout << "Introduceti ID-ul felinei de sters: ";
                        cin >> id_stergere;

                        if (id_stergere >= 0 && id_stergere < feline.size()) {
                            delete feline[id_stergere];
                            feline.erase(feline.begin() + id_stergere);
                            cout << "Felina cu ID-ul " << id_stergere << " a fost stearsa!" << endl;
                        }
                        else {
                            cout << "ID invalid!" << endl;
                        }
                    }
                    break;
                }
                case 4:
                {
                    for (Felina* felina : feline) {
                        delete felina;
                    }
                    feline.clear();
                    cout << "Memoria ocupata de feline a fost eliberata!" << endl;
                    break;
                }
                }
            } while (optiune_submeniu != 0);
            break;
        }
        }
    } while (optiune_zoo != 0);
    return 0;
}