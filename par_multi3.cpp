#include <iostream>

class EsPar {
public:
    bool operator()(int x) const {
        return x % 2 == 0;
    }
};

class EsMultiploDe3 {
public:
    bool operator()(int x) const {
        return x % 3 == 0;
    }
};

template <typename T>
void split(int* ini, int* fin, T f) {
    int* left = ini;
    int* right = fin - 1;
    
    while (left < right) {
        while (left < right && f(*left)) {
            left++;
        }
        while (left < right && !f(*right)) {
            right--;
        }
        if (left < right) {
            std::swap(*left, *right);
            left++;
            right--;
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    split(arr, arr + n, EsPar());
    std::cout << "pares: ";
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
    std::cout << "\n";
    
    int arr2[] = {1, 2, 3, 4, 5, 6, 7};
    split(arr2, arr2 + n, EsMultiploDe3());
    std::cout << "multiplos de 3: ";
    for (int i = 0; i < n; i++) std::cout << arr2[i] << " ";
    std::cout << "\n";
    
    return 0;
}
