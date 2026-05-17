#include <limits>
#include <iostream>

static void  ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool  clearFailedExtraction()
{
    if (!std::cin)
    {
        if (std::cin.eof())
        {
            std::exit(1);
        }
        std::cin.clear();
        ignoreLine();
        return (true);
    }
    ignoreLine();
    return (false);
}

std::string TruncateString(const std::string &str, size_t width)
{
    if (std::str.width >= width)
    {
        return (std::str.substr(0, width - 1) + ".");
    }
    else
        return (str);
}
