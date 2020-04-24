#include <iostream>
#include "../header/Home.hpp"
#include "../header/FileHandler.hpp"
#include "../dsa/header/DataStructure.hpp"
#include "../games/header/Games.hpp"
#include "../namespace/header/cod_scan.hpp"

void home(const std::string &userID)
{
    int flag{1};

    if (flag && Global::showWelcome)
    {
        flag = 0;
        title();                                 // display the title = iCoder
        emessage("--> Welcome " + userID + "!"); // display the welcome message
        showedOneTime = false;
    }

    do
    {
        try
        {
            switch (homeStats)
            {
            case DEFAULT:
                home_menu();
                return;

            case DS:
                data_structure();
                return;

            case GAMES:
                games();
                return;

            default:
                return;
            }
        }
        catch (const OpenDefScreen &e)
        {
            // do nothing
        }

    } while (1); // true
}

void home_menu()
{
    cod::scan sc;
    int ch;

    do
    {
        auto menuVec = Menu::home;

        if (homeStats == DEFAULT)
        {
            menuVec.push_back(std::string{"Main Menu (Sign Out)"});
        }

        menu(menuVec, std::string{" HOME "}, true, stats_selector(homeStats, SmallMenu::homeScreenType), std::string{"Opening Screen: "}); // display the startup menu

        try
        {
            sc.choice(ch);

            home_controller(ch); // start as per user choice
        }
        catch (const EscPressed &e)
        {
            if (homeStats == DEFAULT)
            {
                if (Global::signedUserID == std::string{"NULL"})
                    throw ReturnMain();
            }
            else
                throw OpenDefScreen();
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
        catch (const OpenUpdate &e)
        {
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

    } while (1); // always true
}

void home_controller(int ch)
{
    switch (ch)
    {
    case 1: // data structure
        data_structure();
        break;

    case 2: // games
        games();
        break;

    case 3: // sign out
        (homeStats == DEFAULT) ? sign_out() : print_message(std::string{"Invalid choice"});
        break;

    default:
        print_message(std::string{"Invalid choice"});
        break;
    }

    press_key(); // program paused - getch()
}

void sign_out()
{
    if (Global::signedUserID != std::string{"NULL"})
        save_active_user(std::string{"NULL"});

    throw EscPressed();
}