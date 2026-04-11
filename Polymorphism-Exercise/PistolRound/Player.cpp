#include "Player.h"
#include "DesertEagle.h"
#include "Glock.h"

void Player::buyPistol(const PistolType pistolType,
                       const int        damagePerRound,
                       const int        clipSize,
                       const int        remainingAmmo)
{
    delete _pistol;

    if (pistolType == PistolType::DESERT_EAGLE)
    {
        _pistol = new DesertEagle(damagePerRound, clipSize, remainingAmmo);
    }
    else
    {
        _pistol = new Glock(damagePerRound, clipSize, remainingAmmo);
    }
}
