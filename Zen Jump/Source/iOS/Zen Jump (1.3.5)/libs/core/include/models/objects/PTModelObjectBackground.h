#ifndef PTMODELBACKGROUNDLAYER_H
#define PTMODELBACKGROUNDLAYER_H

#include "PTModelObject.h"
#include "attributes/PTPAttributeFloat.h"
#include "attributes/PTPAttributeSprite.h"

class PTModelObjectBackground : public PTModelObject {
public:
    PTModelObjectBackground(CCString name = "Untitled");    

    virtual PTModelSpriteContainer *sprite();

    virtual void setPosition( CCPoint pos );

    float time() const;
    float speed() const;
    float opacity() const;

    static PTModel *PTSTDCALL create() {
        return new PTModelObjectBackground();
    }

private:
    void setTime(float time);
    void setSprite(PTModelSpriteContainer *sprite);

    float _time;
    PTPAttributeFloat * _speedAttribute;
    PTPAttributeFloat *_opacityAttribute;
    PTPAttributeSprite *_contentSpriteAttribute;

    friend class PTGraphicsBackgroundLayer;
    friend class PTLevelEditorScreen;
};

#endif // PTMODELBACKGROUNDLAYER_H
