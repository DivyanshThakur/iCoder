/***********************************************************************************************************************
 *                                                   ICODER
 * 
 * DEVELOPER - DIVYANSH SINGH THAKUR
 * 
 * VERSION - 1.9.20.4.23-BETA
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
#include <fstream>
#include <windows.h>
#include <dir.h>
#include "header/Home.hpp"
#include "header/Help.hpp"
#include "header/Settings.hpp"
#include "header/FileHandler.hpp"
#include "header/AccountHandler.hpp"
#include "namespace/header/cod_scan.hpp"

/************************************************ FUNCTION PROTOTYPES **************************************************/
void main_menu_controller(int ch);
bool isDirectoryExists();
void adjust_console_size();
void create_path();

int main()
{
    adjust_console_size(); // Adjust the window size
    create_path();         // Initilize the paths

    restore_saved_changes(); // Restore the settings that was previously changed and saved

    // It is executed for only 1 time after installing the software
    if (showedOneTime) // if the showdOneTime is enabled, it displays below message
    {
        title();                                                               // Display title
        emessage(std::string{" HINT --> See HELP section for shortcuts!"});    // Show 1 time message to user
        showedOneTime = false;                                                 // Set to false to not show next time
        save_to_file(Path::fSetting, File::SHOW_ONE_TIME_HINT, showedOneTime); // saves the changes to the file
    }

    // Here, it is checking for the current logged user and if true,it will automatically log in
    try
    {
        if (Global::signedUserID != std::string{"NULL"}) // checking for current signed user
            home(Global::signedUserID);                  // if the user is saved in file it will automatically sign in the active user
        else
            save_active_user(std::string{"NULL"}); // if no current user, NULL is passed
    }
    catch (const ReturnMain &e)
    {
        // The ReturnMain exception thrown from any part of program comes here
    }

    cod::scan sc;
    int ch;

    do
    {
        menu(Menu::main); // display the startup menu

        try
        {
            sc.choice(ch); // scan user's choice

            main_menu_controller(ch); // start as per user choice
        }
        catch (const EscPressed &e)
        {
            // do nothing
        }
        catch (const ReturnMain &e)
        {
            // The ReturnMain exception thrown from any part of program comes here
        }
        catch (const Exit &e)
        {
            e.what(); // call exit function
        }
        catch (const OpenSettings &e)
        {
            e.what();
        }
        catch (const OpenAbout &e)
        {
            e.what(); // open about screen
        }
        catch (const OpenHelp &e)
        {
            e.what(); // open help screen
        }
        catch (const OpenUpdate &e)
        {
            e.what();
        }
        catch (const OpenChangelog &e)
        {
            e.what(); // open changelog
        }
        catch (const OpenHomeScreen &e)
        {
            e.what(); // open home screen
        }
        catch (const OpenAnimeSetting &e)
        {
            e.what(); // open settings with animation
        }
        catch (...)
        {
            border(Ui::widthMenu);
            std::cerr << "Main Menu-Unknown error occurred";
            press_key(NIL);
        }

    } while (1); // The program always run and can only be exited when user presses 'q'

    return 0;
}

void main_menu_controller(int ch)
{
    switch (ch)
    {
    case 1: // go to log in screen
        login();
        break;

    case 2: // go to create account screen
        create_account();
        break;

    case 3: // login Anonymously
        home(std::string{"User"});
        break;

    case 4:              // show saved user details
        display_users(); // fetches user details and display it
        press_key();     // getch()
        break;

    case 5: // help for shortcuts
        help();
        break;

    case 6: // details about the software
        about();
        break;

    case 7: // changelog
        changelog();
        break;

    case 8: // update section to get latest and beta versions
        update();
        break;

    case 9: // Customize the software using settings
        settings();
        break;

    default:
        print_message(std::string{"Invalid choice"}, true); // print given message with press_key() function
        break;
    }
}

bool isDirectoryExists()
{
    // code to check if a Directory exists or not
    DWORD attribs = ::GetFileAttributesA(Path::dataPath.c_str());

    if (attribs == INVALID_FILE_ATTRIBUTES)
        return false;

    return (attribs & FILE_ATTRIBUTE_DIRECTORY);
}

void adjust_console_size()
{
    // code to ajust the console size to fix for all the screens
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //stores the console's current dimensions

    MoveWindow(console, r.left, r.top, Ui::consoleWidth, Ui::consoleHeight, TRUE); // 850 width, 600 height
}

// It creates a path to the user's document folder for storing the user data
void create_path()
{
    char *userpath = getenv("USERPROFILE"); // stores the path to userProfile

    if (userpath == nullptr)
    {
        std::cerr << "No user path";
        return;
    }

    // assigning path to their respective variables
    Path::dataPath = std::string(userpath) + "\\Documents\\iCoder";
    Path::fUser = Path::dataPath + "\\users.dat";
    Path::fSetting = Path::dataPath + "\\settings.dat";

    if (!isDirectoryExists())          // checking if the directory "data" exists or not
        mkdir(Path::dataPath.c_str()); // these code will create a folder in that specific destination
}