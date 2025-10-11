#include <iostream>
using namespace std;

void print_mat(int (*A)[3][3]){
  int *p = (int*)A;
  for(int *i = p; i < p + 9; i += 3){
    for(int *j = i; j < i + 3; j++){
      cout << *j << " ";
    }
    cout << endl;
  }
}

void multi(int (*A)[3][3]){
    int fil = 3;
    int col = 3;
    int tam_cara = fil*col;
    int *p = (int*)A;
    int *q = p + tam_cara;
    int *r = q + tam_cara;
    /* //Multiplicacion elemento a elemento
    for(int *i = p; i < p + tam_cara; i++){
        *(r + (i - p)) = (*i) * *(q + (i - p));
    }*/
    for(int *i=p; i<p+tam_cara; i += col){
        for(int *j = q; j<q + col; j++){
            int suma = 0;
            for(int *k =i; k < i+col;k++){
                suma += (*k) * (*j);
            }
            *r = suma;
            r++;
        }
    }
}

int main(){
    
    int arr[][3][3] = {{{1,2,3},{1,2,3},{1,2,3}},
                       {{2,3,4},{2,3,4},{2,3,4}},
                       {{0,0,0},{0,0,0},{0,0,0}}};
    
    multi(arr);                   
    print_mat(arr+2);
    
    return 0;
}
