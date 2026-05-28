#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class	ClapTrap {
public:
	ClapTrap();
	ClapTrap(const std::string &n);

	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);

	~ClapTrap();

  std::string& getName();
  void         setName(const std::string& n);

  int          getAd();
  void         setAd(const int a);

  int          getHp();


	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	
private:
	std::string name;
	int         hp;
	int         ep;
	int         ad;

  bool        isFit(const int& epCost);
};

#endif
