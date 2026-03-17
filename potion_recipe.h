#pragma once
#include "common.h"

class PotionRecipe 
{
public:
    PotionRecipe(const std::string& name, const std::vector<std::string>& ingredients);
    
    const std::string& GetName() const;
    const std::vector<std::string>& GetIngredients() const;

    bool operator==(const std::string& name) const;
private:
    std::string name;
    std::vector<std::string> ingredients;
};
