#include <iostream>

class AMayuscula {
public:
    char operator()(char a) const {
         if (a >= 'a' && a <= 'z') 
            return a - 32;
        return a;    
    }
};

class AMinuscula {
public:
    char operator()(char a) const {
        if (a >= 'A' && a <= 'Z') 
            return a + 32;
        return a;
    }
};

template <typename Functor>
void funCad(char* c, Functor f) {
    for (char *i = c; *i; i++) 
        *i = f(*i);
}

int main() {
    char cad1[] = "NamsnilK";
    char cad2[] = "&%$Namsnilk";
    
    funCad(cad1, AMayuscula());
    std::cout << "Mayuscula: " << cad1 << "\n";
    
    funCad(cad2, AMinuscula());
    std::cout << "Minuscula: " << cad2 << "\n";
    
    return 0;
}
