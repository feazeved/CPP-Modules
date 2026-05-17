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

int         MyAtoi(const std::string &str)
{
    int   i = 0;
    long  sum = 0;
    int   sign = 1;

    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (std::isdigit(str[i]))
    {
        if (sum > INT_MAX || sum < INT_MIN)
            return (-1);
        sum = sum * 10 + str[i] - '0';
        i++;
    }
    if (str[i])
        return (-1);
    return (sign * sum);
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
