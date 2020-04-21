#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "../header/AccountHandler.hpp"
#include "../header/UIhandler.hpp"
#include "../header/ExHandler.hpp"
#include "../header/Home.hpp"
#include "../header/CreateAccount.hpp"
#include "../header/Security.hpp"

void restore_saved_changes()
{
    std::ifstream file(Path::fSetting);

    if (!file)
    {
        Global::signedUserID = std::string{"NULL"};
        Global::sleepTime = 25;
        lSearchStats = DEFAULT;
        shortcutStats = DEFAULT;
        showedOneTime = true;
        Global::showWelcome = true;
        Global::showQuit = true;
        Global::showHint = true;

        std::ofstream outFile(Path::fSetting);

        print_to_file(outFile, File::CURRENT_USER, Global::signedUserID);
        print_to_file(outFile, File::ANIMATION_SPEED, Global::sleepTime);
        print_to_file(outFile, File::LSEARCH_STATUS, lSearchStats);
        print_to_file(outFile, File::SHORTCUT_STATUS, shortcutStats);
        print_to_file(outFile, File::SHOW_ONE_TIME_HINT, showedOneTime);
        print_to_file(outFile, File::SHOW_WELCOME_MESSAGE, Global::showWelcome);
        print_to_file(outFile, File::SHOW_QUIT_MESSAGE, Global::showQuit);
        print_to_file(outFile, File::SHOW_HINT, Global::showHint);

        outFile.close();

        return;
    }

    std::string title;
    int c;

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

bool check_new_user()
{
    std::ifstream file(Path::fUser);

    if (!file)
        return true;

    file.close();
    return false;
}

bool check_default_settings()
{
    std::ifstream file(Path::fSetting);
    std::string title, usr_signed;
    int time, c, s;
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
        else if (title == File::SHOW_ONE_TIME_HINT)
            file >> sothint;
        else if (title == File::SHOW_WELCOME_MESSAGE)
            file >> wlcome;
        else if (title == File::SHOW_QUIT_MESSAGE)
            file >> quit;
        else if (title == File::SHOW_HINT)
            file >> hint;
    }

    if (usr_signed == std::string{"NULL"} && time == 25 && !c && !s && sothint && wlcome && quit && hint)
        return true;

    file.close();
    return false;
}

void save_active_user(const std::string &userID)
{
    Global::signedUserID = userID;

    save_to_file(Path::fSetting, File::CURRENT_USER, Global::signedUserID);
}

void login()
{
    header(std::string{" LOGIN "});

    auto acc = std::make_unique<Account>();

    try
    {
        acc->input_data(); // taking username and password

        acc->check_account();

        acc->display_remember_me(); // it will display remember me message

        border(Ui::widthMenu);   // display the border
        load();                  // animate loading screen
        home(acc->get_userID()); // calling the main menu (HOME) screen to show all program list
    }
    catch (const EscPressed &e)
    {
        return;
    }
    catch (const InvalidUser &e)
    {
        std::cerr << e.what();

        press_key(PRE, "Press ESC to return");

        login();
    }
    catch (const FileNotOpenedException &e)
    {
        std::cerr << e.what();
        press_key();
    }
    catch (...)
    {
        std::cerr << "Unknown error occured!!!" << std::endl;
        press_key();
    }
}

void create_account()
{
    header(std::string{" CREATE ACCOUNT "}); // display the header

    auto acc = std::make_unique<CreateAccount>(); // pointer to CreateAccount class

    try
    {
        acc->input_data(); // taking userID, pass and confirmed password from the user

        if (acc->get_pass() != acc->get_pass2()) // validating same password or not
            throw PasswordNotMatchedException();

        acc->upload_account();

        acc->display_remember_me(); // it will display remember me message

        border(Ui::widthMenu);   // display the border
        load();                  // animate loading screen
        home(acc->get_userID()); // calling the main menu (HOME) screen to show all program list
    }
    catch (const EscPressed &e)
    {
        return;
    }
    catch (const PasswordNotMatchedException &e)
    {
        std::cerr << e.what();

        press_key(PRE, "Press ESC to return");

        create_account();
    }
    catch (const SavingUserException &e)
    {
        std::cerr << e.what();
        press_key();
    }
    catch (const FileNotOpenedException &e)
    {
        std::cerr << e.what();
        press_key();
    }
    catch (const UsernameAlreadyExistsException &e)
    {
        std::cerr << e.what();

        press_key(PRE, "Press ESC to return");

        create_account();
    }
    catch (...)
    {
        std::cerr << "Unknown error occured!!!" << std::endl;
        press_key();
    }
}

void display_users()
{
    header(" USERS ");

    std::ifstream file(Path::fUser);

    if (!file)
    {
        std::cout << "No user in database!";
        return;
    }

    auto acc = std::make_unique<Account>();

    border(Ui::widthIndex * 3 + Ui::widthUsername + Ui::widthPassword - 1);

    std::cout << " " << std::setw(Ui::widthIndex) << std::left << "INDEX"
              << " | " << std::setw(Ui::widthUsername) << std::left << "USERNAME"
              << " | " << std::setw(Ui::widthPassword) << std::left << "PASSWORD"
              << " |";

    border(Ui::widthIndex * 3 + Ui::widthUsername + Ui::widthPassword - 1);

    std::cout << std::setw(Ui::widthIndex + 1) << ""
              << " | " << std::setw(Ui::widthUsername) << ""
              << " | " << std::setw(Ui::widthPassword) << ""
              << " |";

    while (file >> *acc) // taking userID and pass from file to account class
    {
        std::cout << *acc; // display the id,pass to console using operator<< overloading
    }

    border(Ui::widthIndex * 3 + Ui::widthUsername + Ui::widthPassword - 1);

    file.close();
}

std::string pass_to_asteric(const std::string &pass)
{
    std::string ast;
    for (size_t i{0}; i < pass.length(); ++i)
        ast += "*";
    return ast;
}

template <typename T>
void save_to_file(const std::string &fileName, const std::string &title, const T &data)
{
    std::ifstream in_file(fileName);

    std::string file_str, file_title, line, val;

    if (!in_file)
    {
        std::cerr << "Error saving user details!" << std::endl;
        return;
    }

    while (std::getline(in_file, line))
    {
        file_str += line;
    }

    in_file.close();
    std::ofstream outFile(fileName);
    std::stringstream ss{file_str};
    bool isSaved{false};

    while (ss >> file_title)
    {
        ss >> val;

        if (file_title == title)
        {
            print_to_file(outFile, title, data);
            isSaved = true;
        }
        else
            print_to_file(outFile, file_title, val);
    }

    if (!isSaved)
        print_to_file(outFile, title, data);
}

template <typename T>
void print_to_file(std::ofstream &outFile, const std::string &title, const T &data)
{
    outFile << std::setw(Ui::widthUsername * 2) << std::left << title
            << std::setw(Ui::widthUsername) << std::left << data << std::endl;
}

template void save_to_file<std::string>(const std::string &fileName, const std::string &title, const std::string &data);
template void save_to_file<int>(const std::string &fileName, const std::string &title, const int &data);
template void save_to_file<bool>(const std::string &fileName, const std::string &title, const bool &data);
template void save_to_file<Status>(const std::string &fileName, const std::string &title, const Status &data);