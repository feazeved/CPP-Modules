#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
    public:
        Contact();


        std::string GetFirstName() const;
        void        SetFirstName(const std::string& str);

        std::string GetLastName() const;
        void        SetLastName(const std::string& str);

        std::string GetNick() const;
        void        SetNick(const std::string& str);

        std::string GetNumber() const;
        void        SetNumber(const std::string& str);

        std::string GetSecret() const;
        void        SetSecret(const std::string& str);

    private:
        std::string first_name;
        std::string last_name;
        std::string nick;
        std::string number;
        std::string secret;


};

#endif

