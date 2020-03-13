#include <iostream>
#include <memory>
#include "../header/ExHandler.hpp"
#include "../header/Home.hpp"
#include "../header/Constants.hpp"
#include "../header/UIhandler.hpp"
#include "../header/AccountHandler.hpp"
#include "../header/Array.hpp"
#include "../header/Scanner.hpp"
#include "../namespace/header/cod_array.hpp"

void home(const std::string &userID)
{
    Scanner sc;
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

        menu(home_data); // display the startup menu

        try
        {
            sc.scanChoice(ch);

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
        }
        catch (const NegativeValueException &e)
        {
            std::cerr << e.what();
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

    } while (1); // exit the program when ch == 8
}

void home_controller(int ch)
{
    switch (ch)
    {
    case 1: // arrays
        Arrays();
        return;

    case 2:              // strings
        print_message(); // default is ~ to be Implemented
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
        if (signedUserID != std::string{"NULL"})
            save_active_user(std::string{"NULL"});
        throw EscPressed();

    default:
        print_message(std::string{"Invalid choice"});
        break;
    }

    press_key(); // program paused - getch()
}