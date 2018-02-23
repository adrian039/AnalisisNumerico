#include <iostream>
#include <math.h>

using namespace std;

template<class T>
void calcular1() {
    int n,resp;
    T x;
    while (resp != 1 && resp != 2) {
        cout
                << "--> Ingrese 1 para asignar valores para n y x. Ingrese 2 para usar el caso de prueba (n=10000000, x=0.00001): ";
        cin>>resp;

    }
    if(resp==1){
        cout << "--> Ingrese un valor para n: ";
        while (!(cin >> n)) {
            cin.clear();
            cin.ignore(99999, '\n');
            cout << "Ingrese un valor para n: ";
        }
        cout << "--> Ingrese un valor para x: ";
        while (!(cin >> x)) {
            cin.clear();
            cin.ignore(99999, '\n');
            cout << "--> Ingrese un valor para x: ";
        }
    }else{
        n=10000000;
        x=0.00001;
    }

    T verd, aprox, err;
    verd = x * n;
    aprox = 0;
    for (int i = 0; i < n; i++) {
        aprox += x;
    }
    cout << "--> Verdadero: " << verd << endl;
    cout << "--> Aproximado: " << aprox << endl;
    err = verd - aprox;
    cout << '\n' << "-->" << "\033[1;32m Error verdadero: " << err << "\033[0m" << " <-- \n" << endl;
}

template<class T>
void calcular2() {
    T a, b, c, x1t, x2t, x1a, x2a, errx1, errx2;
    int resp;
    while (resp != 1 && resp != 2) {
        cout
                << "--> Ingrese 1 para asignar valores para a,b,c. Ingrese 2 para usar el caso de prueba (a=1, b=3000.001, c=3): ";
        cin>>resp;

    }
    if (resp == 1) {
        cout << "--> Ingrese un valor para a: ";
        while (!(cin >> a)) {
            cin.clear();
            cin.ignore(99999, '\n');
            cout << "Ingrese un valor para a: ";
        }
        cout << "--> Ingrese un valor para b: ";
        while (!(cin >> b)) {
            cin.clear();
            cin.ignore(99999, '\n');
            cout << "--> Ingrese un valor para b: ";
        }
        cout << "--> Ingrese un valor para c: ";
        while (!(cin >> c)) {
            cin.clear();
            cin.ignore(99999, '\n');
            cout << "--> Ingrese un valor para c: ";
        }
    } else {
        cout << "-->" << "\033[1;32m Valores Verdaderos Utilizados para x1: -0.001, x2: -3000 \033[0m" << " <--" << endl;
        a = 1;
        b = 3000.001;
        c = 3;
    }

    //Calculo usando Formula Tradicional
    x1t = ((-b) + sqrt((b * b) - (4 * a * c))) / (2 * a);
    x2t = ((-b) - sqrt((b * b) - (4 * a * c))) / (2 * a);

    //Calculo usando Formula Alternativa
    x1a = (-2 * c) / (b + sqrt((b * b) - (4 * a * c)));
    x2a = (-2 * c) / (b - sqrt((b * b) - (4 * a * c)));


    cout << "\n--> Raices con Formula Tradicional: " << endl;
    cout << "--> x1: " << x1t << ",  x2: " << x2t << '\n' << endl;
    if (resp == 2) {

        errx1 = -0.001 - x1t;
        errx2 = -3000 - x2t;

        cout << "-->" << "\033[1;32m Error verdadero para x1: " << errx1 << "\033[0m" << " <--" << endl;
        cout << "-->" << "\033[1;32m Error verdadero para x2: " << errx2 << "\033[0m" << " <--\n" << endl;
    }

    cout << "--> Raices con Formula Alternativa: " << endl;
    cout << "--> x1: " << x1a << ",  x2: " << x2a << '\n' << endl;
    if (resp == 2) {
        errx1 = -0.001 - x1a;
        errx2 = -3000 - x2a;

        cout << "-->" << "\033[1;32m Error verdadero para x1: " << errx1 << "\033[0m" << " <--" << endl;
        cout << "-->" << "\033[1;32m Error verdadero para x2: " << errx2 << "\033[0m" << " <--" << endl;
    }

}

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
            calcular1<float>();
        } else {
            cout << "-->" << "\033[1;32m Precisión Doble \033[0m" << "<--" << '\n' << endl;
            calcular1<double>();
        }
    } else {
        if (x == 1) {
            cout << "-->" << "\033[1;32m Precisión Simple \033[0m" << "<--" << '\n' << endl;
            calcular2<float>();
        } else {
            cout << "-->" << "\033[1;32m Precisión Doble \033[0m" << "<--" << '\n' << endl;
            calcular2<double>();
        }
    }

    return 0;
}

