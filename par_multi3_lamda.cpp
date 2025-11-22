#include <iostream>

int main() {
    auto split = [](int* ini, int* fin, auto f) {
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
    };

    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);


    split(arr, arr + n, [](int x){ return x % 2 == 0; });
    std::cout << "pares: ";
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
    std::cout << "\n";

    int arr2[] = {1, 2, 3, 4, 5, 6, 7};

    split(arr2, arr2 + n, [](int x){ return x % 3 == 0; });
    std::cout << "multiplos de 3: ";
    for (int i = 0; i < n; i++) std::cout << arr2[i] << " ";
    std::cout << "\n";

    return 0;
}
