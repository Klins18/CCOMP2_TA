#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Funciones para calcular áreas
float fcuadrado(int* lado) {
    return (*lado) * (*lado);
}

float fcir(int* radio) {
    return M_PI * ((*radio) * (*radio));
}

float frec(int* baseAltura) {
    return baseAltura[0] * baseAltura[1];
}

float ftri(int* baseAltura) {
    return (baseAltura[0] * baseAltura[1])/2;
}

class Ejecuta {
private:
    float (*funcion)(int*);
    int* parametros;
    float (**funciones)(int*);
    string* nombres;
    int cantidad;

public:
    Ejecuta(float (*f)(int*), int* p, float (**arrFuncs)(int*), string* arrNombres, int cant)
        : funcion(f), parametros(p), funciones(arrFuncs), nombres(arrNombres), cantidad(cant) {}

    void operator()() {
        float (**pf)(int*) = funciones;
        string* pn = nombres;
        string nombre = " ";

        // Aritmética de punteros para buscar el nombre de la función
        for (int i = 0; i < cantidad; i++, pf++, pn++) {
            if (funcion == *pf) {
                nombre = *pn;
                break;
            }
        }

        float area = funcion(parametros);
        cout << "Area de " << nombre << " : " << area << endl;
    }
};

int main() {
    // Array de funciones
    float (*funciones[])(int*) = {
        fcuadrado,
        fcir,
        frec,
        ftri
    };

    // Array de nombres
    string nombres[] = {
        "cuadrado",
        "circulo",
        "rectangulo",
        "triangulo"
    };

    int cantidad = sizeof(nombres) / sizeof(nombres[0]);

    // Parámetros individuales
    int lado = 5;
    int radio = 3;
    int rect[] = {4, 7};
    int tri[] = {6, 2};

    // Array de punteros a paraametros
    int* parametros[] = { &lado, &radio, rect, tri };

    Ejecuta f1(fcuadrado, *(parametros + 0), funciones, nombres, cantidad);
    f1();
    Ejecuta f2(fcir,      *(parametros + 1), funciones, nombres, cantidad);
    Ejecuta f3(frec,      *(parametros + 2), funciones, nombres, cantidad);
    Ejecuta f4(ftri,      *(parametros + 3), funciones, nombres, cantidad);

    return 0;
}
