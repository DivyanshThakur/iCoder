#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>

/** FUNCTION PROTOTYPES **/

void createFile();
void makeDirectory();

/** CONSTANTS **/
const std::string fmenu = "./data/menu.txt";

void createFile() {

    makeDirectory();               // make a "data" folder if not created

    std::ofstream file (fmenu);

    std::string menu_data {"MENU1\n1. Log In\n2. Create Account\n3. Try (Anonymous)\n4. About\n5. Exit~\n\n\n"};

    if(!file) {
        std::cerr << "Error Opening file." << std::endl;
        std::cin.get();
        exit(1);
    }

    for(auto c: menu_data)
        file << c;

    file.close();
}

void makeDirectory() {
    std::string dirpath {"data"};
    mkdir(dirpath.c_str());
}