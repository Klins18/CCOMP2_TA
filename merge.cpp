#include <iostream>
using namespace std;

void merge(int *p, int *q){
    int *f = q + (q - p);
    
    while(p < q && q < f){
        if(*p <= *q){
            p++;
        } else {
            int temp = *q;
            int *k = q;
            while(k > p){ //recorrer
                *k = *(k - 1);
                k--;
            }
            
            *p = temp;
            p++;
            q++;
        }
    }
}

int main()
{
    int a[10] = {6,4,8,10,22,5,7,11,19,21};
    int *p = a;
    int *q = a + 5;
   
    merge(p, q);
    
    for(int *r = a; r < a + 10; r++){
        cout << *r << " ";
    }
   
    return 0;
}
