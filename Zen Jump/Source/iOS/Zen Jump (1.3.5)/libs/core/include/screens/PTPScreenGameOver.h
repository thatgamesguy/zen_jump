#ifndef PTPSCREENGAMEOVER_H
#define PTPSCREENGAMEOVER_H

#include "PTPScreen.h"

class PTPScreenGameOver : public PTPScreen
{
public:

    virtual bool init();
    static cocos2d::CCScene* scene();

    CREATE_FUNC( PTPScreenGameOver );

    void restartButtonAction(CCObject* pSender);
    void backButtonAction(CCObject* pSender);
    void upgradeButtonAction(CCObject* pSender);
    void coinshopButtonAction(CCObject* pSender);
};

#endif // PTPSCREENGAMEOVER_H
