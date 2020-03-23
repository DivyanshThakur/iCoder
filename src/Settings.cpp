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

void show_me_first(const std::string &message, int repeatFor)
{
    title();

    if (showHint) // display hint in every screen
        show_hint();

    header(std::string{" SETTINGS "}, false);

    while (repeatFor--)
    {
        std::cout << message;
        Sleep(600);

        if (repeatFor == 0)
            break;

        size_t i{0};
        while (i < message.size())
        {
            std::cout << "\b \b";
            ++i;
        }

        std::cout << std::endl;
    }
    Sleep(200);

    settings();
}

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
        catch (const OpenHintSetting &e)
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
        press_key();
        return;

    case 2: // change linear search type
        change_lsearch_type();
        press_key();
        return;

    case 3: // welcome message enable/disable
        welcome_message();
        break;

    case 4: // hint message enable/disable
        hint_message();
        break;

    case 5: // reset the settings and delete users
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

    for (size_t i{0}; i < settingsMenu.size(); ++i)
    {

        std::string selector;

        if (i == 2)
            selector = (showWelcome ? std::string{"Disable "} : std::string{"Enable "});
        else if (i == 3)
            selector = (showHint ? std::string{"Disable "} : std::string{"Enable "});

        menu_to_display.push_back(selector + settingsMenu.at(i));
    }

    return menu_to_display;
}

void change_text_anime_speed()
{
    Scanner sc;
    int speed;

    header(std::string{" CHANGE ANIMATION SPEED "});

    show_status(std::string{"Current speed: "}, std::to_string(sleepTime));

    animater(std::string{"Enter the speed: "});

    sc.scan(speed);

    if (speed < 0)
        throw NegativeValueException();

    sleepTime = speed;

    save_to_file(fSetting, std::string{"ANIMATION_SPEED"}, speed);
}

void change_lsearch_type()
{
    Scanner sc;
    int ch;

    do
    {
        menu(lSearchTypeMenu, std::string{" CHANGE LINEAR SEARCH TYPE "}, true, stats_selector(), std::string{"Search Type: "});

        sc.scanChoice(ch);

        switch (ch)
        {
        case 1:
        case 2:
        case 3:
            update_stats(ch - 1);
            save_to_file(fSetting, std::string{"LSEARCH_STATUS"}, stats);
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

    save_to_file(fSetting, std::string{"SHOW_WELCOME_MESSAGE"}, showWelcome);
    print_message(std::string{"Changes saved!"});
}

void hint_message()
{
    if (showHint)
        showHint = false;
    else
        showHint = true;

    save_to_file(fSetting, std::string{"SHOW_HINT"}, showHint);
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
        std::remove(fSetting.c_str());
        std::remove(fUser.c_str());

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
//         std::remove(fUser.c_str());
//         print_message(std::string{"Successfully deleted!"});

//         if (signedUserID != std::string{"NULL"})
//             throw SignOut();
//     }
// }