/***********************************************************************************************************************
 *                                                   ICODER
 * 
 * DEVELOPER - DIVYANSH SINGH THAKUR
 * 
 * VERSION - 1.8
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
#include "namespace/header/cod_scan.hpp"
#include "header/ExHandler.hpp"
#include "header/Constants.hpp"
#include "header/UIhandler.hpp"
#include "header/AccountHandler.hpp"
#include "header/Home.hpp"
#include "header/Settings.hpp"
#include "header/Info.hpp"

/************************************************ FUNCTION PROTOTYPES **************************************************/
void main_menu_controller(int ch);
bool isDirectoryExists();
void adjust_console_size();
void create_path();

int main()
{
    adjust_console_size(); // adjust the window size
    create_path();         // initilize the paths

    restore_saved_changes(); // restore the settings that was previously changed and saved

    if (showedOneTime) // if there is no current user & showWelcome enabled, it displays below message
    {
        title();                                                            // display title
        emessage(std::string{" HINT --> See HELP section for shortcuts!"}); // 1 time message to user
        showedOneTime = false;                                              // set to false to not show next time
        save_to_file(Path::fSetting, File::SHOW_ONE_TIME_HINT, showedOneTime);
    }

    if (Global::signedUserID != std::string{"NULL"}) // checking for current signed user
        home(Global::signedUserID);                  // if the user is saved in file it will automatically sign in the active user
    else
        save_active_user(std::string{"NULL"}); // if no current user, NULL is passed

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
        catch (const ReturnHome &e)
        {
            // do nothing
        }
        catch (const Exit &e)
        {
            e.what();
        }
        catch (const OpenSettings &e)
        {
            lstScreen = LAST_MENU; // set the last screen visited as main menu to avoid infinite switching
            e.what();
        }
        catch (const OpenAbout &e)
        {
            e.what();
        }
        catch (const OpenHelp &e)
        {
            e.what();
        }
        catch (const OpenUpdate &e)
        {
            lstScreen = LAST_MENU;
            e.what();
        }
        catch (const OpenChangelog &e)
        {
            e.what();
        }
        catch (const OpenAnimeSetting &e)
        {
            e.what();
        }
        catch (...)
        {
            border(Ui::widthMenu);
            std::cerr << "Unknown error occurred in Main Menu";
            press_key(NIL);
        }

    } while (1); // the program terminates after this line

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

    case 3:                    // login Anonymously
        lstScreen = LAST_MENU; // sets the last screen as main menu
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
        print_message(std::string{"Invalid choice"});
        press_key(); // getch()
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