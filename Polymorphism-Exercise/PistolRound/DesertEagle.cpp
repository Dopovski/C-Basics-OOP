#include "DesertEagle.h"

DesertEagle::DesertEagle(const int damagePerRound,
                         const int clipSize,
                         const int remainingAmmo)
    : Pistol(damagePerRound, clipSize, remainingAmmo)
{
}

bool DesertEagle::fire(PlayerVitalData& enemyPlayerData)
{
    if (_currClipBullets == 0)
    {
        reload();
        return false;
    }

    --_currClipBullets;

    if (enemyPlayerData.armor > 0)
    {
        int armorDmg  = _damagePerRound / 4;
        int healthDmg = _damagePerRound * 3 / 4;

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

    return enemyPlayerData.health <= 0;
}
