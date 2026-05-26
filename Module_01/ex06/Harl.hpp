#ifndef HARL_HPP
# define HARL_HPP

#include <string>

enum level {
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

class Harl {
public:
    void  complain(char *str);
private:
    void  debug(void);
    void  info(void);
    void  warning(void);
    void  error(void);
};

#endif

