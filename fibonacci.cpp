#include <iostream>

using namespace std;

int main()
{
    int n, w;
    int a = 0;
    int b = 1;

    cout << "Podaj ilość liczb ciągu Fibonacciego jaką chcesz otrzymać: " ;
    cin >> n;

    cout << a << endl << b << endl;

    for (int i = 0; i < n; ++i) {
        w = a + b;
        a = b;
        b = w;

        cout << w << endl;
    }
}