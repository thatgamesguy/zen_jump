#ifndef PTPSCREENGAMEFIELD_H
#define PTPSCREENGAMEFIELD_H


#include "models/objects/PTModelAssetPowerup.h"
#include "screens/PTPScreenScene.h"

class GLESDebugDrawLayer;
class PTPInputController;

class PTPScreenGameField : public PTPScreenScene {
    
public:
    static PTPScreenGameField *shared();
    ~PTPScreenGameField();
    
    virtual bool init();
    static cocos2d::CCScene *scene();
    virtual void update(float dt);
    
    CREATE_FUNC( PTPScreenGameField )
    
    virtual void onKeyDown( int keyCode );
    virtual void onKeyUp( int keyCode );
    virtual void ccTouchesBegan(cocos2d::CCSet *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchesMoved(cocos2d::CCSet *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchesEnded(cocos2d::CCSet *pTouch, cocos2d::CCEvent *pEvent);
    
    void setGameOverMode( bool gameOverMode );
    void setPauseMode( bool pauseMode );
    void pauseButtonAction( CCObject *sender );
    void restartButtonAction( CCObject *sender );
    
    void loadBackgroundObjects();
    
    void resetGameplay();
    void setDebugMode(bool enable);
    
    PTPInputController* inputController();
    
    void activatePowerup( PTModelAssetPowerup* powerup);
    
    void setPowerupMagnetMode( bool enabled );
    void setPowerupKillAllEnemy();
    void setPowerupCheckPoint( CCPoint point, int levelSectionId );
    void setPowerupNextCheckPoint();
    
    b2World* world();
    
private:
    
    PTModelLevelSection *getLevelSectionByDistance( float d );
    
    std::list<b2RevoluteJoint *> _jointMotorsList; //TODO: need to complitly move to inputController
    
    PTPInputController* _inputController;
    
    CCArray *_levelSectionModels;
    float _levelSectionCurentLength;
    
    bool _pauseMode;
    bool _gameOverMode;
    
    CCLabelBMFont *_distanceLabel;
    CCLabelBMFont *_coinsLabel;
    
    CCArray *_backgroundObjects;
    
    CCScene *_debugScene;
    
    float _levelSectionLength;
    
    //powerups
    bool _powerupMagnetMode;
    
};

#endif // PTPSCREENGAMEFIELD_H
