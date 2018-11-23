#ifndef PTPSCREENMAINMENU_H
#define PTPSCREENMAINMENU_H

#include "PTPScreen.h"

class PTPScreenMainMenu : public PTPScreen
{
public:

    virtual bool init();
    static cocos2d::CCScene* scene();

    CREATE_FUNC( PTPScreenMainMenu );

    void startButtonAction(CCObject* pSender);
};

#endif // PTPSCREENMAINMENU_H
