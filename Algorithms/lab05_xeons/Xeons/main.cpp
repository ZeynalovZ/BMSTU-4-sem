#include <iostream>
#include <clocale>
#include <cmath>
#include "stream_worker.h"
#include "errors.h"
#include "math_module.h"
using namespace std;


int main()
{
    setlocale(LC_ALL, "ru");
    // Объявим T0 Tw m Tbeg Pbeg
    double T0, Tw, Tbeg, Pbeg;
    double P_result = 0;
    int m;
    const char *filename = "data.txt";
    int code_error = read_data(&Pbeg, &Tbeg, &T0, &Tw, &m, filename);

    if (code_error == OK)
    {
        cout << "T0" << " " << "Tw" << " "  << "m" << " "  << "Tbeg" << " "  << "Pbeg" << " "  << endl;
        cout << T0 << " " << Tw << " "  << m << " "  << Tbeg << " "  << Pbeg << " "  << endl;
        P_result = get_p_result(Pbeg, Tbeg, T0, Tw, m);
        cout << P_result << "result is" << endl;
    }
    else
    {
        switch (code_error) {
        case ERR_READ:
            cout << "Can't read data from file" << endl;
            break;
        case ERR_FILE_OPENING:
            cout << "FILE can't be open" << endl;
        default:
            break;
        }
    }

    return 0;
}
