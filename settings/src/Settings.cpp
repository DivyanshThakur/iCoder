#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <windows.h>
#include "../header/Settings.hpp"
#include "../header/Hint.hpp"
#include "../../main/header/File.hpp"
#include "../../constant/Constants.hpp"
#include "../../namespace/header/cod_scan.hpp"

Settings::Data Settings::userData;

/**************************************************************************************************************
 * 
 *                                           AbstractMenu IMPLEMENTATIONS
 * 
 * ***********************************************************************************************************/

std::string Settings::Menu::title() const
{
    return std::string(Constant::Title::SETTINGS);
}

std::vector<std::string> Settings::Menu::getStats() const
{
    Ui::subHeader(Constant::Title::TIP);

    std::vector<std::string> vec;
    vec.emplace_back(Ui::getTip());
    return vec;
}

std::vector<std::string> Settings::Menu::selector()
{
    menuIndexer(Constant::Menu::SETTINGS.size());
    return Constant::Menu::SETTINGS;
}

void Settings::Menu::controller() const
{
    switch (menuIndex.at(ch - 1))
    {
    case 2:
        Hint::start();
        break;
        // case 1: // change the animation speed of the menu
        //     change_text_anime_speed();
        //     break;

        // case 2: // change linear search type
        //     change_lsearch_type();
        //     break;

        // case 3: // change shortcuts access type
        //     change_shortcuts_type();
        //     break;

        // case 4: // change theme type
        //     change_theme_type();
        //     break;

        // case 5: // change animation style
        //     change_anime_style();
        //     break;

        // case 6: // change display style
        //     change_display_style();
        //     break;

        // case 7: // welcome message enable/disable
        //     welcome_message();
        //     break;

        // case 8: // quit message enable/disable
        //     quit_message();
        //     break;

        // case 9: // hint message enable/disable
        //     hint_message();
        //     break;

        // case 10: // reset the settings and delete users
        //     reset();
        //     break;
    }
}

/**************************************************************************************************************
 * 
 *                                       AbstractSaveable IMPLEMENTATIONS
 * 
 * ***********************************************************************************************************/

std::vector<std::pair<std::string, std::string>> Settings::Data::save() const
{
    std::vector<std::pair<std::string, std::string>> vec;
    vec.emplace_back(Constant::File::ACTIVE_USER, Global::activeUser);
    return vec;
}

void Settings::Data::load(const std::vector<std::pair<std::string, std::string>> &vecData)
{
    int c;

    if (generate()) // Create a new file if not created
        return;

    auto pair = vecData.at(0);

    std::stringstream ss(pair.second);

    if (pair.first == Constant::File::ACTIVE_USER)
        ss >> Global::activeUser;
    else if (pair.first == Constant::File::LSEARCH_STATUS)
    {
        ss >> c;
        // updateStats(lSearchStats, c);
    }
    else if (pair.first == Constant::File::ANIME_SIGN_OUT_STATUS)
    {
        ss >> c;
        // updateStats(animeSignOutStats, c);
    }

    else if (pair.first == Constant::File::SHOW_QUIT)
        ss >> Global::showQuit;
    else if (pair.first == Constant::File::SHOW_HINT)
        ss >> Global::showHint;
}

std::string Settings::Data::getPath() const
{
    return Constant::Path::SETTINGS;
}

bool Settings::Data::generate() const
{
    std::ifstream inFile(Constant::Path::SETTINGS);

    if (inFile) // if file already exists returns else create a new file
    {
        inFile.close();
        return false;
    }

    // Assigns default values to unInitialized variables
    Global::activeUser = Constant::NULL_STR;
    // lSearchStats = DEFAULT;
    // animeSignOutStats = DEFAULT;
    Global::showQuit = true;
    Global::showHint = true;

    // If the settings file dosent exists it prints the above variable to the file for future uses

    std::ofstream outFile(Constant::Path::SETTINGS);

    File::print(outFile, {Constant::File::ACTIVE_USER, Global::activeUser});
    // File::print(outFile, {Constant::File::LSEARCH_STATUS, std::to_string(lSearchStats)});
    // File::print(outFile, {Constant::File::ANIME_SIGN_OUT_STATUS, std::to_string(animeSignOutStats)});
    File::print(outFile, {Constant::File::SHOW_QUIT, std::to_string(Global::showQuit)});
    File::print(outFile, {Constant::File::SHOW_HINT, std::to_string(Global::showHint)});

    outFile.close();

    return true;
}

