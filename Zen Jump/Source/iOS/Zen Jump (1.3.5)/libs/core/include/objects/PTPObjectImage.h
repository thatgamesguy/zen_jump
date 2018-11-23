#ifndef PTPOBJECTIMAGE_H
#define PTPOBJECTIMAGE_H

#include "cocos2d.h"
#include "models/objects/PTModelObjectImage.h"
class PTPObjectImage : public CCNode
{
public:
    PTPObjectImage();
    static PTPObjectImage* create(PTModelObjectImage* model);
    virtual void update( float delta );
    void setModel(PTModelObjectImage* model);
    PTModelObjectImage* model();
private:
    PTModelObjectImage* _model;
};

#endif // PTPOBJECTIMAGE_H
