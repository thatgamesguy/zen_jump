#ifndef PTMODELSCREEN_H
#define PTMODELSCREEN_H

#include "models/PTModel.h"
#include "models/objects/PTModelObject.h"
#include "attributes/PTPAttributeEnum.h"
#include "Attributes/PTPAttributeSound.h"

class PTModelScreen : public PTModel
{
public:
    PTModelScreen(CCString name = "Untitled");
    ~PTModelScreen();

    virtual void initWithDictionary( cocos2d::CCDictionary *dict );
    virtual void initConnectionsWithDictionary(CCDictionary *dict);
    virtual cocos2d::CCDictionary* getDictionary();

    CCString* key;

    CCString adNetworkFullscreen();
    CCString adNetworkBanner();

    int adFullscreenFrequency();
    int adBannerFrequency();

    PTModelSound *backgroundMusic() const;
    void setBackgroundMusic(PTModelSound *value);

    CCString backgroundLevelSection();
    PTPAttributeEnum* backgroundLevelSectionAttribute();

    bool loopMusic() const;
    void setLoopMusic(bool value);

    int childrenCount();
    void addChild(PTModelObject* model);
    CCArray* children();

    bool isMuted();
    void setMuted( bool value );

    static PTModel *  create(){
        return new PTModelScreen();
    }

    int adFullscreenFrequencyCounter;
    int adBannerFrequencyCounter;

private:
    CCArray* _children;
    PTPAttributeEnum* _adNetworkBannerAttribute;
    PTPAttributeEnum* _adNetworkFullscreenAttribute;

    PTPAttributeFloat* _adFullscreenFrequencyAttribute;
    PTPAttributeFloat* _adBannerFrequencyAttribute;

    PTPAttributeSound *_backgroundMusic;
    PTPAttributeBoolean *_loopBackgroundMusic;
    PTPAttributeEnum *_backgroundLevelSectionAttribute;

    bool _muted;
};

#endif // PTMODELSCREEN_H
