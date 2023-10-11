#include "Potion.h"
#include "Player.h"

#include <iostream>
#include <string>

int charNumToInt(char c)
{
	return c - '0';
}

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

	bool correctInput{ true };
	while(true) {

		if (correctInput) {
			shop();
			std::cout << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";
		}
		else {
			std::cout << "That's an invalid input. Try again: ";
		}
		char input{};
		std::cin >> input;

		if (!std::cin) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			correctInput = false;
			continue;
		}

		if (input == 'q') {
			break;
		}

		if (charNumToInt(input) < 0 || charNumToInt(input) >= Potion::max_potion_type) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			correctInput = false; 
			continue;
		}

		correctInput = true;

		if (Potion::cost[charNumToInt(input)] > player.getGold()) {
			std::cout << "You can't afford that.\n\n";
			continue;
		}

		player.buyPotion(Potion::types[charNumToInt(input)], Potion::cost[charNumToInt(input)]);
		std::cout << "You purchased a potion of " << Potion::name[charNumToInt(input)] << ". You have " << player.getGold() << " gold left.\n\n";

		if (player.getGold() == 0) {
			break;
		}

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	std::cout << '\n';
	player.showInventory();
	std::cout << '\n';

	std::cout << "\nThanks for shopping at Roscoe's potion emporium!\n";

	return 0;
}