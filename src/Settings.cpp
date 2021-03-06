#include <iostream>
#include <vector>
#include <sstream>
#include <windows.h>
#include "../header/Settings.hpp"
#include "../header/AccountHandler.hpp"
#include "../header/Constants.hpp"
#include "../header/ExHandler.hpp"
#include "../header/UIhandler.hpp"
#include "../namespace/header/cod_scan.hpp"

void show_me_first(const std::string &message, int repeatFor)
{
    title();

    if (Global::showHint) // display hint in every screen
        show_hint();

    header(std::string{" SETTINGS "}, false);

    while (repeatFor--)
    {
        std::cout << message;
        Sleep(250);

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

    Sleep(300);
    settings();
}

std::string state_selector(bool isTrue)
{
    return (isTrue ? std::string{"Disable "} : std::string{"Enable "});
}

void settings()
{
    cod::scan sc;
    int ch;
    do
    {
        menu(settings_screen_selector(), std::string{" SETTINGS "}); // display the startup menu for settings screen

        try
        {

            try
            {
                sc.choice(ch);
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

            if (lstScreen == LAST_UPDATES)
                return;

            lstScreen = LAST_SETTINGS;
            e.what();
        }
        catch (const OpenChangelog &e)
        {
            e.what();
        }
        catch (const OpenAnimeSetting &e)
        {
            try
            {
                if (Global::showHint)
                    settings_controller(8); // disable hint
            }
            catch (const EscPressed &e)
            {
                // do nothing
            }
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
        break;

    case 3: // change shortcuts access type
        change_shortcuts_type();
        break;

    case 4: // change theme type
        change_theme_type();
        press_key(HOME);
        return;

    case 5: // change display style
        change_display_style();
        press_key(HOME);
        return;

    case 6: // welcome message enable/disable
        welcome_message();
        break;

    case 7: // quit message enable/disable
        quit_message();
        break;

    case 8: // hint message enable/disable
        hint_message();
        break;

    case 9: // reset the settings and delete users
        reset();
        return;

    default:
        print_message(std::string{"Invalid choice"});
        press_key(HOME);
        return;
    }

    print_message(std::string{"Changes saved!"});
    press_key();
}

std::vector<std::string> settings_screen_selector()
{
    // select the correct menu to display as per need

    std::vector<std::string> menu_to_display;

    for (size_t i{0}; i < Menu::settings.size(); ++i)
    {

        std::string selector;

        if (i == 5)
            selector = state_selector(Global::showWelcome);
        else if (i == 6)
            selector = state_selector(Global::showQuit);
        else if (i == 7)
            selector = state_selector(Global::showHint);

        menu_to_display.push_back(selector + Menu::settings.at(i));
    }

    return menu_to_display;
}

void change_text_anime_speed()
{
    cod::scan sc;
    int speed;

    header(std::string{" CHANGE ANIMATION SPEED "});

    show_status(std::string{"Current speed: "}, std::to_string(Global::sleepTime));

    animater(std::string{"Enter the speed: "});

    sc >> speed;

    if (speed < 0)
        throw NegativeValueException();

    Global::sleepTime = speed;

    save_to_file(Path::fSetting, File::ANIMATION_SPEED, speed);
}

void change_lsearch_type()
{
    cod::scan sc;
    int ch;

    do
    {
        menu(SmallMenu::lSearchType, std::string{" CHANGE LINEAR SEARCH TYPE "}, true, stats_selector(lSearchStats, SmallMenu::lSearchType), std::string{"Current Type: "});

        sc.choice(ch);

        switch (ch)
        {
        case 1:
        case 2:
        case 3:
            update_stats(lSearchStats, ch - 1);
            save_to_file(Path::fSetting, File::LSEARCH_STATUS, lSearchStats);
            return;

        default:
            print_message(std::string{"Invalid choice"});
            press_key();
            break;
        }
    } while (1);
}

void change_shortcuts_type()
{
    cod::scan sc;
    int ch;

    do
    {
        menu(SmallMenu::shortcutsType, std::string{" CHANGE SHORTCUT ACCESS "}, true, stats_selector(shortcutStats, SmallMenu::shortcutsType), std::string{"Current Type: "});

        sc.choice(ch);

        switch (ch)
        {
        case 1:
        case 2:
        case 3:
            update_stats(shortcutStats, ch - 1);
            save_to_file(Path::fSetting, File::SHORTCUT_STATUS, shortcutStats);
            return;

        default:
            print_message(std::string{"Invalid choice"});
            press_key();
            break;
        }
    } while (1);
}

void change_theme_type()
{
    print_message();

    // cod::scan sc;
    // int ch;

    // do
    // {
    //     menu(lSearchTypeMenu, std::string{" CHANGE LINEAR SEARCH TYPE "}, true, stats_selector(lSearchStats, lSearchTypeMenu), std::string{"Search Type: "});

    //     sc.choice(ch);

    //     switch (ch)
    //     {
    //     case 1:
    //     case 2:
    //     case 3:
    //         update_stats(lSearchStats, ch - 1);
    //         save_to_file(fSetting, std::string{"LSEARCH_STATUS"}, lSearchStats);
    //         return;

    //     default:
    //         print_message(std::string{"Invalid choice"});
    //         press_key();
    //         break;
    //     }
    // } while (1);
}

void change_display_style()
{
    print_message();

    // cod::scan sc;
    // int ch;

    // do
    // {
    //     menu(lSearchTypeMenu, std::string{" CHANGE LINEAR SEARCH TYPE "}, true, stats_selector(lSearchStats, lSearchTypeMenu), std::string{"Search Type: "});

    //     sc.choice(ch);

    //     switch (ch)
    //     {
    //     case 1:
    //     case 2:
    //     case 3:
    //         update_stats(lSearchStats, ch - 1);
    //         save_to_file(fSetting, std::string{"LSEARCH_STATUS"}, lSearchStats);
    //         return;

    //     default:
    //         print_message(std::string{"Invalid choice"});
    //         press_key();
    //         break;
    //     }
    // } while (1);
}

void welcome_message()
{
    Global::showWelcome = (!Global::showWelcome); // reverse the state

    save_to_file(Path::fSetting, File::SHOW_WELCOME_MESSAGE, Global::showWelcome);
}

void quit_message()
{
    Global::showQuit = (!Global::showQuit); // reverse the state

    save_to_file(Path::fSetting, File::SHOW_QUIT_MESSAGE, Global::showQuit);
}

void hint_message()
{
    Global::showHint = (!Global::showHint); // reverse the state

    save_to_file(Path::fSetting, File::SHOW_HINT, Global::showHint);
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
        std::remove(Path::fSetting.c_str());
        std::remove(Path::fUser.c_str());

        if (Global::signedUserID != std::string{"NULL"})
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