/**************************************************************************************************************
 * 
 *                                         SETTINGS IMPLEMENTATIONS
 * 
 * ***********************************************************************************************************/

Settings::Data &Settings::data()
{
    return userData;
}

void Settings::start()
{
    Menu::player(Menu());
}

// bool Settings::isDefault()
// {
//     std::string usrActive;
//     int c, aso;
//     bool welcome, hint, quit;

//     if (data().generate())
//         return true;

//     auto vec = File::searchTag(data());

//     for (const auto &pair : vec)
//     {
//         std::stringstream ss(pair.second);

//         if (pair.first == Constant::File::ACTIVE_USER)
//             ss >> usrActive;
//         else if (pair.first == Constant::File::LSEARCH_STATUS)
//             ss >> c;
//         else if (pair.first == Constant::File::ANIME_SIGN_OUT_STATUS)
//             ss >> aso;
//         else if (pair.first == Constant::File::SHOW_WELCOME_MESSAGE)
//             ss >> welcome;
//         else if (pair.first == Constant::File::SHOW_QUIT_MESSAGE)
//             ss >> quit;
//         else if (pair.first == Constant::File::SHOW_HINT)
//             ss >> hint;
//     }

//     // It checks the default state of settings file by comparing the saved values with the default values
//     if (usrActive == Constant::NULL_STR && !c && !aso && welcome && quit && hint)
//         return true;

//     return false;
// }
// // Common function to update the Status enum variables
// void Settings::updateStats(enum Status &stats, int c)
// {
//     switch (c)
//     {
//     case 0:
//         stats = DEFAULT;
//         break;

//     case 1:
//         stats = EASY;
//         break;

//     case 2:
//         stats = ADV;
//         break;
//     }
// }

// void Settings::show_me_first(const std::string &message, int repeatFor)
// {
//     logo();

//     update_screen(std::string{" SETTINGS "});

//     if (Global::showHint) // display hint in every screen
//         show_hint();

//     header(std::string{" SETTINGS "}, false);

//     while (repeatFor--)
//     {
//         std::cout << message;
//         Sleep(250);

//         if (repeatFor == 0)
//             break;

//         size_t i{0};
//         while (i < message.size())
//         {
//             std::cout << "\b \b";
//             ++i;
//         }

//         std::cout << std::endl;
//     }

//     Sleep(300);
//     settings();
// }

// std::vector<std::string> Settings::settings_screen_selector()
// {
//     // select the correct menu to display as per need

//     std::vector<std::string> menu_to_display;

//     for (size_t i{0}; i < Menu::settings.size(); ++i)
//     {

//         std::string selector;

//         if (i == 6)
//             selector = state_selector(Global::showWelcome);
//         else if (i == 7)
//             selector = state_selector(Global::showQuit);
//         else if (i == 8)
//             selector = state_selector(Global::showHint);

//         menu_to_display.push_back(selector + Menu::settings.at(i));
//     }

//     return menu_to_display;
// }

// void Settings::change_text_anime_speed()
// {
//     cod::scan sc;
//     int speed;

//     header(std::string{" CHANGE ANIMATION SPEED "});

//     show_status(std::string{"Current speed: "}, std::to_string(Global::sleepTime));

//     animater(std::string{"Enter the speed: "});

//     sc >> speed;

//     if (speed < 0)
//         throw NegativeValueException();

//     Global::sleepTime = speed;

//     this->save(std::pair<std::string, std::string>(Constant::File::ANIMATION_SPEED, std::to_string(speed)));
// }

