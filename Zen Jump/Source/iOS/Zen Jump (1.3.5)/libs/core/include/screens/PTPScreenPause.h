#ifndef PTPSCREENPAUSE_H
#define PTPSCREENPAUSE_H

#include "PTPScreen.h"

class PTPScreenPause : public PTPScreen
{

public:
    virtual bool init();
    static cocos2d::CCScene* scene();

    CREATE_FUNC( PTPScreenPause );

    void restartButtonAction(CCObject* pSender);
    void continueButtonAction(CCObject* pSender);
    void backButtonAction(CCObject* pSender);
    void upgradeButtonAction(CCObject* pSender);
    void coinshopButtonAction(CCObject* pSender);
};

#endif // PTPSCREENPAUSE_H
