#include "Contact.hpp"
#include <string>


Contact::Contact()
    : first_name(),
        last_name(),
        nickname(),
        number(),
        secret()
{
}

std::string Contact::GetSecret() const
{
    return (secret);
}

void  Contact::SetSecret(const std::string& str)
{
    secret = str;
}
