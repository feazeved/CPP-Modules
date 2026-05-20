#ifndef WEAPON_HPP
# define WEAPON_HPP


class Weapon {
public:
    Weapon() = default;
    Weapon(Weapon &&) = default;
    Weapon(const Weapon &) = default;
    Weapon &operator=(Weapon &&) = default;
    Weapon &operator=(const Weapon &) = default;
    ~Weapon() = default;

private:
    
};
