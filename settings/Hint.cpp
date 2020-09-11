#include "Hint.hpp"
#include "../constant/Constants.hpp"
#include "../main/File.hpp"

Hint::Data Hint::userData;

/**************************************************************************************************************
 * 
 *                                           AbstractMenu IMPLEMENTATIONS
 * 
 * ***********************************************************************************************************/

std::string Hint::Menu::title() const
{
    return std::string(Constant::Title::HINT);
}

std::vector<std::string> Hint::Menu::getStats() const
{
    Ui::subHeader(Constant::Title::STATS);

    std::vector<std::string> vec;
    std::string stats = (Global::showHint) ? "Enabled" : "Disabled";

    vec.emplace_back("Currently: " + stats);
    return vec;
}

std::vector<std::string> Hint::Menu::selector()
{
    menuIndexer(Constant::SubMenu::Settings::HINTS.size());
    return Constant::SubMenu::Settings::HINTS;
}

void Hint::Menu::controller() const
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
        File::save(data());
    }
}
/**************************************************************************************************************
 * 
 *                                       AbstractSaveable IMPLEMENTATIONS
 * 
 * ***********************************************************************************************************/

std::vector<std::pair<std::string, std::string>> Hint::Data::save() const
{
    std::vector<std::pair<std::string, std::string>> vec;
    vec.emplace_back(Constant::File::SHOW_HINT, std::to_string(Global::showHint));
    return vec;
}

/**************************************************************************************************************
 * 
 *                                         HINTS IMPLEMENTATIONS
 * 
 * ***********************************************************************************************************/

Hint::Data &Hint::data()
{
    return userData;
}

void Hint::start()
{
    Menu::player(Menu());
}