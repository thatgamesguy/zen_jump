#ifndef PTPOBJECTBUTTON_H
#define PTPOBJECTBUTTON_H

#include "cocos2d.h"
using namespace cocos2d;
class PTPObjectButton : public CCMenuItemSprite
{
public:
    PTPObjectButton();
    static PTPObjectButton * create(CCNode* normalSprite, CCNode* selectedSprite, CCNode* disabledSprite = NULL);
    void setTarget(CCObject *rec, SEL_MenuHandler selectedSelector, SEL_MenuHandler unslectedSelector);
    void setTarget(CCObject *rec, SEL_MenuHandler selector);
    virtual void selected();

protected:
    SEL_MenuHandler    m_pfnSelectedSelector;
};

#endif // PTPOBJECTBUTTON_H
