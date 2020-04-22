#include <iostream>
#include "../header/Home.hpp"
#include "../header/FileHandler.hpp"
#include "../dsa/header/DataStructure.hpp"
#include "../games/header/Games.hpp"
#include "../namespace/header/cod_scan.hpp"

void home(const std::string &userID)
{
    cod::scan sc;
    int ch, flag{1};

    if (flag && Global::showWelcome)
    {
        flag = 0;
        title();                                 // display the title = iCoder
        emessage("--> Welcome " + userID + "!"); // display the welcome message
        showedOneTime = false;
    }

    do
    {
        menu(Menu::home, std::string{" HOME "}); // display the startup menu

        try
        {
            sc.choice(ch);

            home_controller(ch); // start as per user choice
        }
        catch (const EscPressed &e)
        {
            if (Global::signedUserID == std::string{"NULL"})
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
        sign_out();
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