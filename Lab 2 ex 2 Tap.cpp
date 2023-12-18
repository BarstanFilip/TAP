#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Operatiuni {
public:
    virtual float getSumaTotala() = 0;
    virtual float getDobanda() = 0;
    virtual void depunere(float suma) = 0;
    virtual void extragere(float suma) = 0;

    virtual ~Operatiuni() {}
};

class ContBancar : public Operatiuni {
public:
    string numeCont;
    float suma;
    string moneda;

    ContBancar(string numeCont, float suma, string moneda)
        : numeCont(numeCont), suma(suma), moneda(moneda) {}

    ContBancar(const ContBancar& other)
        : numeCont(other.numeCont), suma(other.suma), moneda(other.moneda) {}

    
    float getSumaTotala() override {
        return suma + getDobanda();
    }

    float getDobanda() override {
        if (moneda == "RON") {
            if (suma < 500.0) {
                return suma * 0.003;
            }
            else {
                return suma * 0.008;
            }
        }
        else if (moneda == "EUR") {
            return suma * 0.001;
        }
        return 0.0; 
    }

    void depunere(float suma) override {
        this->suma += suma;
    }

    void extragere(float suma) override {
        if (this->suma >= suma) {
            this->suma -= suma;
        }
        else {
            cout << "Nu exista suficienta suma in cont pentru a efectua extragerea." << std::endl;
        }
    }

    void transfer(ContBancar& contDest, float suma) {
        if (moneda == "RON" && contDest.moneda == "RON") {
            extragere(suma);
            contDest.depunere(suma);
            cout << "Transfer realizat cu succes!" << std::endl;
        }
        else {
            cout << "Transferul poate fi realizat doar între conturi în RON." << std::endl;
        }
    }

    void afisareDateCont() {
        cout << "Cont " << numeCont << " (" << moneda << "): " << endl;
        cout << "  Suma totala: " << getSumaTotala() << " " << moneda << endl;
        cout << "  Dobanda: " << getDobanda() << " " << moneda << endl;
    }
 
};

class ClientInfo {
public:
    string nume;
    string prenume;
    string adresa;
    unsigned nrConturi;
    std::vector<ContBancar> conturi;

    ClientInfo(string nume, string prenume, string adresa, unsigned nrConturi)
        : nume(nume), prenume(prenume), adresa(adresa), nrConturi(nrConturi) {}

    ClientInfo(const ClientInfo& other)
        : nume(other.nume), prenume(other.prenume), adresa(other.adresa), nrConturi(other.nrConturi), conturi(other.conturi) {}

   
    void afisareDateClient() {
        cout << "Client: " << nume << " " << prenume << endl;
        cout << "Adresa: " << adresa << endl;
        cout << "Numar conturi: " << nrConturi << endl;

       
        for (const auto& cont : conturi) {
            cont.afisareDateCont();
        }
    }
};

class Banca {
public:
    vector<ClientInfo> clienti;

    void adaugaClient(ClientInfo& client) {
        clienti.push_back(client);
    }


    void afisareDateBanca() {
        for (const auto& client : clienti) {
            client.afisareDateClient();
        }
    }
};

int main() {

    ContBancar contRON1("ContRON1", 1000.0, "RON");
    ContBancar contEUR1("ContEUR1", 2000.0, "EUR");
    ContBancar contRON2("ContRON2", 500.0, "RON");
    ContBancar contRON3("ContRON3", 1500.0, "RON");

    ClientInfo client1("John", "Doe", "Strada Exemplu", 2);
    client1.conturi.push_back(contRON1);
    client1.conturi.push_back(contEUR1);

    ClientInfo client2("Jane", "Doe", "Strada Exemplu", 2);
    client2.conturi.push_back(contRON2);
    client2.conturi.push_back(contRON3);

    Banca banca;
    banca.adaugaClient(client1);
    banca.adaugaClient(client2);

    contRON1.depunere(200.0);
    contEUR1.extragere(500.0);
    contRON2.transfer(contRON3, 300.0);

    
    banca.afisareDateBanca();

    return 0;
}

