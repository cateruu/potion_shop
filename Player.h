#pragma once

#include "Potion.h"

#include <string>
#include <vector>

class Player {
public:
	Player(const std::string& name);

	const int getGold() const { return m_gold; };

private:
	std::string m_name{};
	int m_gold{};
	std::vector<Potion::Type> m_potions{};
};