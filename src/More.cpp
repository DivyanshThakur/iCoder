#include "../header/More.hpp"
#include "../games/header/Games.hpp"
#include "../namespace/header/cod_scan.hpp"

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
        catch (const OpenMoreScreen &e)
        {
            // do nothing
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