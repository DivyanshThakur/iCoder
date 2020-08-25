/***********************************************************************************************************************
 *                                                   ICODER
 *
 * DEVELOPER - DIVYANSH SINGH THAKUR
 *
 * VERSION - 1.9.20.5.20-BETA
 *
 * FIRST BETA - 27 DECEMBER, 2019
 *
 * FIRST STABLE RELEASE - 19 FEBRUARY, 2020
 *
 * DESCRIPTION :
 * A SMALL PROJECT WITH ALL FEATURES SUCH AS DATA STRUCTURE, ALGORITHM, GAMES AND MUCH MORE...
 *
 * *********************************************************************************************************************/

#include <iostream>
#include <windows.h>
#include <dir.h>
#include "../header/iCoder.hpp"
#include "../header/More.hpp"
#include "../../extras/Extras.hpp"
#include "../../settings/header/Settings.hpp"
#include "../header/File.hpp"
#include "../../dsa/header/DataStructure.hpp"
#include "../../namespace/header/cod_scan.hpp"
#include "../../constant/Constants.hpp"

int main()
{
    iCoder::start();

    return 0;
}

/**************************************************************************************************************
 *
 *                                           AbstractMenu IMPLEMENTATIONS
 *
 * ***********************************************************************************************************/

const std::string &iCoder::Menu::title() const
{
    return std::string(Constant::Title::MAIN);
}

std::vector<std::string> iCoder::Menu::getStats() const
{
    Ui::subHeader(Constant::Title::STATS);

    std::vector<std::string> vec;

    if (Global::activeUser != Constant::NULL_STR)
        vec.emplace_back("User:    " + Global::activeUser);

    vec.emplace_back("Version: " + Constant::iCoder::VERSION);

    return vec;
}

std::vector<std::string> iCoder::Menu::selector()
{
    size_t size = Constant::Menu::MAIN.size();

    if (Global::activeUser == Constant::NULL_STR) // if active user is null, run this code
    {
        menuIndexer(size);
        return Constant::Menu::MAIN;
    }

    menuIndexer(size, 1, 4);
    menuIndex.at(0) = 3;
    menuIndex.push_back(size);

    std::vector<std::string> toDisplayMenu{"Data Structure"};
    toDisplayMenu.insert(toDisplayMenu.end(), Constant::Menu::MAIN.begin() + 3, Constant::Menu::MAIN.end());
    toDisplayMenu.emplace_back("Sign Out");

    return toDisplayMenu;
}

void iCoder::Menu::controller() const
{
    switch (title().size())
    {
    case 1:
        DataStructure::start();
        break;

    case 2:
        CP.start();
        break;

    case 3:
        Help::start();
        break;

    case 4:
        About::start();
        break;

    case 5:
        Update::start();
        break;

    case 6:
        Settings::start();
        break;
    }
}

/**************************************************************************************************************
 *
 *                                           MAIN IMPLEMENTATIONS
 *
 * ***********************************************************************************************************/

void iCoder::start()
{
    load();
    Menu::player(Menu());
}

void iCoder::load()
{
    adjustConsoleSize(); // Adjust the window size
    createPath();        // Initialize the paths

    File::load(Settings::data()); // Restore the settings that was previously changed and saved
}

// void iCoder::signOut()
// {
//     Global::activeUser = Constant::NULL_STR;
//     File::save(Settings::data());
//     Constant::Path::USER.clear();
//     welcomeFlag = true;

//     // AnimeHandler::sign_out();
// }

// It creates a path to the user's document folder for storing the user data
void iCoder::createPath()
{
    char *userpath = getenv("USERPROFILE"); // stores the path to userProfile

    if (userpath == nullptr)
    {
        Ui::println("No user path found!");
        exit(1);
    }

    // assigning path to their respective variables
    Constant::Path::PATH = std::string(userpath) + "\\Documents\\iCoder\\";
    Constant::Path::DB = Constant::Path::PATH + "users.dat";
    Constant::Path::SETTINGS = Constant::Path::PATH + "settings.dat";

    if (!checkDirectory())                   // checking if the directory "data" exists or not
        mkdir(Constant::Path::PATH.c_str()); // these code will create a folder in that specific destination
}

bool iCoder::checkDirectory()
{
    // code to check if a Directory exists or not
    DWORD attribs = ::GetFileAttributesA(Constant::Path::PATH.c_str());

    if (attribs == INVALID_FILE_ATTRIBUTES)
        return false;

    return (attribs & FILE_ATTRIBUTE_DIRECTORY);
}

void iCoder::adjustConsoleSize()
{
    //code to adjust the console size to fix for all the screens
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //stores the console's current dimensions

    MoveWindow(console, r.left, r.top, Constant::Ui::CONSOLE_WIDTH, Constant::Ui::CONSOLE_HEIGHT, TRUE); // 850 width, 600 height
}