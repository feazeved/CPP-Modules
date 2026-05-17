#include "Contact.hpp"
#include <string>


Contact::Contact()
    : first_name(),
        last_name(),
        nick(),
        number(),
        secret()
{
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
void  Contact::SetSecret(const std::string& str)
{
    secret = str;
}
