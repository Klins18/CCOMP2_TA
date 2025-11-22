#include <iostream>

int main() {
    auto funCad = [](char* c, auto f) {
        auto convertirMayus = f();  
        for (auto i = 0; c[i] != '\0'; i++) {
            if (convertirMayus) {
                if (c[i] >= 'a' && c[i] <= 'z') {
                    c[i] = c[i] - 32;
                }
            } else {
                if (c[i] >= 'A' && c[i] <= 'Z') {
                    c[i] = c[i] + 32;
                }
            }
        }
    };

    char cad1[] = "NamsnilK";
    char cad2[] = "Namsnilk";

    funCad(cad1, [](){ return true; });
    std::cout << "Mayuscula: " << cad1 << "\n";

    funCad(cad2, [](){ return false; });
    std::cout << "Minuscula: " << cad2 << "\n";

    return 0;
}
