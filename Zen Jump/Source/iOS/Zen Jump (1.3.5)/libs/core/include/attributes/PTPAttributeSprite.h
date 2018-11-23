#ifndef PTPATTRIBUTESPRITE_H
#define PTPATTRIBUTESPRITE_H

#include "PTPAttribute.h"
#include "models/PTModelSprite.h"
#include "models/PTModelSpriteContainer.h"

class PTPAttributeSprite : public PTPAttribute {
public:
    PTPAttributeSprite(CCObject *node, PTPAttributeValueType valueType = PTPAttributeValueExact);

    virtual void initWithDictionary(CCDictionary *container);
    virtual void initConnectionsWithDictionary(CCDictionary *container);
    virtual CCDictionary *getDictionary();

    PTModelSpriteContainer *value() const;
    void setValue(PTModelSpriteContainer *value);

private:
    PTModelSpriteContainer *_value;
};

#endif // PTPATTRIBUTESPRITE_H
