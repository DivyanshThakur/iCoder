#include <iostream>
#include <vector>
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
    int ch;
    do
    {
        menu(settings_screen_selector(), std::string{" SETTINGS "}); // display the startup menu for settings screen

        try
        {

            try
            {
                sc.scanChoice(ch);
            }
            catch (const EscPressed &e)
            {
                return;
            }

            settings_controller(ch); // start as per user choice
        }
        catch (const EscPressed &e)
        {
            // do nothing, already returned to previous screen
        }
        catch (const ReturnHome &e)
        {
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
            // do nothing
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

    } while (1); // true
}

void settings_controller(char ch)
{

    switch (ch)
    {
    case 1: // change the animation speed of the menu
        change_text_anime_speed();
        press_key();
        return;

    case 2: // change linear search type
        change_lsearch_type();
        press_key();
        return;

    case 3: // welcome message enable/disable
        welcome_message();
        break;

    case 4: // reset the settings and delete users
        reset();
        break;

    default:
        print_message(std::string{"Invalid choice"});
        break;
    }

    press_key(HOME);
}

std::vector<std::string> settings_screen_selector()
{
    // select the correct menu to display as per need

    std::vector<std::string> menu_to_display;

    for (size_t i{0}; i < settings_data.size(); ++i)
    {

        if (i == 2 && showWelcome)
            menu_to_display.push_back(settings_data.at(++i));
        else if (i == 3 && !showWelcome)
            menu_to_display.push_back(settings_data.at(++i));
        else
            menu_to_display.push_back(settings_data.at(i));
    }

    return menu_to_display;
}

void change_text_anime_speed()
{
    Scanner sc;
    int speed;

    header(std::string{" CHANGE ANIMATION SPEED "});

    show_status(std::string{"Current speed: "}, std::to_string(sleep_time));

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
        menu(lsearch_data, std::string{" CHANGE LINEAR SEARCH TYPE "}, true, stats_selector(), std::string{"Search Type: "});

        sc.scanChoice(ch);

        switch (ch)
        {
        case 1:
        case 2:
        case 3:
            update_stats(ch - 1);
            save_to_file(fsetting, std::string{"LSEARCH_STATUS"}, stats);
            return;

        default:
            print_message(std::string{"Invalid choice"});
            press_key();
            break;
        }
    } while (1);
}

void welcome_message()
{
    if (showWelcome)
        showWelcome = false;
    else
        showWelcome = true;
    save_to_file(fsetting, std::string{"SHOW_WELCOME_MESSAGE"}, showWelcome);
    print_message(std::string{"Changes saved!"});
}

void reset()
{
    if (check_new_user() && check_default_settings())
    {
        print_message(std::string{"Already in default settings"});
        return;
    }

    bool toProceed = confirm_the_change(std::string{"This will reset all the settings\nand delete all the user details!"});

    if (toProceed)
    {
        std::remove(fsetting.c_str());
        std::remove(fuser.c_str());

        if (signedUserID != std::string{"NULL"})
        {
            header(std::string{" SETTINGS "});

            std::cout << "To successfully reset the change\nClosing iCoder...";
            press_key(NIL);
            exit(0);
        }

        print_message(std::string{"Successfully deleted!"});
        restore_saved_changes();
    }
}

// void delete_account()
// {

//     if (check_new_user())
//     {
//         print_message(std::string{"No user in database!"});
//         return;
//     }

//     bool toProceed = confirm_the_change(std::string{"This will permanently delete all\nthe user info from the database!"});
//     if (toProceed)
//     {
//         std::remove(fuser.c_str());
//         print_message(std::string{"Successfully deleted!"});

//         if (signedUserID != std::string{"NULL"})
//             throw SignOut();
//     }
// }