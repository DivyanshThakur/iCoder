#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>
#include "../header/Settings.hpp"
#include "../header/FileHandler.hpp"
#include "../namespace/header/cod_scan.hpp"

// This function initializes the StringHandler class and start it
void settings()
{
    Settings s;
    s.start();
}

/************************************ ISAVEABLE PURE VIRTUAL FUNCTION ****************************************/

std::vector<cod::pair<std::string, std::string>> Settings::save() const
{
    std::vector<cod::pair<std::string, std::string>> vec;
    vec.push_back(pairBuffer);
    return vec;
}

void Settings::load(const std::vector<cod::pair<std::string, std::string>> &vecData)
{
    int c;

    if (generate()) // Create a new file if not created
        return;

    auto pair = vecData.at(0);

    std::stringstream ss(pair.second());

    if (pair.first() == File::CURRENT_USER)
        ss >> Global::signedUserID;
    else if (pair.first() == File::ANIMATION_SPEED)
        ss >> Global::sleepTime;
    else if (pair.first() == File::LSEARCH_STATUS)
    {
        ss >> c;
        FileHandler::update_stats(lSearchStats, c);
    }
    else if (pair.first() == File::SHORTCUT_STATUS)
    {
        ss >> c;
        FileHandler::update_stats(shortcutStats, c);
    }
    else if (pair.first() == File::ANIME_SIGN_OUT_STATUS)
    {
        ss >> c;
        FileHandler::update_stats(animeSignOutStats, c);
    }
    else if (pair.first() == File::SHOW_ONE_TIME_HINT)
        ss >> showedOneTime;
    else if (pair.first() == File::SHOW_WELCOME_MESSAGE)
        ss >> Global::showWelcome;
    else if (pair.first() == File::SHOW_QUIT_MESSAGE)
        ss >> Global::showQuit;
    else if (pair.first() == File::SHOW_HINT)
        ss >> Global::showHint;
}

std::string Settings::filename() const
{
    return Path::fSetting;
}

bool Settings::generate() const
{

    std::ifstream inFile(Path::fSetting);

    if (inFile) // if file already exists returns else create a new file
    {
        inFile.close();
        return false;
    }

    // Assigns default values to unInitialized variables
    Global::signedUserID = std::string{"NULL"};
    Global::sleepTime = 25;
    lSearchStats = DEFAULT;
    shortcutStats = DEFAULT;
    animeSignOutStats = DEFAULT;
    showedOneTime = true;
    Global::showWelcome = true;
    Global::showQuit = true;
    Global::showHint = true;

    // If the settings file doen't exists it prints the above variable to the file for future uses

    std::ofstream outFile(Path::fSetting);

    std::vector<cod::pair<std::string, std::string>> vec;

    FileHandler::print(outFile, cod::pair<std::string, std::string>(File::CURRENT_USER, Global::signedUserID));
    FileHandler::print(outFile, cod::pair<std::string, std::string>(File::ANIMATION_SPEED, std::to_string(Global::sleepTime)));
    FileHandler::print(outFile, cod::pair<std::string, std::string>(File::LSEARCH_STATUS, std::to_string(lSearchStats)));
    FileHandler::print(outFile, cod::pair<std::string, std::string>(File::SHORTCUT_STATUS, std::to_string(shortcutStats)));
    FileHandler::print(outFile, cod::pair<std::string, std::string>(File::ANIME_SIGN_OUT_STATUS, std::to_string(animeSignOutStats)));
    FileHandler::print(outFile, cod::pair<std::string, std::string>(File::SHOW_ONE_TIME_HINT, std::to_string(showedOneTime)));
    FileHandler::print(outFile, cod::pair<std::string, std::string>(File::SHOW_WELCOME_MESSAGE, std::to_string(Global::showWelcome)));
    FileHandler::print(outFile, cod::pair<std::string, std::string>(File::SHOW_QUIT_MESSAGE, std::to_string(Global::showQuit)));
    FileHandler::print(outFile, cod::pair<std::string, std::string>(File::SHOW_HINT, std::to_string(Global::showHint)));

    outFile.close();

    return true;
}

/******************************************* MEMBER FUNCTIONS ***********************************************/

void Settings::start()
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
            return; // returns to last screen
        }
        catch (const InvalidInputException &e)
        {
            e.what();
        }
        catch (const NegativeValueException &e)
        {
            e.what();
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

            e.what();
        }
        catch (const OpenMoreScreen &e)
        {
            if (lstScreen == LAST_MORE)
                return;

            e.what();
        }
        catch (const OpenChangelog &e)
        {
            e.what();
        }

    } while (1); // true
}

