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
#include "iCoder.hpp"
#include "header/More.hpp"
#include "extras/Extras.hpp"
#include "header/Settings.hpp"
#include "header/FileHandler.hpp"
#include "header/AccountHandler.hpp"
// #include "dsa/header/DataStructure.hpp"
#include "namespace/header/cod_scan.hpp"
// #include "animation/header/AnimeHandler.hpp"
#include "constant/Constants.hpp"

int main()
{
    Main::start();

    return 0;
}

/**************************************************************************************************************
 * 
 *                                           IMENU IMPLEMENTATIONS
 * 
 * ***********************************************************************************************************/

std::string Main::Menu::title() const
{
    return std::string(Constant::Title::MAIN);
}

std::vector<std::string> Main::Menu::getStats() const
{
    Ui::subHeader(Constant::Title::STATS);

    std::vector<std::string> vec;

    if (Global::activeUser != Constant::NULL_STR)
        vec.emplace_back("User:    " + Global::activeUser);

    vec.emplace_back("Version: " + Constant::iCoder::VERSION);

    return vec;
}

std::vector<std::string> Main::Menu::selector()
{
    // menuIndex.clear(); // clear the previous saved index
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

void Main::Menu::controller() const
{
    switch (menuIndex.at(ch - 1))
    {
    case 1: // go to log in screen
        AccountHandler::login();
        break;

    case 2: // go to create account screen
        AccountHandler::createAccount();
        break;

    case 3: // login Anonymously / Data Structure
        home();
        break;

    case 4: // open more features screen
        More::start();
        break;

    case 5:                          // show saved user details
        AccountHandler::showUsers(); // fetches user details and display it
        break;

    case 6: // help for shortcuts
        Extras::help();
        break;

    case 7: // details about the software
        Extras::about();
        break;

    case 8: // changelog
        Changelog::start();
        break;

    case 9: // update section to get latest and beta versions
        Update::start();
        break;

    case 10: // Customize the software using settings
        Settings::start();
        break;

    case 11: // sign out
        signOut();
        break;
    }
}

/**************************************************************************************************************
 * 
 *                                           MAIN IMPLEMENTATIONS
 * 
 * ***********************************************************************************************************/
bool Main::welcomeFlag = true;

void Main::start()
{
    load();
    Menu::player(Menu());
}

void Main::load()
{
    adjustConsoleSize(); // Adjust the window size
    createPath();        // Initialize the paths

    FileHandler::load(Settings::data()); // Restore the settings that was previously changed and saved

    if (Global::activeUser != Constant::NULL_STR) // checking for current signed user
        home();                                   // if the user is saved in file it will automatically sign in the active user
}

void Main::home()
{
    if (welcomeFlag && Global::showWelcome)
    {
        std::string userID = (Global::activeUser == Constant::NULL_STR) ? "User" : Global::activeUser;
        welcomeFlag = false;

        Ui::logo();                               // display the logo - iCoder
        Ui::popUp("--> Welcome " + userID + "!"); // display the welcome message
    }

    // DataStructure::start();
}

void Main::signOut()
{
    Global::activeUser = Constant::NULL_STR;
    Settings::saveActiveUser();
    Constant::Path::USER.clear();
    welcomeFlag = true;

    // AnimeHandler::sign_out();
}

// It creates a path to the user's document folder for storing the user data
void Main::createPath()
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

bool Main::checkDirectory()
{
    // code to check if a Directory exists or not
    DWORD attribs = ::GetFileAttributesA(Constant::Path::PATH.c_str());

    if (attribs == INVALID_FILE_ATTRIBUTES)
        return false;

    return (attribs & FILE_ATTRIBUTE_DIRECTORY);
}

void Main::adjustConsoleSize()
{
    // code to adjust the console size to fix for all the screens
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //stores the console's current dimensions

    MoveWindow(console, r.left, r.top, Constant::Ui::CONSOLE_WIDTH, Constant::Ui::CONSOLE_HEIGHT, TRUE); // 850 width, 600 height
}