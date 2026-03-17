#include "alchemy.h"

//int main() {
//    AlchemyWorkshop myWorkshop;
//
//    while (true) {
//        std::cout << "--- 연금술 공방 관리 시스템 ---" << std::endl;
//        std::cout << "1. 레시피 추가" << std::endl;
//        std::cout << "2. 모든 레시피 출력" << std::endl;
//        std::cout << "3. 종료" << std::endl;
//        std::cout << "선택: ";
//
//        int choice;
//        std::cin >> choice;
//
//        if (std::cin.fail()) {
//            std::cout << "잘못된 입력입니다. 숫자를 입력해주세요." << std::endl;
//            std::cin.clear();
//            std::cin.ignore(10000, '\n');
//            continue;
//        }
//
//        if (choice == 1) {
//            std::string name;
//            std::cout << "물약 이름: ";
//            std::cin.ignore(10000, '\n');
//            std::getline(std::cin, name);
//
//            // 여러 재료를 입력받기 위한 로직
//            std::vector<std::string> ingredients_input;
//            std::string ingredient;
//            std::cout << "필요한 재료들을 입력하세요. (입력 완료 시 '끝' 입력)" << std::endl;
//
//            while (true) {
//                std::cout << "재료 입력: ";
//                std::getline(std::cin, ingredient);
//
//                // 사용자가 '끝'을 입력하면 재료 입력 종료
//                if (ingredient == "끝") {
//                    break;
//                }
//                ingredients_input.push_back(ingredient);
//            }
//
//            // 입력받은 재료가 하나 이상 있을 때만 레시피 추가
//            if (!ingredients_input.empty()) {
//                myWorkshop.AddRecipe(name, ingredients_input);
//            }
//            else {
//                std::cout << ">> 재료가 입력되지 않아 레시피 추가를 취소합니다." << std::endl;
//            }
//
//        }
//        else if (choice == 2) {
//            myWorkshop.DisplayAllRecipes();
//
//        }
//        else if (choice == 3) {
//            std::cout << "공방 문을 닫습니다..." << std::endl;
//            break;
//
//        }
//        else {
//            std::cout << "잘못된 선택입니다. 다시 시도하세요." << std::endl;
//        }
//    }
//
//    return 0;
//}

int main()
{
    AlchemyWorkshop workshop;

    workshop.AddRecipe("Healing Potion", { "Herb", "Water" });
    workshop.AddRecipe("Mana Potion", { "Magic Water", "Crystal" });
    workshop.AddRecipe("Stamina Potion", { "Herb", "Berry" });
    workshop.AddRecipe("Fire Resistance Potion", { "Fire Flower", "Ash" });

    std::cout << "=== 초기 상태 (레시피 추가 + 재고 자동 3개) ===\n";
    workshop.DisplayAllRecipes();

    std::cout << "\n[재고 확인] Healing Potion 재고: "
        << workshop.GetStockByName("Healing Potion") << "\n";

    std::cout << "\n=== 이름으로 지급 테스트 (Healing Potion 3회 지급) ===\n";
    std::cout << "1회 지급: " << (workshop.DispensePotionByName("Healing Potion") ? "성공" : "실패") << "\n";
    std::cout << "2회 지급: " << (workshop.DispensePotionByName("Healing Potion") ? "성공" : "실패") << "\n";
    std::cout << "3회 지급: " << (workshop.DispensePotionByName("Healing Potion") ? "성공" : "실패") << "\n";

    std::cout << "현재 재고: " << workshop.GetStockByName("Healing Potion") << "\n";

    std::cout << "4회 지급(재고 없으면 실패): "
        << (workshop.DispensePotionByName("Healing Potion") ? "성공" : "실패") << "\n";

    std::cout << "\n=== 재료로 지급 테스트 (ingredient = Herb) ===\n";
    std::vector<std::string> dispensed = workshop.DispensePotionsByIngredient("Herb");

    std::cout << "지급된 물약 수: " << dispensed.size() << "\n";
    for (const std::string& name : dispensed)
        std::cout << "- " << name << "\n";

    std::cout << "\n=== 공병 반환 테스트 (Healing Potion) ===\n";
    workshop.ReturnPotionByName("Healing Potion");
    workshop.ReturnPotionByName("Healing Potion");
    workshop.ReturnPotionByName("Healing Potion");
    workshop.ReturnPotionByName("Healing Potion"); // 이미 3이면 더 올라가면 안 됨

    std::cout << "반환 후 재고(최대 3 유지): "
        << workshop.GetStockByName("Healing Potion") << "\n";

    std::cout << "\n=== 최종 상태 ===\n";
    workshop.DisplayAllRecipes();

    std::cout << "\n=== 재료로 지급 테스트 (ingredient = Herb) ===\n";
    dispensed = workshop.DispensePotionsByIngredient("Herb");

    std::cout << "지급된 물약 수: " << dispensed.size() << "\n";
    for (const std::string& name : dispensed)
        std::cout << "- " << name << "\n";
}