#include <iostream>

bool aMayuscula(){
    return true;
}

bool aMinuscula(){ 
    return false; 
}


void funCad(char* c, bool (*f)()) {
    bool convertirMayus = f();

    for (int i = 0; c[i] != '\0'; i++) {
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
}

int main() {
    char cad1[] = "NamsnilK";
    char cad2[] = "Namsnilk";

    funCad(cad1, aMayuscula);
    std::cout << "Mayuscula: " << cad1 << "\n";

    funCad(cad2, aMinuscula);
    std::cout << "Minuscula: " << cad2 << "\n";

    return 0;
}
