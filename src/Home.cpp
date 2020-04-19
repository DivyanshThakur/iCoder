#include <iostream>
#include "../header/ExHandler.hpp"
#include "../header/Home.hpp"
#include "../header/Constants.hpp"
#include "../header/UIhandler.hpp"
#include "../header/AccountHandler.hpp"
#include "../header/Array.hpp"
#include "../header/String.hpp"
#include "../namespace/header/cod_scan.hpp"

void home(const std::string &userID)
{
    cod::scan sc;
    int ch;
    int flag{1};

    do
    {
        if (flag && Global::showWelcome)
        {
            flag = 0;
            title();                                 // display the title = iCoder
            emessage("--> Welcome " + userID + "!"); // display the welcome message
            showedOneTime = false;
        }

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
        catch (const ReturnHome &e)
        {
            // to return to home screen
        }

    } while (1); // always true
}

void home_controller(int ch)
{
    switch (ch)
    {
    case 1: // arrays
        lstScreen = LAST_HOME;
        Arrays();
        return;

    case 2: // strings
        lstScreen = LAST_HOME;
        String();
        break;

    case 3: // matrices
        print_message();
        break;

    case 4: // sparse matrix
        print_message();
        break;

    case 5: // polynomial representation
        print_message();
        break;

    case 6: // linked list
        print_message();
        break;

    case 7: // sign out
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