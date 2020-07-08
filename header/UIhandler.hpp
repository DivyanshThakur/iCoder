#ifndef UI_HANDLER_HPP
#define UI_HANDLER_HPP

class Ui
{
public:
    static void logo();
    static void menu(const std::vector<std::string> &vecMenu, const std::string &heading = "MENU", bool showStatus = false, const std::string &statsVal = "Default", const std::string &statsStr = "Current Status: ");
    static void show_status(const std::string &statsStr, const std::string &statsVal, bool isFinal = true);
    static std::string stats_selector(const enum Status &stats, const std::vector<std::string> &statsData);
    static void updateLastScreen();
    static void updateScreen(const std::string &heading);
    static void header(const std::string &menuTitle, bool showTitle = true);
    static void showHint();
    static void border(int size);
    static void emessage(const std::string &emessage);
    static void animater(const std::string &anime);
    static void igetch();
    static void print(const std::string &message);
    static void printnPress(const std::string &message);
    static void pressKey(const std::string &message = "Press any key to continue");
    bool isIPressed(const std::string &message);
    // static void erase_line(size_t len = Ui::widthMenu);
    static std::string s_or_not_s(size_t num, const std::string &message, const std::string &extra = "s", const std::string &updateFirst = "");
    static void waitMessage(const std::string &message);
    bool confirm_the_change(const std::string &message, const std::string &txtConfirm = "Do you want to proceed?");
};

#endif