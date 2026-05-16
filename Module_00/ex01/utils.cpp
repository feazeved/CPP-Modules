#include <limits>

void  ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool  cleanFailedExtraction()
{
    if (!std::cin)
    {
        if (std::cin,eof())
        {
            std::exit(1);
        }
        std::cin.clear();
        ignoreLine();
        return (true);
    }
    return (false);
}
