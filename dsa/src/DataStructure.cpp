#include <iostream>
#include "../header/DataStructure.hpp"
#include "../header/Array.hpp"
#include "../header/String.hpp"

/**************************************************************************************************************
 * 
 *                                           IMENU IMPLEMENTATIONS
 * 
 * ***********************************************************************************************************/

std::string DataStructure::Menu::title() const
{
    return std::string(Constant::Title::DATA_STRUCTURE);
}

std::vector<std::string> DataStructure::Menu::getStats() const
{
    Ui::subHeader(Constant::Title::TIP);

    std::vector<std::string> vec;
    vec.emplace_back(Ui::getTip());
    return vec;
}

std::vector<std::string> DataStructure::Menu::selector()
{
    menuIndexer(Constant::Menu::DATA_STRUCTURE.size());
    return Constant::Menu::DATA_STRUCTURE;
}

void DataStructure::Menu::controller() const
{
    switch (menuIndex.at(ch - 1))
    {
    case 1:
        // ArrayHandler::start();
        break;
    case 2:
        StringHandler::start();
        break;
    }
}

/**************************************************************************************************************
 * 
 *                                          DATA STRUCTURE IMPLEMENTATIONS
 * 
 * ***********************************************************************************************************/

void DataStructure::start()
{
    Menu::player(Menu());
}