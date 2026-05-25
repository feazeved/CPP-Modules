#include <limits>
#include <string>
#include <iostream>
#include <climits>

static void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool        clearFailedExtraction()
{
    if (!std::cin)
    {
        std::cin.clear();
        ignoreLine();
        return (true);
    }
    ignoreLine();
    return (false);
}

std::string TruncateString(const std::string &str, size_t width)
{
    if (str.length() >= width)
    {
        return (str.substr(0, width - 1) + ".");
    }
    else
        return (str);
}

