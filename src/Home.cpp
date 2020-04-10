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
        if (flag && showWelcome)
        {
            flag = 0;
            title();                                 // display the title = iCoder
            emessage("--> Welcome " + userID + "!"); // display the welcome message
            showedOneTime = false;
        }

        menu(homeMenu); // display the startup menu

        try
        {
            sc.choice(ch);

            home_controller(ch); // start as per user choice
        }
        catch (const EscPressed &e)
        {
            if (signedUserID == std::string{"NULL"})
                return;
        }
        catch (const InvalidInputException &e)
        {
            std::cerr << e.what();
            press_key(NIL);
        }
        catch (const NegativeValueException &e)
        {
            std::cerr << e.what();
            press_key(NIL);
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
        catch (const ReturnHome &e)
        {
            // to return to home screen
        }

    } while (1); // exit the program when ch == 8
}

void home_controller(int ch)
{
    switch (ch)
    {
    case 1: // arrays
        Arrays();
        return;

    case 2: // strings
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
    if (signedUserID != std::string{"NULL"})
        save_active_user(std::string{"NULL"});
    throw EscPressed();
}