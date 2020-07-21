#include "../Extras.hpp"
#include "../../constant/Constants.hpp"

/**************************************************************************************************************
 * 
 *                                           IMENU IMPLEMENTATIONS
 * 
 * ***********************************************************************************************************/

std::string Update::Menu::title() const
{
    return std::string(Constant::Title::UPDATES);
}

std::vector<std::string> Update::Menu::getStats() const
{
    Ui::subHeader(Constant::Title::STATS);

    std::vector<std::string> vec;

    if (Global::activeUser != Constant::NULL_STR)
        vec.emplace_back("User:    " + Global::activeUser);

    vec.emplace_back("Version: " + Constant::iCoder::VERSION);

    return vec;
}

std::vector<std::string> Update::Menu::selector()
{
    menuIndexer(Constant::Menu::UPDATES.size());
    return Constant::Menu::UPDATES;
}

void Update::Menu::controller() const
{
    switch (menuIndex.at(ch - 1))
    {
    case 1: // Downloads the latest stable release
        system(("start " + Constant::Url::STABLE).c_str());
        break;
    case 2: // Downloads the latest beta release
        system(("start " + Constant::Url::BETA).c_str());
        break;
    }
}

/**************************************************************************************************************
 * 
 *                                           UPDATE IMPLEMENTATIONS
 * 
 * ***********************************************************************************************************/

void Update::start()
{
    Menu::player(Menu());
}
