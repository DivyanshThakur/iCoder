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
    return std::string(" MAIN ");
}

std::vector<std::string> Main::Menu::selector()
{
    this->menuIndex.clear(); // clear the previous saved index

    if (Global::signedUserID == std::string{"NULL"}) // if singed user is null, run this code
    {
        for (size_t i{0}; i < Constant::Menu::main.size(); i++)
            this->menuIndex.push_back(i + 1);

        return Constant::Menu::main;
    }

    // if a user is signed in then leaving singing options display other options

    // select the correct menu to display as per need
    std::vector<std::string> toDisplayMenu;
    size_t i;

    // Data Structure option is added for signed user to return back to DS screen
    toDisplayMenu.push_back(std::string{"Data Structure"});
    this->menuIndex.push_back(3);

    for (i = 3; i < Constant::Menu::main.size(); ++i) // push back common options
    {
        toDisplayMenu.push_back(Constant::Menu::main.at(i));
        this->menuIndex.push_back(i + 1);
    }

    toDisplayMenu.push_back(std::string{"Sign Out"}); // add sign out option for the user
    this->menuIndex.push_back(i + 1);

    return toDisplayMenu;
}

/**
 * The menuIndex stores the index of the menu options that is currently displayed in the screen
 * fn_caller calls the required function by using below logic
 * Any input less than 1 or greater than the menuIndex size, throws Invalid choice message
 * if the input is between the menuIndex size range, it calculates which function to call
 * Logic - the (input - 1) is passed as the index of menuIndex to get the index of Menu::main
 * Since, the index of Menu::main is stored in menuIndex and thus is passed in menu controller
 * 
 **/

void Main::Menu::caller() const
{
    this->sc >> this->ch;

    if (this->ch > 0 && this->ch <= static_cast<int>(this->menuIndex.size()))
        this->controller();
    else
        print_message(std::string{"Invalid choice"}, true);
}

void Main::Menu::controller() const
{
    switch (this->menuIndex.at(ch - 1))
    {
    case 1: // go to log in screen
        AccountHandler::login();
        break;

    case 2: // go to create account screen
        AccountHandler::create_account();
        break;

    case 3: // login Anonymously / Data Structure
        home();
        break;

    case 4: // open more features screen
        more();
        break;

    case 5:                              // show saved user details
        AccountHandler::display_users(); // fetches user details and display it
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
        sign_out();
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
        Main::Menu myMenu;
        Main::Menu::player(myMenu); // display the startup menu

    } while (1); // The program always run and can only be exited when user presses 'q'
}

void Main::load()
{
    adjust_console_size(); // Adjust the window size
    create_path();         // Initilize the paths

    Settings mySetting;
    FileHandler::load(mySetting); // Restore the settings that was previously changed and saved

    // It is executed for only 1 time after installing the software
    if (showedOneTime) // if the showdOneTime is enabled, it displays below message
    {
        logo();                                                             // Display logo
        emessage(std::string{" HINT --> See HELP section for shortcuts!"}); // Show 1 time message to user
        showedOneTime = false;                                              // Set to false to not show next time

        // save the showHint to file
        mySetting.save(cod::pair<std::string, std::string>(File::SHOW_ONE_TIME_HINT, std::to_string(showedOneTime)));
    }

    if (Global::signedUserID != std::string{"NULL"}) // checking for current signed user
        home();                                      // if the user is saved in file it will automatically sign in the active user
}

void Main::sign_out()
{
    FileHandler::save_active_user(std::string{"NULL"});
    Path::userFilePath.clear();
    welcomeFlag = true;

    AnimeHandler::sign_out();
}

// It creates a path to the user's document folder for storing the user data
void Main::create_path()
{
    char *userpath = getenv("USERPROFILE"); // stores the path to userProfile

    if (userpath == nullptr)
    {
        std::cerr << "No user path";
        return;
    }

    // assigning path to their respective variables
    Path::dataPath = std::string(userpath) + "\\Documents\\iCoder\\";
    Path::fUser = Path::dataPath + "users.dat";
    Path::fSetting = Path::dataPath + "settings.dat";

    if (!check_directory())            // checking if the directory "data" exists or not
        mkdir(Path::dataPath.c_str()); // these code will create a folder in that specific destination
}

bool Main::check_directory()
{
    // code to check if a Directory exists or not
    DWORD attribs = ::GetFileAttributesA(Path::dataPath.c_str());

    if (attribs == INVALID_FILE_ATTRIBUTES)
        return false;

    return (attribs & FILE_ATTRIBUTE_DIRECTORY);
}

void Main::adjust_console_size()
{
    // code to ajust the console size to fix for all the screens
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //stores the console's current dimensions

    MoveWindow(console, r.left, r.top, Ui::consoleWidth, Ui::consoleHeight, TRUE); // 850 width, 600 height
}

void Main::home()
{
    if (welcomeFlag && Global::showWelcome)
    {
        std::string userID = (Global::signedUserID == "NULL") ? "User" : Global::signedUserID;

        welcomeFlag = false;
        logo();                                  // display the logo = iCoder
        emessage("--> Welcome " + userID + "!"); // display the welcome message
        showedOneTime = false;
    }

    data_structure();
}