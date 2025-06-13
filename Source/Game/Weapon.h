#pragma once
class Weapon
{
    int m_bullets{10};

public:
    Weapon(int bullets);
    bool fire();
    int damage() const;
};