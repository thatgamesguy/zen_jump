#ifndef PTPOBJECT_H
#define PTPOBJECT_H

#include "cocos2d.h"
#include "box2D/Box2D.h"


enum PTPObjectType {
    PTPObjectTypeCharacter = 0x01,
    PTPObjectTypeObstacle  = 0x02,
    PTPObjectTypePowerup  = 0x04,
    PTPObjectTypeBackground = 0x8,
    PTPObjectTypeSpawned = 0x10,
};

enum PTPObjectState {
    PTPObjectStateDefault  = 0,
    PTPObjectStateActive   ,
    PTPObjectStateShooting ,
    PTPObjectStateJumping  ,
    PTPObjectStateDeath    ,
    PTPObjectStateDeletion

};

// 0x01 ==   1 == "00000001"
// 0x02 ==   2 == "00000010"
// 0x04 ==   4 == "00000100"
// 0x08 ==   8 == "00001000"
// 0x10 ==  16 == "00010000"
// 0x20 ==  32 == "00100000"
// 0x40 ==  64 == "01000000"
// 0x80 == 128 == "10000000"

class PTPObject : public cocos2d::CCNode
{
public:
    PTPObject();
    virtual void update( float dt);

    PTPObjectState state;
    virtual void setState( PTPObjectState s );

    virtual void wakeUp();
    bool isWakeUp();
    virtual float wakeUpDistance();

    b2Body* bodyPhysics();

    virtual void setSpawner( bool spawner );
    bool isSpawner();
    virtual float damage();

    void setCameraNode( CCNode* cameraNode);

    int type();
    void setType( int type );

protected:
    int _type;
    bool _spawner;
    bool _wakeUp;
    b2Body* pBodyPhysics;

    CCNode *_cameraNode;
};

#endif // PTPOBJECT_H