bool Settings::isDefault() const
{
    std::string usr_signed;
    int time, c, s, aso;
    bool sothint, wlcome, hint, quit;

    if (this->generate())
        return true;

    auto vec = FileHandler::search_all(*this);

    for (const auto &pair : vec)
    {
        std::stringstream ss(pair.second());

        if (pair.first() == File::CURRENT_USER)
            ss >> usr_signed;
        else if (pair.first() == File::ANIMATION_SPEED)
            ss >> time;
        else if (pair.first() == File::LSEARCH_STATUS)
            ss >> c;
        else if (pair.first() == File::SHORTCUT_STATUS)
            ss >> s;
        else if (pair.first() == File::ANIME_SIGN_OUT_STATUS)
            ss >> aso;
        else if (pair.first() == File::SHOW_ONE_TIME_HINT)
            ss >> sothint;
        else if (pair.first() == File::SHOW_WELCOME_MESSAGE)
            ss >> wlcome;
        else if (pair.first() == File::SHOW_QUIT_MESSAGE)
            ss >> quit;
        else if (pair.first() == File::SHOW_HINT)
            ss >> hint;
    }

    // It checks the default state of settings file by comparing the saved values with the default values
    if (usr_signed == std::string{"NULL"} && time == 25 && !c && !s && !aso && sothint && wlcome && quit && hint)
        return true;

    return false;
}

void Settings::save(const cod::pair<std::string, std::string> &pair)
{
    this->pairBuffer = pair;

    FileHandler::save(*this); // saves the changes to the file
}

void Settings::show_me_first(const std::string &message, int repeatFor)
{
    logo();

    update_screen(std::string{" SETTINGS "});

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

std::string Settings::state_selector(bool isTrue)
{
    return (isTrue ? std::string{"Disable "} : std::string{"Enable "});
}

void Settings::settings_controller(char ch)
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
        return;

    case 5: // change animation style
        change_anime_style();
        break;

    case 6: // change display style
        change_display_style();
        return;

    case 7: // welcome message enable/disable
        welcome_message();
        break;

    case 8: // quit message enable/disable
        quit_message();
        break;

    case 9: // hint message enable/disable
        hint_message();
        break;

    case 10: // reset the settings and delete users
        reset();
        return;

    default:
        print_message(std::string{"Invalid choice"}, true, HOME);
        return;
    }

    ReturnTo temp = ((ch > 6) ? HOME : PRE);
    print_message(std::string{"Changes saved!"}, true, temp);
}

std::vector<std::string> Settings::settings_screen_selector()
{
    // select the correct menu to display as per need

    std::vector<std::string> menu_to_display;

    for (size_t i{0}; i < Menu::settings.size(); ++i)
    {

        std::string selector;

        if (i == 6)
            selector = state_selector(Global::showWelcome);
        else if (i == 7)
            selector = state_selector(Global::showQuit);
        else if (i == 8)
            selector = state_selector(Global::showHint);

        menu_to_display.push_back(selector + Menu::settings.at(i));
    }

    return menu_to_display;
}

void Settings::change_text_anime_speed()
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

    this->save(cod::pair<std::string, std::string>(File::ANIMATION_SPEED, std::to_string(speed)));
}

void Settings::change_lsearch_type()
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
            FileHandler::update_stats(lSearchStats, ch - 1);
            this->save(cod::pair<std::string, std::string>(File::LSEARCH_STATUS, std::to_string(lSearchStats)));

            return;

        default:
            print_message(std::string{"Invalid choice"}, true);
            break;
        }

    } while (1);
}

void Settings::change_shortcuts_type()
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
            FileHandler::update_stats(shortcutStats, ch - 1);
            this->save(cod::pair<std::string, std::string>(File::SHORTCUT_STATUS, std::to_string(shortcutStats)));

            return;

        default:
            print_message(std::string{"Invalid choice"}, true);
            break;
        }

    } while (1);
}

void Settings::change_theme_type()
{
    print_message();
}

void Settings::change_anime_style()
{
    cod::scan sc;
    int ch;

    do
    {
        menu(SmallMenu::animeSignOutStyle, std::string{" CHANGE ANIMATION STYLE "}, true, stats_selector(animeSignOutStats, SmallMenu::animeSignOutStyle), std::string{"Current Animation: "});

        sc.choice(ch);

        switch (ch)
        {
        case 1:
        case 2:
        case 3:
            FileHandler::update_stats(animeSignOutStats, ch - 1);
            this->save(cod::pair<std::string, std::string>(File::ANIME_SIGN_OUT_STATUS, std::to_string(animeSignOutStats)));

            return;

        default:
            print_message(std::string{"Invalid choice"}, true);
            break;
        }

    } while (1);
}

void Settings::change_display_style()
{
    print_message();
}

void Settings::welcome_message()
{
    Global::showWelcome = (!Global::showWelcome); // reverse the state

    this->save(cod::pair<std::string, std::string>(File::SHOW_WELCOME_MESSAGE, std::to_string(Global::showWelcome)));
}

void Settings::quit_message()
{
    Global::showQuit = (!Global::showQuit); // reverse the state

    this->save(cod::pair<std::string, std::string>(File::SHOW_QUIT_MESSAGE, std::to_string(Global::showQuit)));
}

void Settings::hint_message()
{
    Global::showHint = (!Global::showHint); // reverse the state

    this->save(cod::pair<std::string, std::string>(File::SHOW_HINT, std::to_string(Global::showHint)));
}

void Settings::reset()
{
    if (this->isDefault())
    {
        print_message(std::string{"Already in default settings"}, true);
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

        print_message(std::string{"Successfully deleted!"}, true);
        this->generate();
    }
}