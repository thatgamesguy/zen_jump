#ifndef PTPINPUTCONTROLLER_H
#define PTPINPUTCONTROLLER_H

#include "cocos2d.h"
#include "box2D/Box2D.h"
#include "models/objects/PTModelObjectAssetUnit.h"
#include "objects/PTPObjectAssetUnit.h"
#include "objects/PTPObjectAssetCharacter.h"

class PTPObjectAsset;

enum PTPInputControllerAction {
    PTPInputControllerActionUnknown,
    PTPInputControllerActionMoveUp,
    PTPInputControllerActionMoveDown,
    PTPInputControllerActionMoveRight,
    PTPInputControllerActionMoveLeft,
    PTPInputControllerActionJump,
    PTPInputControllerActionRotateLeft,
    PTPInputControllerActionRotateRight,
    PTPInputControllerActionShoot,
    PTPInputControllerActionMotorCW,
    PTPInputControllerActionMotorCCW
};

enum PTPInputControllerKey {
    PTPInputControllerKeyUnknown,
    PTPInputControllerKeyLeft,
    PTPInputControllerKeyRight,
    PTPInputControllerKeyUp,
    PTPInputControllerKeyDown,
    PTPInputControllerKeyShoot,
    PTPInputControllerKeyJump,
    PTPInputControllerKeyMotorCW,
    PTPInputControllerKeyMotorCCW,
    PTPInputControllerKeyRotateLeft,
    PTPInputControllerKeyRotateRight,
};

class PTPInputController: public CCObject{

public:
    PTPInputController();
    ~PTPInputController();
    static PTPInputController* shared();

    void clear();

    void keyPressed( PTPInputControllerKey key);
    void keyReleased( PTPInputControllerKey key);

    void touchesBegan(CCSet *touches);
    void touchesMoved(CCSet *touches);
    void touchesEnded(CCSet *touches);

    void gamepadAxisMoved( int value, int axis );
    void gamepadButtonPressed( int button );
    void gamepadButtonReleased( int button );

    void buttonJumpPressed() { actionBegin( PTPInputControllerActionJump ); }
    void buttonJumpReleased(){ actionEnd( PTPInputControllerActionJump ); }
    void buttonShootPressed() { actionBegin( PTPInputControllerActionShoot ); }
    void buttonShootReleased(){ actionEnd( PTPInputControllerActionShoot ); }
    void buttonRotateLeftPressed(){ actionBegin( PTPInputControllerActionRotateLeft ); }
    void buttonRotateLeftReleased(){ actionEnd( PTPInputControllerActionRotateLeft ); }
    void buttonRotateRightPressed(){ actionBegin( PTPInputControllerActionRotateRight );}
    void buttonRotateRightReleased(){ actionEnd( PTPInputControllerActionRotateRight ); }

    void buttonMoveRightPressed(){ actionBegin( PTPInputControllerActionMoveRight );}
    void buttonMoveRightReleased(){ actionEnd( PTPInputControllerActionMoveRight ); }
    void buttonMoveLeftPressed(){ actionBegin( PTPInputControllerActionMoveLeft );}
    void buttonMoveLeftReleased(){ actionEnd( PTPInputControllerActionMoveLeft ); }
    void buttonMoveUpPressed(){ actionBegin( PTPInputControllerActionMoveUp );}
    void buttonMoveUpReleased(){ actionEnd( PTPInputControllerActionMoveUp ); }
    void buttonMoveDownPressed(){ actionBegin( PTPInputControllerActionMoveDown );}
    void buttonMoveDownReleased(){ actionEnd( PTPInputControllerActionMoveDown ); }

    void buttonMotorCWPressed(){ actionBegin( PTPInputControllerActionMotorCW ); }
    void buttonMotorCWReleased(){ actionEnd( PTPInputControllerActionMotorCW); }
    void buttonMotorCCWPressed(){ actionBegin( PTPInputControllerActionMotorCCW); }
    void buttonMotorCCWReleased(){ actionEnd( PTPInputControllerActionMotorCCW); }

    void addCharacter(PTPObjectAssetCharacter* character);
    CCArray* characters();
    CCPoint charactersAveragePosition();

    void moveCharacters( float dx, float dy);

    void setMotors( std::list<b2RevoluteJoint *> );

    void addSpawner( PTPObjectAsset* object, PTPInputControllerAction action);
private:
    void actionBegin(PTPInputControllerAction action);
    void actionEnd(PTPInputControllerAction action);

    CCArray* _characters;
    std::list<b2RevoluteJoint *> _motors;
    typedef std::list<PTPObjectAsset*> PTPObjectAssetList;
    std::map<PTPInputControllerAction, PTPObjectAssetList> _spawnerObjects;

    CCTouch *_touchFire;
    CCTouch *_touchMove;

};

#endif // PTPINPUTCONTROLLER_H
