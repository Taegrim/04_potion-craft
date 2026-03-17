#include "stock_manager.h"

void StockManager::InitializeStock(const std::string& name)
{
    potion_stock[name] = MAX_STOCK;
}

bool StockManager::DispensePotion(const std::string& name)
{
    auto it = potion_stock.find(name);

    if (it == potion_stock.end()) {
        return false;
    }

    if (it->second > 0) {
        --it->second;
        return true;
    }

    return false;
}

void StockManager::ReturnPotion(const std::string& name)
{
    auto it = potion_stock.find(name);

    if (it == potion_stock.end()) {
        return;
    }

    if (it->second >= MAX_STOCK) {
        return;
    }

    ++it->second;
}

int StockManager::GetStock(const std::string& name) const
{
    auto it = potion_stock.find(name);

    if (it == potion_stock.end()) {
        return 0;
    }
    
    return it->second;
}