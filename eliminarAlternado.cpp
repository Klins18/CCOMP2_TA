#include <iostream>
using namespace std;

template <typename T>
void imprimirArray(T* inicio, T* fin) {
    for (T* p = inicio; p <= fin; p++) {
        cout << *p << " ";
    }
    cout << endl;
}

template <typename T>
void eliminarAlternado(T* arr, int n) {
    T* inicio = arr;
    T* fin = arr + (n - 1);

    bool eliminarInicio = true;

    while (inicio <= fin) {
        if (eliminarInicio) {
            inicio++;
        } else {
            fin--;
        }
        imprimirArray(inicio, fin);
        eliminarInicio = !eliminarInicio;
    }
}

int main() {
    //int arr[] = {10, 20, 30, 40, 50, 60};
    char arr[] ={ 'a', 'b','c','d','e','f'};
    
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array original:\n";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    
    eliminarAlternado(arr, n);

    return 0;
}
