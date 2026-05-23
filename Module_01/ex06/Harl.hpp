#ifndef HARL_HPP
# define HARL_HPP

#include <string>

enum level {
    NONE,
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

class Harl {
public:
    void  complain(const level& option);
private:
    void  debug(void);
    void  info(void);
    void  warning(void);
    void  error(void);
};

#endif

