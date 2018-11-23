#ifndef PTPObjectAssetCharacter_H
#define PTPObjectAssetCharacter_H

#include "box2D/Box2D.h"

#include "models/objects/PTModelAssetCharacter.h"
#include "models/objects/PTModelObject.h"
#include "objects/PTPObjectAsset.h"
#include "PTPAnimationObject.h"
#include "models/objects/PTModelObjectAssetCharacter.h"
#include <map>

enum PTPObjectAssetCharacterState{
    PTPObjectAssetCharacterStateIdle,
    PTPObjectAssetCharacterStateMoving,
    PTPObjectAssetCharacterStateJumpPressed,
    PTPObjectAssetCharacterStateJumpReleased,
    PTPObjectAssetCharacterStateShooting
};

enum PTPObjectAssetCharacterFlags {
    PTPObjectAssetCharacterFlagJump = 0x01,
    PTPObjectAssetCharacterFlagMoving = 0x02,
    PTPObjectAssetCharacterFlagRotateLeft  = 0x04,
    PTPObjectAssetCharacterFlagRotateRight = 0x08,
    PTPObjectAssetCharacterFlagGrounded    = 0x10
};


class PTPObjectAssetCharacter : public PTPObjectAsset{

public:
    PTPObjectAssetCharacter( PTModelObjectAsset* model );
    ~PTPObjectAssetCharacter();

    void initPhysics( b2World* world );
    void setShooting( bool enabled );
    void setTargetPosition( CCPoint target );
    void move(float dx, float dy);

    virtual void setState( PTPObjectState s );

    virtual void update(float dt);
    virtual void beginContact( PTPObjectAsset *obj,  b2Contact *contact );
    virtual void endContact( PTPObjectAsset *obj,  b2Contact *contact );
    virtual void preSolve(PTPObjectAsset *obj, b2Contact* contact, const b2Manifold* oldManifold);

    void setGrounded( bool grounded );

    void actionJumpPressed();
    void actionJumpReleased();

    void actionRotateLeftPressed();
    void actionRotateLeftReleased();
    void actionRotateRightPressed();
    void actionRotateRightReleased();

    virtual float damage();

    float speed();

    void setModel(PTModelObjectAssetCharacter* model);

    CCPoint moveVector();
    void setMoveVector( CCPoint vector );
    void setMoveVectorX(float x);
    void setMoveVectorY(float y);
    void applyForce( float x, float y);

    bool isInvincibilityMode();
    void setInvincibilityMode( bool enabled );


protected:
    void deathAnimationDidEnd();

private:
    void updateGroundedState();

    PTPAnimationObject* _idleAnimation;
    PTPAnimationObject* _shootingAnimation;
    PTPAnimationObject* _jumpAnimation;
    PTPAnimationObject* _deathAnimation;
    PTPAnimationObject* _moveAnimation;

    PTModelObjectAssetCharacter* _model;

    bool pShooting;
    CCPoint pTargetPosition;

    b2MouseJoint* pMouseJoint;
    b2Body* pGroundBody;

    CCPoint _moveVector;
    b2Vec2 _forceVector;
    b2Vec2 _gravityVector;

    uint32 pFlags;

    float pSpeed;
    float _upForceDuration;
    int _upForceCounter;

    float _gameOverDelay;
    bool _scheduleDeathFall;

    bool _invincibilityMode;
};

#endif // PTPObjectAssetCharacter_H
