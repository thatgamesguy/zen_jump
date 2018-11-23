#ifndef PTModelObjectAssetUnit_H
#define PTModelObjectAssetUnit_H

#include "PTModelObjectAsset.h"
#include "PTModelAsset.h"
#include "models/PTModelAnimation.h"
#include "attributes/PTPAttributeShape.h"
#include "attributes/PTPAttributeAsset.h"
#include "attributes/PTPAttributeEnum.h"

class PTModelObjectAssetUnit : public PTModelObjectAsset {
public:
    PTModelObjectAssetUnit(CCString className = "PTModelObjectAssetUnit");

    virtual PTModelObjectAssetUnit *duplicated();

    PTPAttributeEnum *collisionType;
    PTPAttributeEnum *wakeUpType;

    CCString movementType() const;

    CCPoint moveSpeed() const;
    CCPoint moveSpeedVariable() const;
    void setMoveSpeed( CCPoint moveSpeed );

    float rotateSpeed() const;
    float rotateSpeedVariable() const;

    CCPoint linearVelocity() const;
    CCPoint linearVelocityVariable() const;
    void setLinearVelocity(CCPoint linearVelocity);

    float angularVelocity() const;
    float angularVelocityVariable() const;

    float wakeUpDistance() const;

    PTModelAnimation *idleAnimation();
    PTModelAnimation *deathAnimation();
    float health() const;
    float damage();

    void setSpawnAction(CCString spawnAction);
    CCString spawnAction();

    void setSpawner( bool isSpawner );
    virtual bool isSpawner();

    void setSpawnRate(float spawnRate);
    virtual float spawnRate();

    virtual void attributeDidUpdated(PTPAttribute *attr);

    static PTModel *PTSTDCALL create() {
        return new PTModelObjectAssetUnit();
    }

    CCString idleSound() const ;
    CCString deathSound() const ;
    CCString wakeUpSound() const ;

private:    
    PTPAttributeEnum *_objectTypeAttribute;

    PTPAttributeBoolean *_isSpawner;
    PTPAttributeFloat *_spawnRate;
    PTPAttributeEnum *_spawnAction;

    PTPAttributeGroup *_linearMovementAttributeGroup;
    PTPAttributeGroup *_physicsMovementAttributeGroup;
    PTPAttributeGroup *_spawningAttributeGroup;
    PTPAttributePoint *_moveSpeedAttribute;
    PTPAttributeFloat *_rotateSpeedAttribute;
    PTPAttributePoint *_linearVelocity;
    PTPAttributeFloat *_angularVelocity;
    PTPAttributeFloat *_wakeUpDistance;
    PTPAttributeEnum  *_movementType;

    friend class PTLevelEditorPresetController;
};

#endif // PTModelObjectAssetUnit_H
