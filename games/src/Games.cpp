#include <iostream>
#include "../header/Games.hpp"
#include "../header/TicTacToe.hpp"
#include "../../header/Home.hpp"
#include "../../namespace/header/cod_scan.hpp"

void games()
{
    cod::scan sc;
    int ch;

    do
    {
        auto menuVec = Menu::games;

        if (homeStats == GAMES)
        {
            menuVec.push_back(std::string{"Main Menu (Sign Out)"});
        }

        menu(menuVec, std::string{" GAMES "}); // display the startup menu

        try
        {
            sc.choice(ch);

            game_controller(ch); // start as per user choice
        }
        catch (const EscPressed &e)
        {
            if (homeStats == GAMES)
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
            lstScreen = LAST_GAMES;
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
            lstScreen = LAST_GAMES;
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

void game_controller(int ch)
{

    switch (ch)
    {
    case 1: // data structure
        lstScreen = LAST_GAMES;
        tic_tac_toe();
        break;

    case 2: // sign out
        (homeStats == GAMES) ? sign_out() : print_message(std::string{"Invalid choice"});
        break;

    default:
        print_message(std::string{"Invalid choice"});
        break;
    }

    press_key(); // program paused - getch()
}