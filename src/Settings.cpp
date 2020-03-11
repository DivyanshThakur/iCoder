#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include "../header/Settings.hpp"
#include "../header/AccountHandler.hpp"
#include "../header/Constants.hpp"
#include "../header/ExHandler.hpp"
#include "../header/UIhandler.hpp"
#include "../header/Scanner.hpp"

void settings()
{
    Scanner sc;
    int ch{0};
    do
    {
        title(); // print the title = iCoder

        menu(settings_data, std::string{" SETTINGS "}); // display the startup menu for settings screen

        try
        {
            sc.scanChoice(ch);
        }
        catch (const EscPressed &e)
        {
            return;
        }
        catch (const OpenSettings &e)
        {
            continue;
        }
        catch (const Exit &e)
        {
            e.what();
        }

        try
        {
            settings_controller(ch); // start as per user choice
        }
        catch (const EscPressed &e)
        {
            // do nothing, already returned to previous screen
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
            // do nothing
        }

    } while (1); // true
}

void settings_controller(char ch)
{

    switch (ch)
    {
    case 1: // change the animation speed of the menu
        change_text_anime_speed();
        break;

    case 2: // change linear search type
        change_lsearch_type();
        save_to_file(fsetting, std::string{"LSEARCH_STATUS"}, stats);
        break;

    default:
        print_message(std::string{"Invalid choice"});
        break;
    }

    press_key(); // getch()
}

void change_text_anime_speed()
{
    int speed;
    Scanner sc;

    title(); // print the title = iCoder

    header(std::string{" CHANGE ANIMATION SPEED "});

    animater(std::string{"Enter the speed: "});

    sc.scan(speed);

    if (speed < 0)
        throw NegativeValueException();

    sleep_time = speed;

    save_to_file(fsetting, std::string{"ANIMATION_SPEED"}, speed);
}

void change_lsearch_type()
{
    Scanner sc;
    int ch;

    do
    {
        title(); // print the title = iCoder

        menu(lsearch_data, std::string{" CHANGE LINEAR SEARCH TYPE "});

        sc.scanChoice(ch);

        switch (ch)
        {
        case 1:
        case 2:
        case 3:
            update_stats(ch - 1);
            return;

        default:
            print_message(std::string{"Invalid choice"});
            press_esc();
            break;
        }
    } while (1);
}