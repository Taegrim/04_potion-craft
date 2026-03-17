#pragma once
#include "common.h"

class StockManager
{
public:
	void InitializeStock(const std::string& name);
	bool DispensePotion(const std::string& name);
	void ReturnPotion(const std::string& name);
	int GetStock(const std::string& name) const;

private:
	std::unordered_map<std::string, int> potion_stock;
	static constexpr int MAX_STOCK = 3;
};
