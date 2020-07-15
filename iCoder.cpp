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
#include "header/Help.hpp"
#include "header/Settings.hpp"
#include "header/FileHandler.hpp"
#include "header/AccountHandler.hpp"
#include "dsa/header/DataStructure.hpp"
#include "namespace/header/cod_scan.hpp"
#include "animation/header/AnimeHandler.hpp"

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
    std::vector<std::string> vec;
    vec.emplace_back(Constant::Title::STATS);

    if (Global::activeUser != Constant::NULL_STR)
        vec.emplace_back("User:    " + Global::activeUser);

    vec.emplace_back("Version: " + Constant::iCoder::VERSION);

    return vec;
}

std::vector<std::string> Main::Menu::selector()
{
    menuIndex.clear(); // clear the previous saved index

    if (Global::activeUser == Constant::NULL_STR) // if active user is null, run this code
    {
        for (size_t i{0}; i < Constant::Menu::MAIN.size(); i++)
            menuIndex.push_back(i + 1);

        return Constant::Menu::MAIN;
    }

    // if a user is signed in then leaving singing options display other options

    // select the correct menu to display as per need
    std::vector<std::string> toDisplayMenu;
    size_t i;

    // Data Structure option is added for signed user to return back to DS screen
    toDisplayMenu.push_back(std::string{"Data Structure"});
    menuIndex.push_back(3);

    for (i = 3; i < Constant::Menu::MAIN.size(); ++i) // push back common options
    {
        toDisplayMenu.push_back(Constant::Menu::MAIN.at(i));
        menuIndex.push_back(i + 1);
    }

    toDisplayMenu.push_back(std::string{"Sign Out"}); // add sign out option for the user
    menuIndex.push_back(i + 1);

    return toDisplayMenu;
}

/**
 * The menuIndex stores the index of the menu options that is currently displayed in the screen
 * fn_caller calls the required function by using below logic
 * Any input less than 1 or greater than the menuIndex size, throws Invalid choice message
 * if the input is between the menuIndex size range, it calculates which function to call
 * Logic - the (input - 1) is passed as the index of menuIndex to get the index of Menu::main
 * Since, the index of Menu::main is stored in menuIndex and thus is passed in menu controller
 **/

void Main::Menu::caller() const
{
    scan >> ch;

    if (ch > 0 && ch <= static_cast<int>(menuIndex.size()))
        controller();
    else
        Ui::println(std::string{"Invalid choice"});
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
        more();
        break;

    case 5:                          // show saved user details
        AccountHandler::showUsers(); // fetches user details and display it
        break;

    case 6: // help for shortcuts
        help();
        break;

    case 7: // details about the software
        about();
        break;

    case 8: // changelog
        changelog();
        break;

    case 9: // update section to get latest and beta versions
        update();
        break;

    case 10: // Customize the software using settings
        settings();
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

    do
    {
        Main::Menu::player(Main::Menu()); // display the startup menu

    } while (1);
}

void Main::load()
{
    adjustConsoleSize(); // Adjust the window size
    createPath();        // Initialize the paths

    Settings mySetting;
    FileHandler::load(mySetting); // Restore the settings that was previously changed and saved

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

    // data_structure();
}

void Main::signOut()
{
    FileHandler::saveActiveUser(Constant::NULL_STR);
    Constant::Path::USER.clear();
    welcomeFlag = true;

    AnimeHandler::sign_out();
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