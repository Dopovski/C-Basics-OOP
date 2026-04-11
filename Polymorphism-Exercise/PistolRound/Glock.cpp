#include "Glock.h"

Glock::Glock(const int damagePerRound,
             const int clipSize,
             const int remainingAmmo)
    : Pistol(damagePerRound, clipSize, remainingAmmo)
{
}

bool Glock::fire(PlayerVitalData& enemyPlayerData)
{
    if (_currClipBullets == 0)
    {
        reload();
        return false;
    }

    for (int shot = 0; shot < ROUNDS_PER_FIRE; ++shot)
    {
        if (_currClipBullets == 0)
        {
            reload();
            return false;
        }

        --_currClipBullets;

        if (enemyPlayerData.armor > 0)
        {
            int armorDmg  = _damagePerRound / 2;
            int healthDmg = _damagePerRound / 2;

            if (armorDmg >= enemyPlayerData.armor)
            {
                healthDmg += armorDmg - enemyPlayerData.armor;
                enemyPlayerData.armor = 0;
            }
            else
            {
                enemyPlayerData.armor -= armorDmg;
            }

            enemyPlayerData.health -= healthDmg;
        }
        else
        {
            enemyPlayerData.health -= _damagePerRound;
        }

        std::cout << "Enemy left with: " << enemyPlayerData.health
                  << " health and " << enemyPlayerData.armor << " armor\n";

        if (enemyPlayerData.health <= 0)
        {
            return true;
        }
    }

    return false;
}
