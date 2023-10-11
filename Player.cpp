#include "Player.h"
#include "Random.h"

Player::Player(const std::string& name) : m_name{ name } {
	m_gold = Random::get(80, 120);
}