#ifndef PTMODELOBJECTBUTTONPOWERUP_H
#define PTMODELOBJECTBUTTONPOWERUP_H

#include "PTModelObjectButton.h"

class PTModelObjectButtonPowerup : public PTModelObjectButton
{
public:
    PTModelObjectButtonPowerup(CCString className = "PTModelObjectButtonPowerup");

    CCPoint labelOffset();
    CCString actionType();
    bool isUnlimitedUse();

    static PTModel *PTSTDCALL create() {
        return new PTModelObjectButtonPowerup();
    }

private:
    PTPAttributeEnum *_actionTypeAttribute;
    PTPAttributePoint* _labelOffsetAttribute;
    PTPAttributeBoolean* _unlimitedUseAttribute;
};

#endif // PTMODELOBJECTBUTTONPOWERUP_H
