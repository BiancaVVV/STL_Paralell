﻿#include <iostream>
#include <string>
#include <algorithm>
#include <execution>

// Funcție pentru a căuta un substring într-un string folosind căutare liniară paralelă
bool search_substring(const std::string& str, const std::string& substr) {
    // Utilizăm std::search cu std::execution::par pentru execuție paralelă
    auto it = std::search(std::execution::par,
        str.begin(), str.end(),
        substr.begin(), substr.end());

    // Verificăm dacă substring-ul a fost găsit
    return (it != str.end());
}

int main() {
    std::string str = "Acesta este un exemplu de string in care vom cauta un substring.";
    std::string substr = "exemplu";

    if (search_substring(str, substr)) {
        std::cout << "Substring-ul a fost găsit!" << std::endl;
    }
    else {
        std::cout << "Substring-ul nu a fost găsit!" << std::endl;
    }

    return 0;
}
