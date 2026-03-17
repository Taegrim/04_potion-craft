#include "potion_recipe.h"

PotionRecipe::PotionRecipe(const std::string& name, const std::vector<std::string>& ingredients)
	: name(name), ingredients(ingredients)
{
}

const std::string& PotionRecipe::GetName() const
{
	return name;
}

const std::vector<std::string>& PotionRecipe::GetIngredients() const
{
	return ingredients;
}

bool PotionRecipe::operator==(const std::string& name) const
{
	return (this->name == name);
}
