#ifndef PTPATTRIBUTESTRING_H
#define PTPATTRIBUTESTRING_H

#include "PTPAttribute.h"

class PTPAttributeString : public PTPAttribute {
public:
    PTPAttributeString(CCObject *node, PTPAttributeValueType valueType = PTPAttributeValueExact);

    virtual void initWithDictionary(CCDictionary *container);
    virtual CCDictionary *getDictionary();

    virtual void match(PTPAttribute* attribute);

    CCString value() const;
    void setValue(const CCString &value);

private:
    CCString _value;
};

#endif // PTPATTRIBUTESTRING_H
