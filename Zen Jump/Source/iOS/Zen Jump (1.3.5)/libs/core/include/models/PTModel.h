#ifndef PTMODEL_H
#define PTMODEL_H

#include "cocos2d.h"
#include "attributes/PTPAttribute.h"
#include "attributes/PTPAttributeString.h"
#include "attributes/PTPAttributeGroup.h"

USING_NS_CC;

class PTModel : public CCObject {
public:
    PTModel(CCString className, CCString name = CCString());
    ~PTModel();    

    virtual void initWithDictionary(CCDictionary *container);
    virtual CCDictionary *getDictionary();
    virtual void initConnectionsWithDictionary(CCDictionary *container);

    virtual void cleanup();

    int id() const;
    CCString name() const;

    CCString className() const;
    bool isKindOf(CCString className) const;

    float time() const;
    void setTime(float time);

    virtual void match(PTModel* model); //match current model with input model

    virtual void update(float dt);
    virtual void attributeDidUpdated(PTPAttribute *attr);
    virtual void attributeDidConnected(PTPAttribute *attr);
    virtual void attributeWillDisconnected(PTPAttribute *attr);

    PTPAttribute *addAttribute(const CCString &name,
                               PTPAttributeType type,
                               PTPAttributeValueType valueType = PTPAttributeValueExact,
                               PTPAttributeGroup *group = NULL,
                               PTPAttributeDirection direction = PTPAttributeInput,
                               bool connectable = false);
    int attributeCount() const;
    PTPAttribute *attributeAt(int index) const;

protected:
    void setName(const CCString &name);
    PTPAttributeString *_nameAttribute;

private:        
    CCString _className;
    CCArray *_attributes;

    unsigned int _id;
    float _time;

    friend class PTAnimationEditorWidget;
    friend class PTLevelEditorScreen;
};

#endif // PTMODEL_H