// void Settings::change_lsearch_type()
// {
//     cod::scan sc;
//     int ch;

//     do
//     {
//         menu(SmallMenu::lSearchType, std::string{" CHANGE LINEAR SEARCH TYPE "}, true, stats_selector(lSearchStats, SmallMenu::lSearchType), std::string{"Current Type: "});

//         sc.choice(ch);

//         switch (ch)
//         {
//         case 1:
//         case 2:
//         case 3:
//             File::update_stats(lSearchStats, ch - 1);
//             this->save(std::pair<std::string, std::string>(Constant::File::LSEARCH_STATUS, std::to_string(lSearchStats)));

//             return;

//         default:
//             print_message(std::string{"Invalid choice"}, true);
//             break;
//         }

//     } while (1);
// }

// void Settings::change_shortcuts_type()
// {
//     cod::scan sc;
//     int ch;

//     do
//     {
//         menu(SmallMenu::shortcutsType, std::string{" CHANGE SHORTCUT ACCESS "}, true, stats_selector(shortcutStats, SmallMenu::shortcutsType), std::string{"Current Type: "});

//         sc.choice(ch);

//         switch (ch)
//         {
//         case 1:
//         case 2:
//         case 3:
//             File::update_stats(shortcutStats, ch - 1);
//             this->save(std::pair<std::string, std::string>(Constant::File::SHORTCUT_STATUS, std::to_string(shortcutStats)));

//             return;

//         default:
//             print_message(std::string{"Invalid choice"}, true);
//             break;
//         }

//     } while (1);
// }

// void Settings::change_theme_type()
// {
//     print_message();
// }

// void Settings::change_anime_style()
// {
//     cod::scan sc;
//     int ch;

//     do
//     {
//         menu(SmallMenu::animeSignOutStyle, std::string{" CHANGE ANIMATION STYLE "}, true, stats_selector(animeSignOutStats, SmallMenu::animeSignOutStyle), std::string{"Current Animation: "});

//         sc.choice(ch);

//         switch (ch)
//         {
//         case 1:
//         case 2:
//         case 3:
//             File::updateStats(animeSignOutStats, ch - 1);
//             this->save(std::pair<std::string, std::string>(Constant::File::ANIME_SIGN_OUT_STATUS, std::to_string(animeSignOutStats)));

//             return;

//         default:
//             print_message(std::string{"Invalid choice"}, true);
//             break;
//         }

//     } while (1);
// }

// void Settings::change_display_style()
// {
//     print_message();
// }

// void Settings::welcome_message()
// {
//     Global::showWelcome = (!Global::showWelcome); // reverse the state

//     this->save(std::pair<std::string, std::string>(Constant::File::SHOW_WELCOME_MESSAGE, std::to_string(Global::showWelcome)));
// }

// void Settings::quit_message()
// {
//     Global::showQuit = (!Global::showQuit); // reverse the state

//     this->save(std::pair<std::string, std::string>(Constant::File::SHOW_QUIT_MESSAGE, std::to_string(Global::showQuit)));
// }

// void Settings::hint_message()
// {
//     Global::showHint = (!Global::showHint); // reverse the state

//     this->save(std::pair<std::string, std::string>(Constant::File::SHOW_HINT, std::to_string(Global::showHint)));
// }

// void Settings::reset()
// {
//     if (this->isDefault())
//     {
//         print_message(std::string{"Already in default settings"}, true);
//         return;
//     }

//     bool toProceed = confirm_the_change(std::string{"This will reset all the settings\nand delete all the user details!"});

//     if (toProceed)
//     {
//         std::remove(Constant::Path::SETTINGS.c_str());
//         std::remove(Path::fUser.c_str());

//         if (Global::activeUser != std::string{"NULL"})
//         {
//             header(std::string{" SETTINGS "});

//             std::cout << "To successfully reset the change\nClosing iCoder...";
//             press_key(NIL);
//             exit(0);
//         }

//         print_message(std::string{"Successfully deleted!"}, true);
//         this->generate();
//     }
// }