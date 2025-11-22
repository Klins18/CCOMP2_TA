#include <iostream>

int main() {
    auto funCad = [](char* c, auto f) {
        bool convertirMayus = f();  
        for (char *i = c; *i; i++) {
            if (convertirMayus) {
                if (*i >= 'a' && *i <= 'z') 
                    *i = *i - 32;  
            } else {
                if (*i >= 'A' && *i <= 'Z') 
                    *i = *i + 32;
            }
        }
    };
    
    char cad1[] = "NamsnilK";
    char cad2[] = "&%$Namsnilk";
    
    funCad(cad1, [](){ return true; });
    std::cout << "Mayuscula: " << cad1 << "\n";

    funCad(cad2, [](){ return false; });
    std::cout << "Minuscula: " << cad2 << "\n";

    return 0;
}
