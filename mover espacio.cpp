#include <iostream>
using namespace std;

void imprime_mat(int **mat, int fil, int col){
    int **p = mat;
    while(p< mat + fil){
      int *q = *p;
      while(q<*p+col){
        cout << *q << " ";
        q++;
      }
      cout << endl;
      p++;
    }
  }

void agregar_valores(int **mat, int fil, int col, int valores[][3]){
    for (int i = 0; i < fil; ++i) {
        for (int j = 0; j < col; ++j) {
            *(*(mat + i) + j) = *(*(valores + i) + j);
        }
    }
}

void intercambiar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void mover_cero(int **mat, int fil, int col, int fila, int columna) {
    char movimiento;
    
    while (movimiento != 'x') {
        imprime_mat(mat, fil, col);
        cout << "mueve el 0 (w = arriba, s = abajo, a = izquierda, d = derecha, x = salir): ";
        cin >> movimiento;

        int nuevaFila = fila;
        int nuevaColumna = columna;

        switch (movimiento) {
            case 'w':
                nuevaFila--;
                break;
            case 's':
                nuevaFila++;
                break;
            case 'a':
                nuevaColumna--;
                break;
            case 'd':
                nuevaColumna++;
                break;
            case 'x':
                cout << "chau!" << endl;
                return;
            default:
                cout << "movimiento invalido!" << endl;
                continue;
        }
        if (nuevaFila >= 0 && nuevaFila < fil && nuevaColumna >= 0 && nuevaColumna < col) {
            int temp = *(*(mat + nuevaFila) + nuevaColumna);
            *(*(mat + nuevaFila) + nuevaColumna) = *(*(mat + fila) + columna);
            *(*(mat + fila) + columna) = temp;

            // actualizamos posicion del 0
            fila = nuevaFila;
            columna = nuevaColumna;
        } else {
            cout << "no se puede mover a esa direccion, intente de nuevo" << endl;
        }
    }
}    

int main (){
    int **mat = new int*[3];
    for (int i = 0; i < 3; ++i) {
        mat[i] = new int[3];
    }

    int valores[3][3] ={{1, 8, 3},
                        {2, 5, 6},
                        {4, 7, 0}};
                        
    agregar_valores(mat,3,3,valores);
    imprime_mat(mat,3,3);
    
    mover_cero(mat,3,3,2,2);
    for (int i = 0; i < 3; ++i) {
    delete[] mat[i];
    }
    delete[] mat;
   return 0; 
}