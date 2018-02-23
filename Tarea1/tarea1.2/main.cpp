#include <iostream>
#include <math.h>
#include "calculos.cpp"
using namespace std;



int main() {
    int x, s;
    while (s != 2 && s != 3) {
        cout << "--> Ingrese 2 para seleccionar el problema 2 de la tarea o 3 para seleccionar el calculo de raices: ";
        cin >> s;
    }
    while (x != 1 && x != 2) {
        cout << "--> Ingrese 1 para utilizar precision simple o 2 para precision doble: ";
        cin >> x;
    }
    if (s == 2) {
        if (x == 1) {
            cout << "-->" << "\033[1;32m Precisión Simple \033[0m" << "<--" << '\n' << endl;
            calculos::calcular2<float>();
        } else {
            cout << "-->" << "\033[1;32m Precisión Doble \033[0m" << "<--" << '\n' << endl;
            calculos::calcular2<double>();
        }
    } else {
        if (x == 1) {
            cout << "-->" << "\033[1;32m Precisión Simple \033[0m" << "<--" << '\n' << endl;
           calculos::calcular3<float>();
        } else {
            cout << "-->" << "\033[1;32m Precisión Doble \033[0m" << "<--" << '\n' << endl;
           calculos::calcular3<double>();
        }
    }

    return 0;
}

