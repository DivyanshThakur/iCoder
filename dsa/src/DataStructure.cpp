#include <iostream>
#include "../header/DataStructure.hpp"
#include "../../header/Home.hpp"
#include "../../header/FileHandler.hpp"
#include "../header/Array.hpp"
#include "../header/String.hpp"

void data_structure()
{
    cod::scan sc;
    int ch;

    do
    {
        auto menuVec = Menu::dataStructure;

        if (homeStats == DS)
        {
            menuVec.push_back(std::string{"Main Menu (Sign Out)"});
        }

        menu(menuVec, std::string{" DATA STRUCTURE "}); // display the startup menu

        try
        {
            sc.choice(ch);

            ds_controller(ch); // start as per user choice
        }
        catch (const EscPressed &e)
        {
            if (homeStats == DS)
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
            lstScreen = LAST_DS;
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
            lstScreen = LAST_DS;
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
            // to return to data structure screen
        }

    } while (1); // always true
}

void ds_controller(int ch)
{
    switch (ch)
    {
    case 1: // arrays
        lstScreen = LAST_DS;
        Arrays();
        return;

    case 2: // strings
        lstScreen = LAST_DS;
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

    case 7:
        (homeStats == DS) ? sign_out() : print_message(std::string{"Invalid choice"});
        break;

    default:
        print_message(std::string{"Invalid choice"});
        break;
    }

    press_key(); // program paused - getch()
}