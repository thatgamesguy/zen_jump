#ifndef PTPOBJECTASSET_H
#define PTPOBJECTASSET_H

#include "PTPObject.h"
#include "models/objects/PTModelAsset.h"
#include "box2D/Box2D.h"
#include "models/objects/PTModelObjectAssetUnit.h"
#include "models/PTModelGeneralSettings.h"

enum PTPObjectAssetCollisionType{
    PTPObjectAssetCollisionNo = 0,
    PTPObjectAssetCollisionCharacter,
    PTPObjectAssetCollisionDestroy
};

class PTPObjectAsset : public PTPObject
{
public:
    PTPObjectAsset(PTModelObjectAsset* model);
    ~PTPObjectAsset();

    static PTPObjectAsset* create(PTModelObjectAsset* model);

    virtual void initPhysics(b2World* world);
    virtual void update(float dt);

    virtual void beginContact( PTPObjectAsset *obj,  b2Contact *contact );
    virtual void endContact( PTPObjectAsset *obj,  b2Contact *contact );
    virtual void preSolve( PTPObjectAsset *obj, b2Contact* contact, const b2Manifold* oldManifold);
    bool isMovementTypeLinear();

    bool isSpawnEnabled();
    void setSpawnEnabled( bool spawnEnabled );
    CCPoint linearMoveSpeed();
    virtual void spawnObject();

    PTPObjectAssetCollisionType collisionType();

protected:
    void playSound(const CCString &soundFile, bool loop = false);

protected:

    PTModelGeneralSettings* _generalSettingsModel;
    PTPObjectAssetCollisionType _collisionType;

    float _linearRotationSpeed;
    CCPoint _linearMoveSpeed;
    bool _movementTypeLinear;

    bool _spawnEnabled;
    float _spawnCounter;

private:
    PTModelObjectAsset* _model;

};

#endif // PTPOBJECTASSET_H
