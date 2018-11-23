#ifndef PTMODELASSETCHARACTER_H
#define PTMODELASSETCHARACTER_H

#include "models/objects/PTModelAsset.h"
#include "attributes/PTPAttributeSprite.h"

class PTPAttributePoint;
class PTPAttributeBoolean;
class PTPAttributeFloat;
class PTPAttributeAnimation;
class PTPAttributeShape;
class PTPAttributeSound;
class PTPAttributeEnum;
class PTModelSpriteContainer;
class PTModelAnimation;

class PTModelAssetCharacter : public PTModelAsset {
public:
    PTModelAssetCharacter(CCString name = "Untitled");

    virtual void initWithDictionary(CCDictionary *dict);
    virtual CCDictionary *getDictionary();

    PTModelAnimation *idleAnimation() const;
    PTModelAnimation *shootingAnimation() const;
    PTModelAnimation *bulletAnimation() const;
    PTModelAnimation *jumpAnimation() const;
    PTModelAnimation *moveAnimation() const;

    PTModelAnimation *deathAnimtion() const;
    float deathCameraShake() const;
    float deathCameraFlash() const;
    float deathFall() const;
    float gameOverDelay() const;

    CCString jumpSound() const;
    CCString shootSound() const;
    CCString deathSound() const;

    virtual PTModelSpriteContainer *sprite();

    static PTModel *PTSTDCALL create() {
        return new PTModelAssetCharacter();
    }

private:
    void setBodyAnimation(PTModelSpriteContainer *spriteContainer);

    PTPAttributeAnimation *_idleAnimationAttribute;
    PTPAttributeAnimation *_shootingAnimationAttribute;
    PTPAttributeAnimation *_bulletAnimationAttribute;
    PTPAttributeAnimation *_jumpAnimationAttribute;
    PTPAttributeAnimation *_moveAnimationAttribute;
    PTPAttributeAnimation *_deathAnimationAttribute;
    PTPAttributeFloat *_cameraShakeAttribute;
    PTPAttributeFloat *_cameraFlashAttribute;
    PTPAttributeFloat *_gameOverDelayAttribute;
    PTPAttributeFloat *_deathFallAttribute;

	PTPAttributeSound *_jumpSoundAttribute;
	PTPAttributeSound *_shootSoundAttribute;
	PTPAttributeSound *_deathSoundAttribute;

    int _zDepth;

    friend class PTLevelEditorScreen;
};

#endif // PTMODELASSETCHARACTER_H
