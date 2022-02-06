#include <iostream>

// Parent klasa iz koje svoje atribute uzimaju i KancelarijskiRadnik kao i Menadzer
class Zaposleni {

public:
    double plata;
    double getPlata() {
        return this->plata;
    }

    // Virtual Void je funkcija koja se pravi ako funkcije u "child"
    // klasama koje imaju isto ime kao i funkcija u "parent" klasi
    // treba da vracaju razliciti rezultat

    virtual void izracunajPlatu(int brojSati) {

        // Znaci kada bi uzeli klasu zaposleni, onda bi u donjem primeru 10 * 5 bilo 50
        this->plata = 10 * brojSati;
    }
};

class KancelarijskiRadnik : public Zaposleni {
    virtual void izracunajPlatu(int brojSati) {
        // Ali ovde overridujemo tu funkciju i kazemo da taj rezultat u stvari treba da se pomnozi sa 20 znaci 20*5 = 100
        this->plata = 20 * brojSati;
    }
};


class Menadzer : public Zaposleni {

    // Isto tako je i ovde 30 * 5 = 150
    void izracunajPlatu(int brojSati) {
        this->plata = 30 * brojSati;
    }
};

using namespace std;
int main() {

    // Sada pravimo "instance" ovih dveju klasa
    KancelarijskiRadnik kancelarijskiRadnik;
    Menadzer menadzer;

    // I da bi dokazali vrednost virtual voida prvo pointer klase kancelarijskiRadnik, dodeljujemo klasi zaposleni
    Zaposleni* zaposleni = &kancelarijskiRadnik;

    zaposleni->izracunajPlatu(5);

    // Racunamo platu i stampamo rezultat
    cout << zaposleni->getPlata() << endl;

    // Onda istu tu klasu dodeljujemo menadzer
    zaposleni = &menadzer;

    zaposleni->izracunajPlatu(5);

    // Racunamo platu i dodeljujemo rezultat
    cout << zaposleni->getPlata() << endl;

}
