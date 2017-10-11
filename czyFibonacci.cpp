#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    float n, w;
    float a = 0;
    float b = 1;
    float z;

    cout << "Czy dana liczba jest liczbą Fibonacciego?" << endl;
    cout << "Podaj liczbę: ";
    cin >> n;

    if (n > 0) {
        for (int i = 0; i < 100; ++i) {

            w = a + b;
            a = b;
            b = w;

            if (w == n) {
                cout << "Podana liczba jest liczbą Fibonacciego" << endl;
                break;
            }

            if (w > n) {
                cout << "Twoja liczba nie jest liczba Fibonacciego" << endl;
                break;
            }
        }
    } else {
        cout << "Ciąg Fibonacciego jest rosnący liczba musi być dodatnia" << endl;
    }

    if (w == n) {
        z = b / a;
        cout << "TWOJA ZŁOTA LICZBA TO: " << z << endl;
    }
}