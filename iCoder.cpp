/*************************************************************************************************************************
 *                                                   ICODER
 * 
 * DEVELOPER - DIVYANSH SINGH THAKUR
 * 
 * VERSION - 1.4
 * 
 * FIRST BETA - 27 DECEMBER, 2019
 * 
 * FIRST STABLE RELEASE - 19 FEBRUARY, 2020
 * 
 * DESCRIPTION :
 * A SMALL PROJECT WITH ALL FEATURES SUCH AS DATA STRUCTURE & ALGORITHM, GAMES AND MUCH MORE...
 * 
 * **********************************************************************************************************************/

#include <iostream>
#include <fstream>
#include <windows.h>
#include <dir.h>
#include "header/ExHandler.hpp"
#include "header/Constants.hpp"
#include "header/UIhandler.hpp"
#include "header/AccountHandler.hpp"
#include "header/Home.hpp"
#include "header/Settings.hpp"
#include "header/Scanner.hpp"
#include "header/Info.hpp"

/** FUNCTION PROTOTYPES **/
void main_menu_controller(int ch);
bool isDirectoryExists();
void adjust_console_size();
void create_path();

int main()
{
    adjust_console_size(); // adjust the window size
    create_path();         // initilize the paths

    restore_saved_changes(); // restore the settings that was previously changed and saved

    if (check_new_user()) // if there is no current user, it displays below message
    {
        title();                                                            // display title
        emessage(std::string{" HINT --> See HELP section for shortcuts!"}); // 1 time message to user
    }

    if (signedUserID != std::string{"NULL"}) // checking for current signed user
        home(signedUserID);                  // if the user is saved in file it will automatically sign in the active user
    else
        save_active_user(std::string{"NULL"}); // if no current user, NULL is passed

    Scanner sc;
    int ch{0};

    do
    {
        title(); // print the title = iCoder

        menu(main_menu_data); // display the startup menu

        try
        {
            sc.scanChoice(ch); // scan user's choice

            main_menu_controller(ch); // start as per user choice
        }
        catch (const EscPressed &e)
        {
            // do nothing
        }
        catch (const Exit &e)
        {
            e.what();
        }
        catch (const OpenSettings &e)
        {
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
        catch (const OpenDownload &e)
        {
            e.what();
        }
        catch (...)
        {
            border(width_menu);
            std::cerr << "Unknown error occurred in Main Menu";
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

    case 3: // login Anonymously
        home(std::string{"User"});
        break;

    case 4: // show saved user details
        display_users();
        press_key(); // getch()
        break;

    case 5: // help for shortcuts
        help();
        break;

    case 6: // details about the software
        about();
        break;

    case 7: // download section to get latest and beta versions
        download();
        break;

    case 8: // Customize the software using settings
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
    DWORD attribs = ::GetFileAttributesA(path.c_str());

    if (attribs == INVALID_FILE_ATTRIBUTES)
        return false;

    return (attribs & FILE_ATTRIBUTE_DIRECTORY);
}

void adjust_console_size()
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //stores the console's current dimensions

    MoveWindow(console, r.left, r.top, console_width, console_height, TRUE); // 850 width, 600 height
}

void create_path()
{
    char *userpath = getenv("USERPROFILE");

    if (userpath == nullptr)
    {
        std::cerr << "No user path";
        return;
    }

    path = std::string(userpath) + "\\Documents\\iCoder";
    fuser = path + "\\users.dat";
    fsetting = path + "\\settings.dat";

    if (!isDirectoryExists()) // checking if the directory "data" exists or not
        mkdir(path.c_str());  // these code will create a folder in that specific destination
}