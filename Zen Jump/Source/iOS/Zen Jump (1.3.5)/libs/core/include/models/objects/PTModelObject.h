#ifndef PTMODELOBJECT_H
#define PTMODELOBJECT_H

#include "cocos2d.h"
#include "models/PTModel.h"
#include "models/PTModelSprite.h"
#include "attributes/PTPAttributePoint.h"
#include "attributes/PTPAttributeFloat.h"
#include "attributes/PTPAttributeSprite.h"
#include "attributes/PTPAttributeBoolean.h"

#include <vector>

class PTModelObject : public PTModel {
public:
    PTModelObject(CCString className = "PTModelObject", CCString name = "Untitled");
    ~PTModelObject();

    virtual void initWithDictionary( cocos2d::CCDictionary *dict );
    virtual cocos2d::CCDictionary *getDictionary();

    virtual void attributeDidUpdated( PTPAttribute *attr );

    virtual PTModelObject* duplicated();

    virtual void setPosition( CCPoint pos);
    CCPoint position();

    // TODO: Encapsulate fields
    PTPAttributeFloat *rotation;
    PTPAttributePoint *scale;

    int zDepth() const;
    void setZDepth(int value);

    virtual bool isSpawner();
    virtual float spawnRate();

    //return sprite reperesentation
    virtual PTModelSpriteContainer *sprite();

    PTModelObject *parent() const;
    void setParent(PTModelObject *parent);    

    virtual CCSize contentSize();

    std::vector<int> keyframeMarkers();

    static PTModel *PTSTDCALL create() {
        return new PTModelObject();
    }       

protected:
    PTPAttributePoint *_position;

private:    
    int _zDepth;
    PTModelObject *_parent;        

    friend class PTAnimationEditorWidget;
};

#endif // PTMODELOBJECT_H
