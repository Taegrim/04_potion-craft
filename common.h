#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <format>
#include <cstdlib>
#include <algorithm>
#include <memory>
#include <optional>
#include <unordered_map>


inline void ClearScreen() {
	std::cout << "\033[2J\033[1;1H";
}