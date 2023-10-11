#include "Potion.h"
#include "Player.h"

#include <iostream>
#include <string>

void shop() {
    std::cout << "Here is our selection for today:\n";

    for (int i{ 0 }; i < Potion::max_potion_type; i++) {
        std::cout << i << ") " << Potion::name[i] << " costs " << Potion::cost[i] << '\n';
    }
}

int main() {
    std::cout << "Welcome to Roscoe's potion emporium!\n";
    
    std::cout << "Enter your name: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name);

    Player player{ name };

    std::cout << "Hello, " << name << ", you have " << player.getGold() << " gold.\n\n";

    shop();

    std::cout << "\nThanks for shopping at Roscoe's potion emporium!\n";

    return 0;
}