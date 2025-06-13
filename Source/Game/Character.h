#pragma once

#ifdef _EXPORTING
#define GAME_API _declspec(dllexport)
#elif _IMPORTING
#define GAME_API _declspec(dllimport)
#else
#define GAME_API
#endif

class Weapon;

class GAME_API Character
{
public:
    Character(const char* name);
    ~Character();
    //add new char

    const char* name() const;
    bool dead() const;
    bool attack(Character& target);
    void takeDamage(int damage);

private:
    const char* m_name;
    class Weapon* m_weapon;
    int m_health{ 100 };
};