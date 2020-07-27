#include <iostream>
#include "../header/Games.hpp"
#include "../header/TicTacToe.hpp"
#include "../../namespace/header/cod_scan.hpp"
#include "../../constant/Constants.hpp"

/**************************************************************************************************************
 * 
 *                                           AbstractMenu IMPLEMENTATIONS
 * 
 * ***********************************************************************************************************/

std::string Games::Menu::title() const
{
    return std::string(Constant::Title::GAMES);
}

std::vector<std::string> Games::Menu::getStats() const
{
    Ui::subHeader(Constant::Title::TIP);

    std::vector<std::string> vec;
    vec.emplace_back(Ui::getTip());
    return vec;
}

std::vector<std::string> Games::Menu::selector()
{
    menuIndexer(Constant::Menu::GAMES.size());
    return Constant::Menu::GAMES;
}

void Games::Menu::controller() const
{
    switch (menuIndex.at(ch - 1))
    {
    case 1:
        TicTacToe::start();
        break;
    }
}

/**************************************************************************************************************
 * 
 *                                           MORE IMPLEMENTATIONS
 * 
 * ***********************************************************************************************************/

void Games::start()
{
    Menu::player(Menu());
}