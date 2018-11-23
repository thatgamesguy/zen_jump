#ifndef PTPSETTINGSCONTROLLER_H
#define PTPSETTINGSCONTROLLER_H

#include "cocos2d.h"
#include "models/objects/PTModelAssetPowerup.h"
#include <map>

class PTPSettingsController
{
public:
    PTPSettingsController();
    static PTPSettingsController* shared();

    void setPowerupInventoryAmount(PTModelAssetPowerup* powerup, int amount);
    int powerupInventoryAmount( PTModelAssetPowerup* powerup);
    int coins;
    float distance;

private:

    std::map<int, int> _inventoryMap;

};

#endif // PTPSETTINGSCONTROLLER_H
