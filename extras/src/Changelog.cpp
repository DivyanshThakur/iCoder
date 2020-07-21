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
    Ui::subHeader(Constant::Title::UPCOMING);
    return Constant::Version::UPCOMING;
}

std::vector<std::string> Changelog::Menu::selector()
{
    menuIndexer(Constant::Menu::CHANGELOG.size());
    return Constant::Menu::CHANGELOG;
}

void Changelog::Menu::controller() const
{
    switch (Constant::Menu::CHANGELOG.size() - menuIndex.at(ch - 1))
    {
    case 1:
        Ui::header(Constant::Tag::V1_0);
        Ui::println(Constant::Version::V1_0);
        break;

    case 2:
        Ui::header(Constant::Tag::V1_2);
        Ui::println(Constant::Version::V1_2);
        break;

    case 3:
        Ui::header(Constant::Tag::V1_4);
        Ui::println(Constant::Version::V1_4);
        break;

    case 4:
        Ui::header(Constant::Tag::V1_6);
        Ui::println(Constant::Version::V1_6);
        break;

    case 5:
        Ui::header(Constant::Tag::V1_8);
        Ui::println(Constant::Version::V1_8);
        break;

    case 6:
        Ui::header(Constant::Tag::V2_0);
        Ui::println(Constant::Version::V2_0);
        break;
    }
}

/**************************************************************************************************************
 * 
 *                                           CHANGELOG IMPLEMENTATIONS
 * 
 * ***********************************************************************************************************/

void Changelog::start()
{
    Menu::player(Menu());
}
