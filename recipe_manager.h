#pragma once
#include "potion_recipe.h"

class RecipeManager
{
public:
    bool AddRecipe(const std::string& name, const std::vector<std::string>& ingredients);
    std::optional<PotionRecipe> FindRecipeByName(const std::string& name);
    std::vector<PotionRecipe> FindRecipesByIngredient(const std::string& ingredient) const;
    const std::vector<PotionRecipe>& GetAllRecipes() const;

private:
    std::vector<PotionRecipe> recipes;
};
