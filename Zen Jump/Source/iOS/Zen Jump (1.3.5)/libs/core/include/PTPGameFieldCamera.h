#ifndef PTPGAMEFIELDCAMERA_H
#define PTPGAMEFIELDCAMERA_H

#include "cocos2d.h"
#include "models/PTModelGeneralSettings.h"

class PTPGameFieldCamera : public CCNode {
public:
    PTPGameFieldCamera();
    static PTPGameFieldCamera *create();

    void reset();

    virtual void update(float delta);

    void setFocusPoint( CCPoint point );

    CCPoint deltaMove();

private:
    CCPoint fitPointInRect(CCPoint p, CCRect rect);
    CCPoint _focusPoint;
    CCRect _focusRect;
    CCPoint _deltaMove;

    PTModelGeneralSettings* _settings;

};

#endif // PTPGAMEFIELDCAMERA_H
