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
    int ch{0};
    do
    {
        system("cls"); // clear the screen each time

        title(); // print the title = iCoder

        menu(settings_data, std::string{" SETTINGS "}); // display the startup menu for settings screen

        Scanner sc;
        sc.scanChoice(ch);

        if (ch == ESC || ch == 2) //return when ESC is pressed
            return;

        settings_controller(ch); // start as per user choice

    } while (ch != 3);
    exit(0);
}

void settings_controller(char ch)
{

    switch (ch)
    {
    case 1: // change the animation speed of the menu
        change_text_anime_speed();
        return;

    case 3: //exit
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

    system("cls"); // clear the screen each time

    title(); // print the title = iCoder

    header(std::string{" CHANGE ANIMATION SPEED "});

    std::cout << "Enter the speed: ";

    try
    {
        sc.scan(speed);

        if (speed < 0)
            throw NegativeValueException();

        sleep_time = speed;

        save_to_file(fsetting, std::string{"ANIMATION_SPEED"}, speed);
    }
    catch (const EscPressed &e)
    {
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

    press_key();
}