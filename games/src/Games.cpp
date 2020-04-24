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
        menu(Menu::games, std::string{" GAMES "}); // display the startup menu

        try
        {
            sc.choice(ch);

            game_controller(ch); // start as per user choice
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
        catch (const OpenMoreScreen &e)
        {
            return;
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
    case 1: // tic tac toe
        tic_tac_toe();
        break;

    default:
        print_message(std::string{"Invalid choice"}, true);
        break;
    }
}