
#include "../header/Hints.hpp"
#include "../../constant./Constants.hpp"

Hints::Data Hints::userData;

/**************************************************************************************************************
 * 
 *                                           AbstractMenu IMPLEMENTATIONS
 * 
 * ***********************************************************************************************************/

std::string Hints::Menu::title() const
{
    return std::string(Constant::Title::SETTINGS);
}

std::vector<std::string> Hints::Menu::getStats() const
{
    Ui::subHeader(Constant::Title::STATS);

    std::vector<std::string> vec;
    vec.emplace_back("Current Enabled :)");
    return vec;
}

std::vector<std::string> Hints::Menu::selector()
{
    menuIndexer(Constant::Menu::SETTINGS.size());
    return Constant::Menu::SETTINGS;
}

void Hints::Menu::controller() const
{
    switch (menuIndex.at(ch - 1))
    {
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

std::vector<std::pair<std::string, std::string>> Hints::Data::save() const
{
    // return std::vector<std::pair<std::string, std::string>>();
}

void Hints::Data::load(const std::vector<std::pair<std::string, std::string>> &vecData)
{
    // int c;

    // if (generate()) // Create a new file if not created
    //     return;

    // auto pair = vecData.at(0);

    // std::stringstream ss(pair.second);

    // if (pair.first == Constant::File::CURRENT_USER)
    //     ss >> Global::activeUser;
    // else if (pair.first == Constant::File::LSEARCH_STATUS)
    // {
    //     ss >> c;
    //     // updateStats(lSearchStats, c);
    // }
    // else if (pair.first == Constant::File::ANIME_SIGN_OUT_STATUS)
    // {
    //     ss >> c;
    //     // updateStats(animeSignOutStats, c);
    // }
    // else if (pair.first == Constant::File::SHOW_WELCOME_MESSAGE)
    //     ss >> Global::showWelcome;
    // else if (pair.first == Constant::File::SHOW_QUIT_MESSAGE)
    //     ss >> Global::showQuit;
    // else if (pair.first == Constant::File::SHOW_HINT)
    //     ss >> Global::showHint;
}

std::string Hints::Data::getPath() const
{
    // return Constant::Path::SETTINGS;
}

// bool Hints::Data::generate() const
// {
// std::ifstream inFile(Constant::Path::SETTINGS);

// if (inFile) // if file already exists returns else create a new file
// {
//     inFile.close();
//     return false;
// }

// // Assigns default values to unInitialized variables
// Global::activeUser = Constant::NULL_STR;
// lSearchStats = DEFAULT;
// animeSignOutStats = DEFAULT;
// Global::showWelcome = true;
// Global::showQuit = true;
// Global::showHint = true;

// // If the settings file dosent exists it prints the above variable to the file for future uses

// std::ofstream outFile(Constant::Path::SETTINGS);

// FileHandler::print(outFile, {Constant::File::CURRENT_USER, Global::activeUser});
// FileHandler::print(outFile, {Constant::File::LSEARCH_STATUS, std::to_string(lSearchStats)});
// FileHandler::print(outFile, {Constant::File::ANIME_SIGN_OUT_STATUS, std::to_string(animeSignOutStats)});
// FileHandler::print(outFile, {Constant::File::SHOW_WELCOME_MESSAGE, std::to_string(Global::showWelcome)});
// FileHandler::print(outFile, {Constant::File::SHOW_QUIT_MESSAGE, std::to_string(Global::showQuit)});
// FileHandler::print(outFile, {Constant::File::SHOW_HINT, std::to_string(Global::showHint)});

// outFile.close();

// return true;
// }

/**************************************************************************************************************
 * 
 *                                         HINTS IMPLEMENTATIONS
 * 
 * ***********************************************************************************************************/
