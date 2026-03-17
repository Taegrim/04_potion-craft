#include "alchemy.h"
#include "recipe_manager.h"

void AlchemyWorkshop::AddRecipe(const std::string& name, const std::vector<std::string>& ingredients)
{
    if (recipe_manager.AddRecipe(name, ingredients)) {
        stock_manager.InitializeStock(name);
    }
}

void AlchemyWorkshop::DisplayAllRecipes() const
{
    auto& recipes = recipe_manager.GetAllRecipes();
    if (recipes.empty()) {
        std::cout << "아직 등록된 레시피가 없습니다." << std::endl;
        return;
    }

    std::cout << "\n--- [ 전체 레시피 목록 ] ---" << std::endl;
    for (int i = 0; i < recipes.size(); ++i) {
        std::cout << "- 물약 이름: " << recipes[i].GetName() << std::endl;
        std::cout << "  > 필요 재료: ";

        auto& v = recipes[i].GetIngredients();
        for (int j = 0; j < v.size(); ++j) {
            std::cout << v[j];

            if (j < v.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "---------------------------\n";
}

int AlchemyWorkshop::GetStockByName(const std::string& name) const
{
    return stock_manager.GetStock(name);
}

bool AlchemyWorkshop::DispensePotionByName(const std::string& name)
{
    return stock_manager.DispensePotion(name);
}

std::vector<std::string> AlchemyWorkshop::DispensePotionsByIngredient(const std::string& ingredient)
{
    auto v = recipe_manager.FindRecipesByIngredient(ingredient);
    std::vector<std::string> recipes{};

    for (const auto& recipe : v) {
        if (stock_manager.DispensePotion(recipe.GetName())) {
            recipes.push_back(recipe.GetName());
        }
    }

    return recipes;
}

void AlchemyWorkshop::ReturnPotionByName(const std::string& name)
{
    stock_manager.ReturnPotion(name);
}
