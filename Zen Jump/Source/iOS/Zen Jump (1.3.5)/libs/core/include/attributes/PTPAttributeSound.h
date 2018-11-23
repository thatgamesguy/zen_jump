#ifndef PTPATTRIBUTESOUND_H
#define PTPATTRIBUTESOUND_H

#include "PTPAttribute.h"

class PTModelSound;

class PTPAttributeSound : public PTPAttribute
{
public:
    PTPAttributeSound(CCObject *node, PTPAttributeValueType valueType = PTPAttributeValueExact);

    virtual void initConnectionsWithDictionary(CCDictionary *container);
    virtual CCDictionary *getDictionary();

    PTModelSound *value() const;
    void setValue(PTModelSound *value);

private:
    PTModelSound *_value;
};

#endif // PTPATTRIBUTESOUND_H
