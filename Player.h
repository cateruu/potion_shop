#pragma once

#include "Potion.h"

#include <string>
#include <array>

class Player {
public:
	Player(const std::string& name);

	void buyPotion(Potion::Type t, int price);
	void showInventory();

	const int getGold() const { return m_gold; };
	const int getPotions(Potion::Type t) const { return m_potions[t]; };

private:
	std::string m_name{};
	int m_gold{};
	std::array<int, Potion::max_potion_type> m_potions{};
};