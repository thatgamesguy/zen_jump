#ifndef PTPSCREEN_H
#define PTPSCREEN_H

#include "cocos2d.h"
#include "models/PTModelScreen.h"
#include "models/objects/PTModelObjectVector.h"
#include "objects/PTPObjectButton.h"

#define kRootCCMenuItemTag 100

class PTPScreen : public CCLayer
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();

    CREATE_FUNC( PTPScreen );

    PTModelScreen* model;

    bool load(const char* key);
    PTPObjectButton* getButton( const char* key );
    PTModelObjectVector* getVector( const char* key);
    void update(float dt);

protected:
    void powerupButtonAction(CCObject* sender);

    std::map<PTModelObject*, CCNode*> _objectMap;
};

#endif // PTPSCREEN_H
