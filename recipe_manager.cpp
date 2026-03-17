#include "recipe_manager.h"

bool RecipeManager::AddRecipe(const std::string& name, const std::vector<std::string>& ingredients)
{
    if (FindRecipeByName(name)) {
        std::cout << "이미 존재하는 레시피입니다." << std::endl;
        return false;
    }

	recipes.emplace_back(PotionRecipe(name, ingredients));
	std::cout << ">> 새로운 레시피 '" << name << "'이(가) 추가되었습니다." << std::endl;
    return true;
}

std::optional<PotionRecipe> RecipeManager::FindRecipeByName(const std::string& name)
{
    auto it = std::find(recipes.begin(), recipes.end(), name);

    if (it == recipes.end()) {
        return std::nullopt;
    }

    return *it;
}

std::vector<PotionRecipe> RecipeManager::FindRecipesByIngredient(const std::string& ingredient) const
{
    std::vector<PotionRecipe> v;

    /// 탐색
    for (const auto& recipe : recipes) {
        const auto& ingredients = recipe.GetIngredients();

        auto it = std::find(ingredients.begin(), ingredients.end(), ingredient);

        if (it != ingredients.end()) {
            v.push_back(recipe);
        }
    }

    return v;
}

const std::vector<PotionRecipe>& RecipeManager::GetAllRecipes() const
{
    return recipes;
}