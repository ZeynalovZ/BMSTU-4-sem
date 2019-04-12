#include <iostream>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    // Объявим T0 Tw m Tbeg Pbeg
    double T0, Tw, m, Tbeg, Pbeg;
    cout << "Input T0:" << endl;
    cin >> T0;

    cout << "Input Tw:" << endl;
    cin >> Tw;

    cout << "Input m:" << endl;
    cin >> m;

    cout << "Input Tbeg:" << endl;
    cin >> Tbeg;

    cout << "Input Pbeg:" << endl;
    cin >> Pbeg;

    cout << T0 << " " << Tw << " "  << m << " "  << Tbeg << " "  << Pbeg << " "  << endl;
    return 0;
}
