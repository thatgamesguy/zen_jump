#ifndef PTPATTRIBUTEFLOAT_H
#define PTPATTRIBUTEFLOAT_H

#include "PTPAttribute.h"
#include "PTAnimationCurve.h"

class PTPAttributeFloat : public PTPAttribute {
public:
    PTPAttributeFloat(CCObject *node, PTPAttributeValueType valueType = PTPAttributeValueVariable);

    virtual void initWithDictionary(CCDictionary *container);
    virtual CCDictionary *getDictionary();

    float value();
    void setValue(float value);

    int intValue();
    void setIntValue(int value);

    float variableValue() const;
    void setVariableValue(float variableValue);

    virtual void match(PTPAttribute *attribute);

    float minValue() const;
    void setMinValue(float);

    float maxValue() const;
    void setMaxValue(float);

    float bound(float) const;

private:
    void setKeyFrame(float value, float time);

    float _minValue;
    float _maxValue;

    float _value;
    float _variableValue;
    PTAnimationCurve *_animationCurve;

    friend class PTAnimationEditorWidget;
};

#endif // PTPATTRIBUTEFLOAT_H
