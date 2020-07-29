#include <iostream>
#include "../header/Settings.hpp"
#include "../header/Hints.hpp"
#include "../../constant./Constants.hpp"
#include "../../header/FileHandler.hpp"

Hints::Data Hints::userData;

/**************************************************************************************************************
 * 
 *                                           AbstractMenu IMPLEMENTATIONS
 * 
 * ***********************************************************************************************************/

std::string Hints::Menu::title() const
{
    return std::string(Constant::Title::HINT);
}

std::vector<std::string> Hints::Menu::getStats() const
{
    Ui::subHeader(Constant::Title::STATS);

    std::vector<std::string> vec;
    std::string stats = (Global::showHint) ? "Enabled" : "Disabled";

    vec.emplace_back("Currently: " + stats);
    return vec;
}

std::vector<std::string> Hints::Menu::selector()
{
    menuIndexer(Constant::SubMenu::Settings::HINTS.size());
    return Constant::SubMenu::Settings::HINTS;
}

void Hints::Menu::controller() const
{
    bool isChanged{false};

    switch (menuIndex.at(ch - 1))
    {
    case 1:
        if (!Global::showHint)
            isChanged = true;
        break;

    case 2:
        if (Global::showHint)
            isChanged = true;
        break;
    }

    if (isChanged)
    {
        Global::showHint = !Global::showHint;
        FileHandler::save(data());
    }
}
/**************************************************************************************************************
 * 
 *                                       AbstractSaveable IMPLEMENTATIONS
 * 
 * ***********************************************************************************************************/

std::vector<std::pair<std::string, std::string>> Hints::Data::save() const
{
    std::vector<std::pair<std::string, std::string>> vec;
    vec.emplace_back(Constant::File::SHOW_HINT, Global::showHint);
    return vec;
}

/**************************************************************************************************************
 * 
 *                                         HINTS IMPLEMENTATIONS
 * 
 * ***********************************************************************************************************/

Hints::Data &Hints::data()
{
    return userData;
}

void Hints::start()
{
    Menu::player(Menu());
}