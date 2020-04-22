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

    switch (homeStats)
    {
    case DEFAULT:
        home_menu();
        break;

    case DS:
        data_structure();
        break;

    case GAMES:
        games();
        break;

    default:
        break;
    }
}

void home_menu()
{
    cod::scan sc;
    auto menuVec = Menu::home;
    int ch;

    if (homeStats == DEFAULT)
    {
        menuVec.push_back(std::string{"Main Menu (Sign Out)"});
    }

    do
    {
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
                    return;
            }
            else
                return;
        }
        catch (const Exit &e)
        {
            e.what();
        }
        catch (const OpenSettings &e)
        {
            lstScreen = LAST_HOME;
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
            lstScreen = LAST_HOME;
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
        lstScreen = LAST_HOME;
        data_structure();
        return;

    case 2: // games
        lstScreen = LAST_HOME;
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