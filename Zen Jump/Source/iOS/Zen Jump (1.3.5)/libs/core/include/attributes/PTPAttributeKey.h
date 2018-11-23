#ifndef PTPATTRIBUTEKEY_H
#define PTPATTRIBUTEKEY_H

#include "PTPAttribute.h"

class PTPAttributeKey : public PTPAttribute {
public:
    PTPAttributeKey(CCObject *node, PTPAttributeValueType valueType = PTPAttributeValueExact);

    virtual void initWithDictionary(CCDictionary *container);
    virtual CCDictionary *getDictionary();

    virtual void match(PTPAttribute *attribute);

    int value() const;
    void setValue(int value);

private:
    int _value;
};

#endif // PTPATTRIBUTEKEY_H
