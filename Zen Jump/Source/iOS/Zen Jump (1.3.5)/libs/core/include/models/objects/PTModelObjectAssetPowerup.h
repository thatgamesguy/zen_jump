#ifndef PTMODELOBJECTASSETPOWERUP_H
#define PTMODELOBJECTASSETPOWERUP_H

#include "PTModelObjectAsset.h"
#include "models/PTModelAnimation.h"

class PTModelObjectAssetPowerup : public PTModelObjectAsset {
public:
    PTModelObjectAssetPowerup();
    static PTModel *PTSTDCALL create() {
        return new PTModelObjectAssetPowerup();
    }

    virtual PTModelObjectAssetPowerup *duplicated();

    int reward() const;
    float cameraShake() const;
    float cameraFlash() const;
    float duration() const;

    PTModelAnimation *startAnimation() const;
    PTModelAnimation *endAnimation() const;
    PTModelAnimation *idleAnimation() const;
    CCString constraintType() const;
    CCString powerupType() const;

    CCString idleSound() const ;
    CCString startSound() const ;
    CCString endSound() const ;
};

#endif // PTMODELOBJECTASSETPOWERUP_H
