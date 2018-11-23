#ifndef PTMODELBUTTON_H
#define PTMODELBUTTON_H

#include "PTModelObjectImage.h"
#include "attributes/PTPAttributeEnum.h"

class PTModelObjectButton : public PTModelObjectImage {
public:
    PTModelObjectButton(CCString className = "PTModelObjectButton");

    CCString action();
    PTPAttributeEnum* actionAttribute();

    virtual void initWithDictionary( cocos2d::CCDictionary *dict );
    virtual cocos2d::CCDictionary *getDictionary();

    static PTModel *PTSTDCALL create() {
        return new PTModelObjectButton();
    }

protected:
    PTPAttributeEnum *_actionAttribute;

};

#endif // PTMODELBUTTON_H
