#include <iostream>
using namespace std;

template <class T>
class Cola {
    T arr[10];
    T* head = nullptr;
    T* tail = nullptr;
public:
    bool vacio();
    bool lleno();
    bool push(T val);
    bool pop(T &val);
    void mostrar();
};

template <class T>
bool Cola<T>::vacio() {
    return head == nullptr;
}

template <class T>
bool Cola<T>::lleno() {
    if(vacio()){
        return false;
    }
    T* siguiente = (tail == arr + 9) ? arr : tail + 1;
    return siguiente == head;
}

template <class T>
bool Cola<T>::push(T val) {
    if (lleno()) {
        return false;
    }
    if (vacio()) {
        head = tail = arr;
        *tail = val;
    }
    else {
        if (tail == arr + 9)
            tail = arr;
        else
            tail++;
        *tail = val;
    }
    return true;
}

template<class T>
bool Cola<T>::pop(T &val) {
    if (vacio()) {
        return false;
    }
    val = *head;
    if (head == tail) {
        head = tail = nullptr;
    }
    else {
        if (head == arr + 9)
            head = arr;
        else
            head++;
    }
    return true;
}

template <class T>
void Cola<T>::mostrar() {
    if (vacio()) {
        cout << "cola vacia" << endl;
        return;
    }
    T *p = head;
    while (true) {
        cout << *p << " ";
        if (p == tail) break;
        if (p == arr + 9)
            p = arr;
        else
            p++;
    }
    cout << endl;
}

int main() {
    Cola<int> c;
   
    c.push(2);
    c.push(4);
    c.push(6);
    c.push(10);
    c.push(20);
    c.mostrar();
    
    int a;
    c.pop(a);
    cout << "salio: " << a << endl;
    c.pop(a);
    cout << "salio: " << a << endl;
   
    cout << "Elementos que quedan: " << endl;
    while (c.pop(a)) {
        cout << a << " ";
    }
    cout << endl;
    
    return 0;
}
