#include "Player.h"
#include "Potion.h"
#include "Random.h"

#include <iostream>

Player::Player(const std::string& name) : m_name{ name } {
	m_gold = Random::get(80, 120);
}

void Player::buyPotion(Potion::Type t, int price) {
	m_potions[t]++;
	m_gold -= price;
}

void Player::showInventory() {
	std::cout << "Your inventory contains:\n";

	for (int i{ 0 }; i < m_potions.size(); i++) {
		if (m_potions[i] == 0) {
			continue;
		}
		else {
			std::cout << m_potions[i] << "x potion of " << Potion::name[i] << '\n';
		}
	}

	std::cout << "You escaped with " << m_gold << " gold remaining.\n";
}