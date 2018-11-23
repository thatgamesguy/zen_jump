#ifndef PTPSCREENCOINSHOP_H
#define PTPSCREENCOINSHOP_H

#include "PTPScreen.h"

class PTPScreenCoinShop : public PTPScreen
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();

    CREATE_FUNC( PTPScreenCoinShop );

    void backButtonAction(CCObject* pSender);

};

#endif // PTPSCREENCOINSHOP_H
