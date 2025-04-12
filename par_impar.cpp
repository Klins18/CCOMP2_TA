#include <iostream>
using namespace std;

void merge (int *p, int*q){
    int *fin = p+(q-p)*2;
    while(p<q && q<fin){
        if(*p < *q){
            p++;
        }else{
            for(int *r = p; r<q;r++){
                swap(*r , *q);
                q++;
                p++;
            }
        }
    }

}

int main(){
    int arr[] = {12,18,50,100,120,7,11,23,57,69};
    merge(arr,arr+5);
    return 0;
}