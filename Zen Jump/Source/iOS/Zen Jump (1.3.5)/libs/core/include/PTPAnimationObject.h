#ifndef PTPANIMATIONOBJECT_H
#define PTPANIMATIONOBJECT_H

#include "cocos2d.h"
#include "attributes/PTPAttributeAnimation.h"
#include "models/PTModelAnimation.h"
#include "attributes/PTPAttributeAction.h"

class PTPAnimationObject : public CCNode {
public:
    PTPAnimationObject( PTModelAnimation *model);

    virtual void update(float delta);
    virtual void setParent(CCNode *parent);

    void setTime( float time );
    void reset();

    void setAnimationCallback(PTPActionPointer action, CCObject *target);

private:
    float _time;

    PTPActionPointer _actionPointer;
    CCObject *_actionTarget;

    PTModelAnimation *_model;
    std::map<PTModelObject *, CCNode *> _nodeMap;
};

#endif // PTPANIMATIONOBJECT_H
