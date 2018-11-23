#ifndef PTPATTRIBUTEBOOLEAN_H
#define PTPATTRIBUTEBOOLEAN_H

#include "PTPAttribute.h"

class PTPAttributeBoolean : public PTPAttribute
{
public:
    PTPAttributeBoolean(CCObject * parent, PTPAttributeValueType valueType = PTPAttributeValueExact);

    virtual void initWithDictionary(CCDictionary *container);
    virtual CCDictionary *getDictionary();

    bool value() const;
    void setValue(bool value);

    virtual void match(PTPAttribute *attribute);

private:
    bool _value;
};

#endif // PTPATTRIBUTEBOOLEAN_H
