#ifndef PTMODELGAMEOBJECT_H
#define PTMODELGAMEOBJECT_H

#include "models/PTModel.h"
#include "models/PTModelSpriteContainer.h"
#include "models/objects/PTModelObject.h"
#include "attributes/PTPAttributeShape.h"

class PTModelAsset : public PTModel {
public:
    PTModelAsset(CCString className, CCString name = CCString());

    virtual void initWithDictionary(CCDictionary *dict);
    virtual CCDictionary *getDictionary();

    virtual PTModelSpriteContainer *sprite();

    PTModelPolygon *collisionShape() const;
    PTPShapeType collisionShapeType() const;


    void addChild(PTModelObject *object);
    CCArray *children();

protected:
    void initializeCollisionShape(PTModelSpriteContainer *spriteContainer, PTModelPolygon *shapeModel);
    PTPAttributeShape *_collisionShapeAttribute;



};

#endif // PTMODELGAMEOBJECT_H
