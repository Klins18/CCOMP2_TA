#include <iostream>
#include <string>
#include <thread>
#include <vector>

using namespace std;

int fil = 10;
int col = 10;

int main() {
    char sopa[fil][col] = {
        { 'X','G','A','T','O','X'},
        { 'Z','A','J','T','B','Z'},
        { 'N','T','O','E','I','U'},
        { 'B','O','C','T','J','P'},
        { 'O','T','A','B','L','M'},
        { 'M','A','O','A','T','T'},
        { 'S','G','G','A','S','O'}};

    string palabra[] = {"GATO"};
    int k = sizeof(palabras) / sizeof(string);

    char* base = *sopa;
    char* end  = base + fil * col;

    cout << "SOPA DE LETRAS:" << endl;
    for (char* fila = base; fila < end; fila += col) {
        for (char* p = fila; p < fila + col; ++p)
            cout << *p << ' ';
        cout << endl;
    }

    cout << "\nPALABRA A BUSCAR:"<< endl;
    for (string* pw = palabras; pw < palabras + k; ++pw)
        cout << "- " << *pw << '\n';

    vector<int> conteos(k, 0);

    auto buscar = [&](string& w, char* start, char* limit, int step) {
        char* p = start;
        for (char ch : w) {
            if (p < base || p >= end || *p != ch) return false;
            p += step;
        }
        return true;
    };


    auto worker = [&](int dir, vector<int>& resultados) {
        for (int idx = 0; idx < k; ++idx) {
            string& w = palabras[idx];
            int count = 0;

            if (dir == 0) { // derecha
                for (char* fila = base; fila < end; fila += col) {
                    char* rowEnd = fila + col;
                    for (char* p = fila; p < rowEnd; ++p)
                        if (buscar(w, p, rowEnd, +1)) ++count;
                }
            }
            else if (dir == 1) { // izquierda
                for (char* fila = base; fila < end; fila += col) {
                    char* rowBegin = fila;
                    for (char* p = fila; p < fila + col; ++p)
                        if (buscar(w, p, rowBegin-1, -1)) ++count;
                }
            }
            else if (dir == 2) { // abajo
                for (char* col = base; col < base + col; ++col) {
                    for (char* p = col; p < end; p += col)
                        if (buscar(w, p, end, COLS)) ++count;
                }
            }
            else if (dir == 3) { // arriba
                for (char* col = base; col < base + col; ++col) {
                    for (char* p = col; p < end; p += col)
                        if (buscar(w, p, base-1, -col)) ++count;
                }
            }

            resultados[idx] += count;
        }
    };


    vector<thread> hilos;
    for (int dir = 0; dir < 4; ++dir)
        hilos.emplace_back(worker, dir, ref(conteos));

    for (thread& t : hilos) t.join();


    cout << "\nRESULTADOS:\n";
    for (int i = 0; i < k; ++i)
        cout << palabras[i] << " aparece " << conteos[i] << " veces.\n";

    return 0;
}
