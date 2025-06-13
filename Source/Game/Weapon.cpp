#include "Weapon.h"
#include "Utils/Math.h"

Weapon::Weapon(int bullets) : m_bullets{bullets} {}

bool Weapon::fire()
{
    if (m_bullets <= 0) return false;
    m_bullets--;

    return true;
}

int Weapon::damage() const
{
    return randInt(5, 40);
}