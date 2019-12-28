#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>

/** FUNCTION PROTOTYPES **/

void createFile();
void makeDirectory();

/** CONSTANTS **/
const extern std::string fmenu;

void createFile()
{

    makeDirectory(); // make a "data" folder if not created

    std::ofstream file(fmenu);

    std::string menu_data{"MENU1\n1. Log In\n2. Create Account\n3. Try (Anonymous)\n4. Users\n5. About\n6. Exit~\n\n\n"};

    if (!file)
    {
        std::cerr << "Error Opening file." << std::endl;
        std::cin.get();
        exit(1);
    }

    for (auto c : menu_data)
        file << c; // sending all the menu data to the menu.txt file and saving it

    file.close();
}

void makeDirectory()
{
    // these code will create a folder in that specific destination
    std::string dirpath{"data"};
    mkdir(dirpath.c_str());
}

#endif