#include <iostream>
#include <sstream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <cstdio>

using namespace std;

void otworzPlik(string nazwaPliku, fstream *plik, bool tylkoDoOdczytu) {
    if (tylkoDoOdczytu) {
        plik->open(nazwaPliku, ios::in);
    } else {
        plik->open(nazwaPliku, ios::out | ios::trunc);
    }
}

void zamknijPlik(fstream *plik) {
    plik->close();
}

void wyswietlZawartoscPliku(fstream *plik) {
    string linia;

    while(!plik->eof())
    {
        getline(*plik, linia);
        cout << linia << endl;
    }
}

string wczytajLinie(fstream *plik) {
    string linia;

    if (!plik->eof()) {
        getline(*plik, linia);
        return linia;
    }
}

void zapiszLinie(fstream *plik, string linia) {
    if(plik->good() == true)
    {
        *plik << linia << endl;
    }
}

unsigned int generujKlucz(unsigned int klucz) {
    if (klucz < 3) {
        return 1;
    }
    return generujKlucz(klucz - 2) + generujKlucz(klucz - 1);
}

string szyfrujLinie(string linia, unsigned long klucz) {
    char znak;
    int wartoscZnaku, iKlucz;
    string nowaLinia, sKlucz, cKlucz;
    sKlucz = to_string(klucz);

    for (int i = 0; i < linia.length(); i++) {
        znak = linia[i];
        wartoscZnaku = int(znak);
        cKlucz = sKlucz[i % sKlucz.length()];
        istringstream(cKlucz) >> iKlucz;
        wartoscZnaku = wartoscZnaku - iKlucz;
        znak = (char) wartoscZnaku;
        nowaLinia += znak;
    }
    return nowaLinia;
}

string deszyfrujLinie(string linia, unsigned long klucz) {
    char znak;
    int wartoscZnaku, iKlucz;
    string nowaLinia, sKlucz, cKlucz;
    sKlucz = to_string(klucz);

    for (int i = 0; i < linia.length(); i++) {
        znak = linia[i];
        wartoscZnaku = int(znak);
        cKlucz = sKlucz[i % sKlucz.length()];
        istringstream(cKlucz) >> iKlucz;
        wartoscZnaku = wartoscZnaku + iKlucz;
        znak = (char) wartoscZnaku;
        nowaLinia += znak;
    }
    return nowaLinia;
}

void szyfrujPlik(fstream *wPlikWejsciowy, fstream *wPlikWyjsciowy, unsigned long klucz) {
    string linia;

    while (!wPlikWejsciowy->eof()) {
        linia = wczytajLinie(wPlikWejsciowy);
        if (linia == "") {
            break;
        }
        linia = szyfrujLinie(linia, klucz);
        zapiszLinie(wPlikWyjsciowy, linia);
    }
}

void deszyfrujPlik(fstream *wPlikWejsciowy, fstream *wPlikWyjsciowy, unsigned long klucz) {
    string linia;

    while (!wPlikWejsciowy->eof()) {
        linia = wczytajLinie(wPlikWejsciowy);
        if (linia == "") {
            break;
        }
        linia = deszyfrujLinie(linia, klucz);
        zapiszLinie(wPlikWyjsciowy, linia);
    }
}

int main() {
    string nazwaPlikuWejsciowego, nazwaPlikuWyjsciowego;
    fstream plikWejsciowy, plikWyjsciowy;
    unsigned int klucz;
    unsigned int zlozonoscKlucza;
    int operacja;

    fstream *wPlikWejsciowy = &plikWejsciowy;
    fstream *wPlikWyjsciowy = &plikWyjsciowy;
    printf("\033c"); // czyszczenie ekranu

    cout << "Wybierz operację:" << endl;
    cout << "1) Szyfrowanie" << endl;
    cout << "2) Deszyfrowanie" << endl;
    cout << "-> ";
    cin >> operacja;
    printf("\033c");

    cout << "Podaj nazwę pliku do wejściowego:" << endl;
    cin >> nazwaPlikuWejsciowego;
    printf("\033c");

    cout << "Podaj nazwę pliku wyjściowego:" << endl;
    cin >> nazwaPlikuWyjsciowego;
    printf("\033c");

    otworzPlik(nazwaPlikuWejsciowego, wPlikWejsciowy, true);
    otworzPlik(nazwaPlikuWyjsciowego, wPlikWyjsciowy, false);

    cout << "Podaj złożoność klucza:" << endl;
    cin >> zlozonoscKlucza;
    printf("\033c");

    klucz = generujKlucz(zlozonoscKlucza);

    switch (operacja) {
        case 1:
            szyfrujPlik(wPlikWejsciowy, wPlikWyjsciowy, klucz);
            break;
        case 2:
            deszyfrujPlik(wPlikWejsciowy, wPlikWyjsciowy, klucz);
            break;
    }

    cout << "Operacja zakończona pomyślnie" << endl;

    zamknijPlik(wPlikWejsciowy);
    zamknijPlik(wPlikWyjsciowy);

    return 0;
}
