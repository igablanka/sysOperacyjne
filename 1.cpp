#include <iostream>
#include <sstream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
    int liczba;
    cout << "Podaj liczbe: "<< endl;
    cin >> liczba;

    int podstawa;
    cout << "Podaj podstawę systemu: " << endl;
    cin >> podstawa;

    string reszta("");

    while(liczba>0){
        reszta.insert(0,to_string(liczba%podstawa));
        liczba = floor(liczba / podstawa);
    }

    cout << reszta << endl;
}
