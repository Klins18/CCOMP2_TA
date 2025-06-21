#include <iostream>
#include <string>

using namespace std;

class iterador{
    int *x;
    public:

    void operator = (int *p){
        x=p;
    }
    void operator = (int p){
        *x=p;
    }
    bool operator < (int *p){
        return (x < p);
    }
    iterador operator ++ (int){
        iterador a;
        x++;
        a=x;
    }
    friend ostream &operator<<( ostream &output, iterador a) {
        output << *(a.x);
        return output;
    }

};

int main(){
    iterador it;
    int A[10] = {1,2,3,4,5,6,7,8,9,10};

    int b=100;
    for(it=A;it < A+10;it++){
        it =b;
        b+=10;
    }

    for(it=A;it < A+10;it++){
        cout << it << " ";
    }cout << endl;


    return 0;
}