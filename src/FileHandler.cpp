#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "../header/FileHandler.hpp"
#include "../header/ExHandler.hpp"
#include "../header/UIhandler.hpp"

void restore_saved_changes()
{
    std::ifstream file(Path::fSetting);

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
    if (!file)
    {
        std::ofstream outFile(Path::fSetting);

        print_to_file(outFile, File::CURRENT_USER, Global::signedUserID);
        print_to_file(outFile, File::ANIMATION_SPEED, Global::sleepTime);
        print_to_file(outFile, File::LSEARCH_STATUS, lSearchStats);
        print_to_file(outFile, File::SHORTCUT_STATUS, shortcutStats);
        print_to_file(outFile, File::ANIME_SIGN_OUT_STATUS, animeSignOutStats);
        print_to_file(outFile, File::SHOW_ONE_TIME_HINT, showedOneTime);
        print_to_file(outFile, File::SHOW_WELCOME_MESSAGE, Global::showWelcome);
        print_to_file(outFile, File::SHOW_QUIT_MESSAGE, Global::showQuit);
        print_to_file(outFile, File::SHOW_HINT, Global::showHint);

        outFile.close();

        return;
    }

    std::string title;
    int c;

    // If the file already exists, it assigns the saved values to the above variables
    while (file >> title)
    {
        if (title == File::CURRENT_USER)
            file >> Global::signedUserID;
        else if (title == File::ANIMATION_SPEED)
            file >> Global::sleepTime;
        else if (title == File::LSEARCH_STATUS)
        {
            file >> c;
            update_stats(lSearchStats, c);
        }
        else if (title == File::SHORTCUT_STATUS)
        {
            file >> c;
            update_stats(shortcutStats, c);
        }
        else if (title == File::ANIME_SIGN_OUT_STATUS)
        {
            file >> c;
            update_stats(animeSignOutStats, c);
        }
        else if (title == File::SHOW_ONE_TIME_HINT)
            file >> showedOneTime;
        else if (title == File::SHOW_WELCOME_MESSAGE)
            file >> Global::showWelcome;
        else if (title == File::SHOW_QUIT_MESSAGE)
            file >> Global::showQuit;
        else if (title == File::SHOW_HINT)
            file >> Global::showHint;
    }

    file.close();
}

// Common function to update the Status enum variables
void update_stats(enum Status &stats, int c)
{
    switch (c)
    {
    case 0:
        stats = DEFAULT;
        break;

    case 1:
        stats = EASY;
        break;

    case 2:
        stats = ADV;
        break;
    }
}

// It checks the default state of settings file by comparing the saved values with the default values
bool check_default_settings()
{
    std::ifstream file(Path::fSetting);
    std::string title, usr_signed;
    int time, c, s, aso;
    bool sothint, wlcome, hint, quit;

    if (!file)
        return true;

    while (file >> title)
    {
        if (title == File::CURRENT_USER)
            file >> usr_signed;
        else if (title == File::ANIMATION_SPEED)
            file >> time;
        else if (title == File::LSEARCH_STATUS)
            file >> c;
        else if (title == File::SHORTCUT_STATUS)
            file >> s;
        else if (title == File::ANIME_SIGN_OUT_STATUS)
            file >> aso;
        else if (title == File::SHOW_ONE_TIME_HINT)
            file >> sothint;
        else if (title == File::SHOW_WELCOME_MESSAGE)
            file >> wlcome;
        else if (title == File::SHOW_QUIT_MESSAGE)
            file >> quit;
        else if (title == File::SHOW_HINT)
            file >> hint;
    }

    if (usr_signed == std::string{"NULL"} && time == 25 && !c && !s && !aso && sothint && wlcome && quit && hint)
        return true;

    file.close();
    return false;
}

void save_active_user(const std::string &userID)
{
    Global::signedUserID = userID;

    // save the current user to the file for automatically log in
    save_to_file(Path::fSetting, File::CURRENT_USER, Global::signedUserID);
}

std::string get_file_str(const std::string &fileName)
{
    std::ifstream inFile(fileName);

    std::string fileStr, line;

    if (!inFile)
        throw FileNotOpenedException();

    // Scans and appends the data from the settings file to the fileStr variable
    while (std::getline(inFile, line))
    {
        fileStr += line;
    }

    inFile.close();

    return fileStr;
}

template <typename T>
void save_to_file(const std::string &fileName, const std::string &title, const T &data)
{
    std::stringstream ss{get_file_str(fileName)};

    std::ofstream outFile(fileName);
    std::string fileTitle, val;
    bool isSaved{false};

    // stringstream helps in checking string line by line
    while (ss >> fileTitle) // scan the title
    {
        ss >> val; // scan the value stored

        if (fileTitle == title) // if scanned title equals the title whose value we changed
        {                       // will print the changed value to file and update it
            print_to_file(outFile, title, data);
            isSaved = true; // checks for new titles i.e. new setting feature for older version of files
        }
        else
            print_to_file(outFile, fileTitle, val); // print again without change
    }

    if (!isSaved) // adds new setting to the end of file
        print_to_file(outFile, title, data);
}

void save_to_file(const std::string &fileName, const std::string &title, const ISaveable &iSave)
{
    std::stringstream ss{get_file_str(fileName)};

    // std::ofstream outFile(fileName);
    // std::string fileTitle, val;
    // bool isSaved{false};

    // // stringstream helps in checking string line by line
    // while (ss >> fileTitle) // scan the title
    // {
    //     ss >> val; // scan the value stored

    //     if (fileTitle == title) // if scanned title equals the title whose value we changed
    //     {                       // will print the changed value to file and update it
    //         print_to_file(outFile, title, iSave);
    //         isSaved = true; // checks for new titles i.e. new setting feature for older version of files
    //     }
    //     else
    //         print_to_file(outFile, fileTitle, val); // print again without change
    // }

    // if (!isSaved) // adds new setting to the end of file
    // print_to_file(outFile, title, iSave);
}

template <typename T>
void print_to_file(std::ofstream &outFile, const std::string &title, const T &data)
{
    // print values to file with titles
    outFile << std::setw(Ui::widthUsername * 2) << std::left << title
            << data << std::endl;
}

void print_to_file(std::ofstream &outFile, const cod::pair<std::string, std::string> &pair)
{
    // print values to file with titles
    outFile << std::setw(Ui::widthUsername * 2) << std::left << pair.first()
            << pair.second() << std::endl;
}

template void save_to_file<std::string>(const std::string &fileName, const std::string &title, const std::string &data);
template void save_to_file<int>(const std::string &fileName, const std::string &title, const int &data);
template void save_to_file<bool>(const std::string &fileName, const std::string &title, const bool &data);
template void save_to_file<Status>(const std::string &fileName, const std::string &title, const Status &data);