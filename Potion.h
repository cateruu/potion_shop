#pragma once

#include <array>
#include <string_view>
#include <cassert>

namespace Potion {
	enum Type {
		healing,
		mana,
		speed,
		invisibility,

		max_potion_type,
	};

	using namespace std::literals;
	constexpr std::array types{ healing, mana, speed, invisibility };
	constexpr std::array cost{ 20, 30, 12, 50 };
	constexpr std::array name{ "healing"sv, "mana"sv, "speed"sv, "invisibility"sv };

	static_assert(std::size(cost) == Type::max_potion_type && "Cost array have incorrect length!");
	static_assert(std::size(name) == Type::max_potion_type && "Names array have incorrect length!");
}