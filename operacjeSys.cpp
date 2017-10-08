#include <iostream>
#include <sstream>
#include <stdio.h>
#include <cmath>
#include <cstring>

using namespace std;

string DecToN(int liczba, int podstawa)
{
    string reszta("");

    while(liczba>0){
        reszta.insert(0,to_string(liczba%podstawa));
        liczba = floor(liczba / podstawa);
    }

    return reszta;
}

int NToDec(string liczba, int podstawa)
{
    int suma = 0;
    int j = 0;

    for(int i = liczba.length() -1; i >= 0; i--){
        int x = liczba[j] - 48;
        suma = suma + (pow(podstawa, i) * x);
        j++;
    }

    return suma;
}

int main()
{
    cout << "Wybierz operacje: " << endl;
    cout << "[D]odawanie " << endl;
    cout << "[O]dejmowanie" << endl;
    cout << "[M]nożenie" << endl;
    cout << "D[Z]ielenie" << endl;

    char operacja;
    cout << "Wybierz: " << endl;
    cin >> operacja;

    string liczba1;
    int iliczba1;
    cout << "Podaj pierwszą liczbe: "<< endl;
    cin >> liczba1;

    string liczba2;
    int iliczba2;
    cout << "Podaj drugą liczbe: "<< endl;
    cin >> liczba2;

    int podstawa;
    cout << "Podaj podstawę systemu: "<< endl;
    cin >> podstawa;

    iliczba1 = NToDec(liczba1, podstawa);
    iliczba2 = NToDec(liczba2, podstawa);

    int wynik;
    int reszta = 0;

    switch (operacja) {
        case 'd':
            wynik = iliczba1 + iliczba2;
            break;
        case 'o':
            wynik = iliczba1 - iliczba2;
            break;
        case 'm':
            wynik = iliczba1 * iliczba2;
            break;
        case 'z':
            wynik = floor(iliczba1 / iliczba2);
            reszta = iliczba1 % iliczba2;
            break;
    }

    cout << "Wynik: " << DecToN(wynik, podstawa) << endl;

    if (reszta != 0){
        cout << "Reszta z dzielenia: " << DecToN(reszta, podstawa) << endl;
    }
}