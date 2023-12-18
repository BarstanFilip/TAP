#include <iostream>
#include <string>
#include <vector>

// Clasa abstractă pentru operațiuni bancare
class Operatiuni {
public:
    virtual float getSumaTotala() = 0;
    virtual float getDobanda() = 0;
    virtual void depunere(float suma) = 0;
    virtual void extragere(float suma) = 0;

    // Destructor virtual pentru a permite utilizarea clasei ca și clasa de bază polimorfică
    virtual ~Operatiuni() {}
};

class ContBancar : public Operatiuni {
public:
    std::string numaCont;
    float suma;
    std::string moneda;

    // Constructori
    ContBancar(std::string numaCont, float suma, std::string moneda)
        : numaCont(numaCont), suma(suma), moneda(moneda) {}

    ContBancar(const ContBancar& other)
        : numaCont(other.numaCont), suma(other.suma), moneda(other.moneda) {}

    // Metodele din clasa abstractă
    float getSumaTotala() override {
        return suma + getDobanda();
    }

    float getDobanda() override {
        if (moneda == "RON") {
            if (suma < 500) {
                return suma * 0.003;
            }
            else {
                return suma * 0.008;
            }
        }
        else if (moneda == "EUR") {
            return suma * 0.001;
        }
        return 0.0; // În cazul altor monede
    }

    void depunere(float suma) override {
        this->suma += suma;
    }

    void extragere(float suma) override {
        if (this->suma >= suma) {
            this->suma -= suma;
        }
        else {
            std::cout << "Nu exista suficienta suma in cont pentru a efectua extragerea." << std::endl;
        }
    }

    // Metoda specifică pentru transfer între conturi în RON
    void transfer(ContBancar& contDest, float suma) {
        if (moneda == "RON" && contDest.moneda == "RON") {
            extragere(suma);
            contDest.depunere(suma);
            std::cout << "Transfer realizat cu succes!" << std::endl;
        }
        else {
            std::cout << "Transferul poate fi realizat doar între conturi în RON." << std::endl;
        }
    }

    // Metoda de afișare a datelor contului
    void afisaredateCont() {
        std::cout << "Cont " << numaCont << " (" << moneda << "): " << std::endl;
        std::cout << "  Suma totala: " << getSumaTotala() << " " << moneda << std::endl;
        std::cout << "  Dobanda: " << getDobanda() << " " << moneda << std::endl;
    }
};

class Clienti {
public:
    std::string nume;
    std::string prenume;
    std::string adresa;
    unsigned nrConturi;
    std::vector<ContBancar> conturi;

    // Constructori
    Clienti(std::string nume, std::string prenume, std::string adresa, unsigned nrConturi)
        : nume(nume), prenume(prenume), adresa(adresa), nrConturi(nrConturi) {}

    Clienti(const Clienti& other)
        : nume(other.nume), prenume(other.prenume), adresa(other.adresa), nrConturi(other.nrConturi), conturi(other.conturi) {}

    // Metoda de afișare a datelor clientului
    void afisaredateClient() {
        std::cout << "Client: " << nume << " " << prenume << std::endl;
        std::cout << "Adresa: " << adresa << std::endl;
        std::cout << "Numar conturi: " << nrConturi << std::endl;

        // Afișarea datelor pentru fiecare cont
        for (const auto& cont : conturi) {
            cont.afisaredateCont();
        }
    }
};

class Banca {
public:
    std::vector<Clienti> clienti;

    // Metoda de adăugare a unui client în bancă
    void adaugaClient(Clienti& client) {
        clienti.push_back(client);
    }

    // Metoda de afișare a datelor băncii
    void afisaredateBanca() {
        for (const auto& client : clienti) {
            client.afisaredateClient();
        }
    }
};

int main() {
    // Creare obiecte
    ContBancar contRON1("ContRON1", 1000.0, "RON");
    ContBancar contEUR1("ContEUR1", 2000.0, "EUR");
    ContBancar contRON2("ContRON2", 500.0, "RON");
    ContBancar contRON3("ContRON3", 1500.0, "RON");

    Clienti client1("John", "Doe", "Strada Exemplu", 2);
    client1.conturi.push_back(contRON1);
    client1.conturi.push_back(contEUR1);

    Clienti client2("Jane", "Doe", "Strada Exemplu", 2);
    client2.conturi.push_back(contRON2);
    client2.conturi.push_back(contRON3);

    Banca banca;
    banca.adaugaClient(client1);
    banca.adaugaClient(client2);

    // Operațiuni pe conturi
    contRON1.depunere(200.0);
    contEUR1.extragere(500.0);
    contRON2.transfer(contRON3, 300.0);

    // Afișare date bancă
    banca.afisaredateBanca();

    return 0;
}
