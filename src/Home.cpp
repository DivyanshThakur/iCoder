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

    data_structure();
}

void more()
{
    cod::scan sc;
    int ch;

    do
    {
        menu(Menu::more, std::string{" MORE "}); // display the startup menu

        try
        {
            sc.choice(ch);

            more_controller(ch); // start as per user choice
        }
        catch (const EscPressed &e)
        {
            return;
        }
        catch (const Exit &e)
        {
            e.what();
        }
        catch (const OpenSettings &e)
        {
            if (lstScreen == LAST_SETTINGS)
                return;

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
            if (lstScreen == LAST_UPDATES)
                return;

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

void more_controller(int ch)
{
    switch (ch)
    {
    case 1: // games
        games();
        break;

    default:
        print_message(std::string{"Invalid choice"}, true);
        break;
    }
}