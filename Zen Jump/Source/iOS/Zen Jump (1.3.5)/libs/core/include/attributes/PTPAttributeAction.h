#ifndef PTPATTRIBUTEACTION_H
#define PTPATTRIBUTEACTION_H

#include "PTPAttribute.h"
#include "PTAnimationCurve.h"

#define PTPActionPointerSelector(_SELECTOR) (PTPActionPointer)(&_SELECTOR)

typedef void (CCObject::*PTPActionPointer)();

class PTPAttributeAction : public PTPAttribute {
public:
    PTPAttributeAction(CCObject *parent, PTPAttributeValueType valueType = PTPAttributeValueExact);

    void setValue(PTPActionPointer value);
    PTPActionPointer value();

    PTPAttribute *target();

    std::vector<int> keyFrameMarkers();

    virtual void update(float dt);

private:
    void setKeyFrame(bool enabled, float time);

    PTPActionPointer _value;
    PTAnimationCurve *_animationCurve;
};

#endif // PTPATTRIBUTEACTION_H
