#include <iostream>
#include <sstream>
#include <stdio.h>
#include <cmath>
#include <cstring>

using namespace std;

int main()
{
    string liczba;
    cout << "Podaj liczbę: " << endl;
    cin >> liczba;

    int podstawa;
    cout << "Podaj podstawę systemu: " << endl;
    cin >> podstawa;

    int suma = 0;
    int j = 0;

    for(int i = liczba.length() -1; i >= 0; i--){
        int x = liczba[j] - 48;
        suma = suma + (pow(podstawa, i) * x);
        j++;
    }

cout << "Podana liczba w systemie dziesiętnym: " << suma << endl;

}


