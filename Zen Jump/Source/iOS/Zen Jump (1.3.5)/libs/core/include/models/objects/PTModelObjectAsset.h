#ifndef PTMODELOBJECTASSET_H
#define PTMODELOBJECTASSET_H

#include "PTModelObjectAsset.h"
#include "attributes/PTPAttributeAsset.h"
#include "attributes/PTPAttributeEnum.h"

class PTModelObjectAsset : public PTModelObject {
public:
    PTModelObjectAsset(CCString className = "PTModelObjectAsset");
    PTModelAsset *asset() const;
    void setAsset(PTModelAsset *asset);
    virtual PTModelSpriteContainer *sprite();

    PTModelPolygon *collisionShape();
    PTPShapeType collisionShapeType();

protected:
    PTPAttributeAsset   *_assetAttribute;
};

#endif // PTMODELOBJECTASSET_H
