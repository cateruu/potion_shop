#include "Potion.h"

#include <iostream>

void shop() {
    std::cout << "Here is our selection for today:\n";

    for (int i{ 0 }; i < Potion::max_potion_type; i++) {
        std::cout << i << ") " << Potion::name[i] << " costs " << Potion::cost[i] << '\n';
    }
}

int main() {
    shop();

    return 0;
}