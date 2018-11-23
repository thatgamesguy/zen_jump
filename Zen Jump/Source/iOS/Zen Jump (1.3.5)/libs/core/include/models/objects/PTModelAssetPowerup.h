#ifndef PTMODELASSETPOWERUP_H
#define PTMODELASSETPOWERUP_H

#include "models/objects/PTModelAsset.h"
#include "attributes/PTPAttributeSprite.h"
#include "attributes/PTPAttributeAnimation.h"
#include "attributes/PTPAttributeEnum.h"
#include "attributes/PTPAttributeSound.h"

class PTModelAssetPowerup : public PTModelAsset {
public:
    PTModelAssetPowerup(CCString name = "Powerup");

    virtual PTModelSpriteContainer *sprite();

    void setIdleSpriteAnimation(PTModelSpriteContainer *sprite);
    PTModelAnimation* idelAnimation();
    PTModelAnimation* startAnimation();
    PTModelAnimation* endAnimation();

    CCString constraintType();

    int reward() const ;
    float cameraShake() const;
    float cameraFlash() const;
    float duration() const;
    int price() const;

    CCString powerupType();

    CCString idleSoundAttribute() const;
    CCString startSoundAttribute() const;
    CCString endSoundAttribute() const;

    static PTModel *PTSTDCALL create() {
        return new PTModelAssetPowerup();
    }

private:

    PTPAttributeFloat* _rewardAttribute;
    PTPAttributeFloat* _appearanceChanceAttribute;
    PTPAttributeEnum* _powerupType;
    PTPAttributeFloat* _priceAttribute;
    PTPAttributeFloat* _cameraShake;
    PTPAttributeFloat* _cameraFlash;
    PTPAttributeFloat* _durationAttribute;
    PTPAttributeEnum* _constraintTypeAttribute;
    PTPAttributeAnimation* _idleAnimationAttribute;
    PTPAttributeAnimation* _startAnimationAttribute;
    PTPAttributeAnimation* _endAnimationAttribute;

    PTPAttributeSound *_idleSoundAttribute;
    PTPAttributeSound *_startSoundAttribute;
    PTPAttributeSound *_endSoundAttribute;

    friend class PTLevelEditorScreen;
};

#endif // PTMODELASSETPOWERUP_H
