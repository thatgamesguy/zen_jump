#ifndef PTMODELOBJECTIMAGE_H
#define PTMODELOBJECTIMAGE_H

#include "attributes/PTPAttributeSprite.h"
#include "PTModelObject.h"

class PTModelObjectImage : public PTModelObject {
public:
    PTModelObjectImage(CCString className = "PTModelObjectImage");

    virtual void initWithDictionary( CCDictionary *container );
    virtual CCDictionary *getDictionary();

    virtual void update(float dt);
    float autohide();

    virtual PTModelSpriteContainer *sprite();
    PTPAttributeSprite *spriteAttribute();

    static PTModel *PTSTDCALL create() {
        return new PTModelObjectImage();
    }

private:
    PTPAttributeSprite *_spriteAttribute;
    PTPAttributeFloat *_autohideAttribute;
};

#endif // PTMODELOBJECTIMAGE_H
