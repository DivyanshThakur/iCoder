#include <fstream>
#include <utility>
#include "../header/AbstractSaveable.hpp"
#include "../../constant/Constants.hpp"
#include "../../header/FileHandler.hpp"

bool AbstractSaveable::generate() const
{
    std::ifstream inFile(Constant::Path::USER);

    if (inFile)
    {
        inFile.close(); // if already exists, return false
        return false;
    }

    std::ofstream outFile(Constant::Path::USER);

    // These default values are stored for name generation
    std::vector<std::pair<std::string, std::string>> vec;
    vec.push_back({Constant::Title::ARRAY, ""});
    vec.push_back({Constant::Title::STRING, ""});

    // create file with default data
    FileHandler::print(outFile, vec);

    outFile.close();
    return true;
}
