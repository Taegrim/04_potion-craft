#pragma once
#include "potion_recipe.h"
#include "stock_manager.h"
#include "recipe_manager.h"

// AlchemyWorkshop 클래스: 레시피 목록을 관리
class AlchemyWorkshop 
{
public:
    void AddRecipe(const std::string& name, const std::vector<std::string>& ingredients);
    void DisplayAllRecipes() const;
    int GetStockByName(const std::string& name) const;
    bool DispensePotionByName(const std::string& name);
    std::vector<std::string> DispensePotionsByIngredient(const std::string& ingredient);
    void ReturnPotionByName(const std::string& name);

    const std::vector<PotionRecipe>& GetAllRecipes() const;

private:
    RecipeManager recipe_manager;
    StockManager stock_manager;
};