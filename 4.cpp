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
    cout << "KALKULATOR na systemach liczbowych " << endl;

    string liczba1;
    int iliczba1;
    cout << "Podaj pierwszą liczbe: "<< endl;
    cin >> liczba1;

    int podstawa1;
    cout << "Podaj podstawę systemu pierwszej liczby: "<< endl;
    cin >> podstawa1;

    string liczba2;
    int iliczba2;
    cout << "Podaj drugą liczbe: "<< endl;
    cin >> liczba2;

    int podstawa2;
    cout << "Podaj podstawę systemu drugiej liczby : "<< endl;
    cin >> podstawa2;

    int podstawaWyniku;
    cout << "Podaj podstawę systemu w której chcesz otrzymać wynik: "<< endl;
    cin >> podstawaWyniku;

    iliczba1 = NToDec(liczba1, podstawa1);
    iliczba2 = NToDec(liczba2, podstawa2);

    int wynikD, wynikO, wynikM, wynikZ;
    int reszta = 0;


        wynikD = iliczba1 + iliczba2;

        wynikO = iliczba1 - iliczba2;

        wynikM = iliczba1 * iliczba2;

        wynikZ = floor(iliczba1 / iliczba2);
        reszta = iliczba1 % iliczba2;



    cout << "Wynik w systemie " << podstawaWyniku  << endl;

    cout << "Dodawanie: "<< DecToN(wynikD, podstawaWyniku) << endl;
    cout << "Odejmowanie: "<< DecToN(wynikO, podstawaWyniku);

    if (wynikO == 0){
        cout << "0";
    }

    cout << endl;

    cout << "Mnożenie: "<< DecToN(wynikM, podstawaWyniku) << endl;
    cout << "Dzielenie: "<< DecToN(wynikZ, podstawaWyniku) << endl;

    if (reszta != 0){
        cout << "Reszta z dzielenia: " << DecToN(reszta, podstawaWyniku) << endl;
    }
}