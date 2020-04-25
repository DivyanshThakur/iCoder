#include <iostream>
#include "../header/DataStructure.hpp"
#include "../header/Array.hpp"
#include "../header/String.hpp"

void data_structure()
{
    cod::scan sc;
    int ch;

    do
    {
        menu(Menu::dataStructure, std::string{" DATA STRUCTURE "}); // display the startup menu

        try
        {
            sc.choice(ch);

            ds_controller(ch); // start as per user choice
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
        catch (const OpenMoreScreen &e)
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
        Arrays();
        break;

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

    default:
        print_message(std::string{"Invalid choice"}, true);
        break;
    }
}