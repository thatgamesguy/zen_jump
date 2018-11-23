#ifndef PTPObjectAssetUnit_H
#define PTPObjectAssetUnit_H

#include "PTPObjectAsset.h"
#include "models/objects/PTModelAssetObstacle.h"
#include "PTPAnimationObject.h"
#include "box2D/Box2D.h"

class PTPObjectAssetUnit : public PTPObjectAsset {
public:
    explicit PTPObjectAssetUnit( PTModelObjectAsset *model );
    ~PTPObjectAssetUnit();

    void initPhysics( b2World *world );

    virtual void update(float dt);
    virtual void beginContact(PTPObjectAsset *obj, b2Contact *contact);
    virtual void endContact(PTPObjectAsset *obj, b2Contact *contact);
    virtual void setState( PTPObjectState s );

    virtual void wakeUp(); // perform wake up for object
    virtual float wakeUpDistance();

    virtual float damage();

    virtual void setSpawner( bool spawner );

    void deathAnimationDidEnd();
    virtual void spawnObject();   

private:
    PTModelObjectAssetUnit* _model;

    float _healthValue;

    PTPAnimationObject *_idleAnimation;
    PTPAnimationObject *_deathAnimation;

    bool _scheduledBodyChangeToDynamic;

};

#endif // PTPObjectAssetUnit_H
