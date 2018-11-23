#ifndef PTModelObjectAssetCharacter_H
#define PTModelObjectAssetCharacter_H

#include "models/objects/PTModelObjectAsset.h"
#include "models/PTModelAnimation.h"
#include "attributes/PTPAttributeEnum.h"

class PTModelObjectAssetCharacter : public PTModelObjectAsset {
public:
    PTModelObjectAssetCharacter(CCString className = "PTModelObjectAssetCharacter");

    static PTModel *PTSTDCALL create() {
        return new PTModelObjectAssetCharacter();
    }

    virtual PTModelObjectAssetCharacter *duplicated();

    PTModelAnimation *idleAnimation() const ;
    PTModelAnimation *shootingAnimation() const ;
    PTModelAnimation *bulletAnimation() const ;
    PTModelAnimation *jumpAnimation() const;
    PTModelAnimation *deathAnimation() const;
    PTModelAnimation *moveAnimation() const;

    float deathCameraShake() const;
    float deathCameraFlash() const;
    float gameOverDelay() const;
    float deathFall() const;

    CCString shootSound() const ;
    CCString deathSound() const ;
    CCString jumpSound() const ;

private:
};

#endif // PTModelObjectAssetCharacter_H
