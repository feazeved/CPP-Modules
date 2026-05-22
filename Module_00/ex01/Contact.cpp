#include "Contact.hpp"
#include <string>
#include <iostream>

void        Contact::PrintContact()
{
    std::cout << "\nFirst name: " << GetFirstName() << "\n";
    std::cout << "Last name: " << GetLastName() << "\n";
    std::cout << "Nickname: " << GetNick() << "\n";
    std::cout << "Number: " << GetNumber() << "\n";
    std::cout << "The darkest secret: " << GetSecret() << "\n\n";
}

std::string Contact::GetFirstName() const
{
    return (first_name);
}
void        Contact::SetFirstName(const std::string& str)
{
    first_name = str;
}

std::string Contact::GetLastName() const
{
    return (last_name);
}
void        Contact::SetLastName(const std::string& str)
{
    last_name = str;
}

std::string Contact::GetNick() const
{
    return (nick);
}
void        Contact::SetNick(const std::string& str)
{
    nick = str;
}

std::string Contact::GetNumber() const
{
    return (number);
}
void        Contact::SetNumber(const std::string& str)
{
    number = str;
}

std::string Contact::GetSecret() const
{
    return (secret);
}
void        Contact::SetSecret(const std::string& str)
{
    secret = str;
}
