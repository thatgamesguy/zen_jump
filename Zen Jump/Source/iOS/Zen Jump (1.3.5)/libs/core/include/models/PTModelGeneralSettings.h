#ifndef PTMODELGENERALSETTINGS_H
#define PTMODELGENERALSETTINGS_H

#include "PTModel.h"
#include "attributes/PTPAttributeSprite.h"
#include "attributes/PTPAttributeBoolean.h"
#include "attributes/PTPAttributeEnum.h"

typedef enum {
    PTObjectFrameEdgeStatePass = 0,
    PTObjectFrameEdgeStateBlock,
    PTObjectFrameEdgeStateKill,
    PTObjectFrameEdgeStateCount

} PTObjectFrameEdgeState;

typedef enum {
    PTPScreenOrientationLandscape = 0,
    PTPScreenOrientationPortrait,
} PTPScreenOrientation;

class PTModelGeneralSettings : public PTModel {
public:
    PTModelGeneralSettings();
    ~PTModelGeneralSettings();

    static PTModelGeneralSettings* shared();
    PTPScreenOrientation orientation();
    float gameplayAngleDirection();

    virtual void initWithDictionary( CCDictionary *dict );
    virtual cocos2d::CCDictionary *getDictionary();

    void assignGampePreset(CCDictionary* dict);

    unsigned int lastIdNumber;

    CCString *versionNumber;
    CCString *applicationName;
    CCString *nameOnDevice;
    CCString *bundleId;
    CCString *comments;

    float gameAngle;
    float gameSpeedMin;
    float gameSpeedMax;
    float gameSpeedCurrent;
    float gameSpeedIncrease;

    PTPAttributeSprite *iconAttribute;

    CCPoint moveSpeed() const;
    void setMoveSpeed(float x, float y);
    void setFixedRotation( bool fixedRotation );
    bool isFixedRotation() const;
    void setFixedPosition( bool fixedPosition );
    bool isFixedPosition() const;
    CCPoint upForce() const;
    void setUpForce( CCPoint value);
    float upForceDuration() const;
    void setUpForceDuration(float value);
    float upForceCounter() const;
    void setUpForceCounter(float value);
    float leftLeanForce() const;
    void setLeftLeanForce(float value);
    float rightLeanForce() const;
    void setRightLeanForce(float value);
    float simulationTimeScale();
    void setSimulationTimeScale( float value);
    CCPoint characterFriction();
    void setCharacterFriction( CCPoint value);
    float friction();
    void setFriction( float value );
    float velocityScale();
    void setVelocityScale( float value  );

    void setRestitution( float );
    float restitution() const;

    void setScoreMultiplier( float );
    float scoreMultiplier() const;

    float platformFriction() const;

    bool autoImageDirection();
    void setAutoImageDirection( bool autoImageDirection );

    void setBounceForce( CCPoint value);
    CCPoint bounceForce();

    bool isUpForceFromGround();
    void setUpForceFromGround( bool upForceFromGround );

    float rotationScale();
    void setRotationScale( float rotationScale );

    void setGravity( CCPoint value);
    CCPoint gravity();

    void setObjectFrameRect( CCRect rect );
    CCRect objectFrameRect();

    PTObjectFrameEdgeState objectFrameEdgeState( int edgeIndex );
    void setObjectFrameEdgeState(int edgeIndex, PTObjectFrameEdgeState state);

    static PTModel * create() {
        return new PTModelGeneralSettings();
    }


    PTPAttributeString *gamePresetName;
    CCString *ibVersion() const;
    void setIbVersion(CCString *ibVersion);

    CCSize designResolution();

    const char* platformValue(const std::string &platform, const std::string &key) const;
    void setPlatformValue(const std::string &platform, const std::string &key, const std::string &value);

private:
    CCString *_ibVersion;

    PTPScreenOrientation _orientation;
    float _gameplayAngleDirection;

    CCSize _designResolution;

    PTPAttributePoint *_gravityAttribute;
    PTPAttributePoint *_moveSpeedAttribute;
    PTPAttributePoint *_bounceForceAttribute;
    PTPAttributePoint *_upForceAttribute;
    PTPAttributeFloat *_upForceDurationAttribute;
    PTPAttributeFloat *_upForceCounterAttribute;
    PTPAttributeFloat *_leftLeanForceAttribute;
    PTPAttributeFloat *_rightLeanForceAttribute;
    PTPAttributeFloat *_simulationTimeScaleAttribute;
    PTPAttributeFloat *_frictionAttribute;
    PTPAttributePoint *_characterFrictionAttribute;
    PTPAttributeFloat *_velocityScaleAttribute;
    PTPAttributeFloat *_rotationScaleAttribute;
    PTPAttributeFloat *_restitutionAttribute;
    PTPAttributeFloat *_platformFriction;
    PTPAttributeFloat *_scoreMultiplierAttribute;

    CCRect _objectFrameRect;

    PTObjectFrameEdgeState _objectFrameEdgeState[ 4 ];
    PTPAttributeBoolean *_upForceFromGroundAttribute;
    PTPAttributeBoolean *_fixedRotationAttribute;
    PTPAttributeBoolean *_fixedPositionAttribute;
    PTPAttributeBoolean *_autoImageDirectionAttribute;


    CCDictionary* _platformSpecificValues;

    void dumpAttributes();

    friend class PTPreferenceScreenGameplay;
    friend class PTPreferenceScreenProject;
    friend class PTPreferenceScreenFrame;
};

#endif // PTMODELGENERALSETTINGS_H
