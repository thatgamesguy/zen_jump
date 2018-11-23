#ifndef PTPASSETPOWERUP_H
#define PTPASSETPOWERUP_H

#include "PTPObjectAsset.h"
#include "models/objects/PTModelObjectAssetPowerup.h"
#include "PTPAnimationObject.h"

class PTPObjectAssetPowerup : public PTPObjectAsset
{
public:
    explicit PTPObjectAssetPowerup( PTModelObjectAsset* model);
    ~PTPObjectAssetPowerup();
    virtual void initPhysics(b2World* world);
    virtual void update(float dt);
    virtual void beginContact(PTPObjectAsset *obj,  b2Contact *contact );
    virtual void setState( PTPObjectState s );

private:
    void endAnimationDidEnd();
    PTModelObjectAssetPowerup* _model;
    PTPAnimationObject *_idleAnimation;
    PTPAnimationObject *_startAnimation;
    PTPAnimationObject *_endAnimation;

    bool pRewardAnimation;
    float pRewardAnimationCounter;
    CCLabelBMFont* pRewardLabel;

    bool _characterConstraint;
    bool _screenConstarint;

    float _duration;
};

#endif // PTPASSETCOIN_H
