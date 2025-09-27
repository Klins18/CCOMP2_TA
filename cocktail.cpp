#include <iostream>
using namespace std;

void cocktail_sort(int *p, int *q) {
    bool hubo_cambio = true;
    while (hubo_cambio && p < q) {
        hubo_cambio = false;
  
        for (int *k = p; k < q; k++) { // burbuja hacia la derecha
            if (*k > *(k + 1)) {
                int temp = *k;
                *k = *(k + 1);
                *(k + 1) = temp;
                hubo_cambio = true;
            }
        }
        q--;
        
        if (!hubo_cambio) break;
        hubo_cambio = false;
      
        for (int *k = q; k > p; k--) {  // burbuja hacia la izquierda
            if (*(k - 1) > *k) {
                int temp = *k;
                *k = *(k - 1);
                *(k - 1) = temp;
                hubo_cambio = true;
            }
        }
        p++;
    }
}

int main() {
    int a[10] = {2,8,26,30,42,3,7,21,35,70};
    int *p = a;
    int *q = a + 9;
    
    cocktail_sort(p, q);
    
    for (int *r = a; r < a + 10; r++) {
        cout << *r << " ";
    }
    
    return 0;
}
