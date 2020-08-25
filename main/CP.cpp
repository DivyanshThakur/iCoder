#include "header/CP.hpp"
#include "../constant/Constants.hpp"

/**************************************************************************************************************
 * 
 *                                           AbstractMenu IMPLEMENTATIONS
 * 
 * ***********************************************************************************************************/

std::string More::Menu::title() const
{
    return std::string(Constant::Title::MORE);
}

std::vector<std::string> More::Menu::getStats() const
{
    Ui::subHeader(Constant::Title::TIP);

    std::vector<std::string> vec;
    vec.emplace_back(Ui::getTip());
    return vec;
}

std::vector<std::string> More::Menu::selector()
{
    menuIndexer(Constant::Menu::MORE.size());
    return Constant::Menu::MORE;
}

void More::Menu::controller() const
{
    switch (menuIndex.at(ch - 1))
    {
    case 1:
        Games::start();
        break;
    }
}

/**************************************************************************************************************
 * 
 *                                           MORE IMPLEMENTATIONS
 * 
 * ***********************************************************************************************************/

void More::start()
{
    Menu::player(Menu());
}