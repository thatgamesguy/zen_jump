#ifndef PTPATTRIBUTEPOINT_H
#define PTPATTRIBUTEPOINT_H

#include "PTPAttribute.h"
#include "PTAnimationCurve.h"

class PTPAttributePoint : public PTPAttribute {
public:
    PTPAttributePoint(CCObject *node, PTPAttributeValueType valueType = PTPAttributeValueVariable);

    virtual void initWithDictionary(CCDictionary *container);
    virtual CCDictionary *getDictionary();

    std::vector<int> keyFrameMarkers();

    CCPoint value();
    void setValue(const CCPoint &value);

    CCPoint variableValue() const;
    void setVariableValue(const CCPoint &value);

    virtual void match(PTPAttribute* attribute);

private:
    void setKeyFrame(CCPoint value, float time);

    CCPoint _variableValue;
    CCPoint _value;

    PTAnimationCurve *_animationCurveX;
    PTAnimationCurve *_animationCurveY;

    friend class PTAnimationEditorWidget;
};

#endif // PTPATTRIBUTEPOINT_H
