#include "../Extras.hpp"
#include "../../constant/Constants.hpp"

/**************************************************************************************************************
 * 
 *                                           IMENU IMPLEMENTATIONS
 * 
 * ***********************************************************************************************************/

std::string Changelog::Menu::title() const
{
    return std::string(Constant::Title::CHANGELOG);
}

std::vector<std::string> Changelog::Menu::getStats() const
{
    std::vector<std::string> vec;
    vec.emplace_back(Constant::Title::STATS);

    if (Global::activeUser != Constant::NULL_STR)
        vec.emplace_back("User:    " + Global::activeUser);

    vec.emplace_back("Version: " + Constant::iCoder::VERSION);

    return vec;
}

std::vector<std::string> Changelog::Menu::selector()
{
    menuIndex.clear(); // clear the previous saved index

    for (size_t i{0}; i < Constant::SubMenu::size(); i++)
        menuIndex.push_back(i + 1);

    return Constant::SubMenu::UPDATES;
}

/**
 * The menuIndex stores the index of the menu options that is currently displayed in the screen
 * Menu::caller() calls the required function by using below logic
 * Any input less than 1 or greater than the menuIndex size, throws Invalid choice message
 * if the input is between the menuIndex size range, it calculates which function to call
 * Logic - the (input - 1) is passed as the index of menuIndex to get the index of Menu::Changelog
 * Since, the index of Menu::Changelog is stored in menuIndex and thus is passed in menu controller
 **/

void Changelog::Menu::caller() const
{
    if (ch > 0 && ch <= static_cast<int>(menuIndex.size()))
        controller();
    else
        Ui::println(std::string{"Invalid choice"});
}

void Changelog::Menu::controller() const
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
 *                                           MAIN IMPLEMENTATIONS
 * 
 * ***********************************************************************************************************/

void Changelog::start()
{
    Menu::player(Menu());
}
