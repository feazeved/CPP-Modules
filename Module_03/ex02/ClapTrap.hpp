#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class	ClapTrap {
public:
	ClapTrap();
	ClapTrap(const std::string &n);

	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);

	virtual ~ClapTrap();

	const std::string& getName() const;
	void         setName(const std::string& n);

	int          getAd() const;
	void         setAd(const int a);

	int          getHp() const;

	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

protected:
	std::string name;
	int         hp;
	int         ep;
	int         ad;
};

#endif
