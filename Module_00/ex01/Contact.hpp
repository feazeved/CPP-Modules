#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
    public:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string number;

        Contact();
        std::string GetSecret() const;
        void        SetSecret(const std::string& str);

    private:
        std::string secret;
};

#endif

