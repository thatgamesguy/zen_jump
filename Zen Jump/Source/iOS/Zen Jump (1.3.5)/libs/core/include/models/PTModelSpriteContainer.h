#ifndef PTMODELSPRITECONTAINER_H
#define PTMODELSPRITECONTAINER_H

#include "PTModel.h"
#include "PTModelSprite.h"
#include "attributes/PTPAttributeFloat.h"
#include "attributes/PTPAttributePoint.h"

USING_NS_CC;

class PTModelSpriteContainer : public PTModel {
public:
    PTModelSpriteContainer(CCString name = CCString());

    virtual void initWithDictionary(CCDictionary *container);
    virtual void initConnectionsWithDictionary(CCDictionary *container);
    virtual CCDictionary *getDictionary();

    virtual void cleanup();

    PTModelSpriteContainer* duplicated();

    CCPoint pivot() const; //realted cooridnates of pivot point (related to 0,0 - origin)

    void addSpriteModel( PTModelSprite *sprite );
    PTModelSprite *spriteModelAtIndex( int index );
    int spriteModelsCount();       

    CCSize sourceSize();
    CCSize size();
    CCPoint offset();


    void setExcludeFromAtlas( bool value );
    bool isExcludeFromAtlas();

    CCSprite *getSprite(float animationSpeed = 1.0);
    CCTexture2D *getTexture();

    int count();

    static PTModel * create() {
        return new PTModelSpriteContainer();
    }

#ifdef __QT__
    static PTModelSpriteContainer *create(const QList<QUrl> &urls, bool excludeFromAtlas = false );
    void buildPixmap();
    QPixmap pixmap();
    void paint(QPainter *painter);
    void resetOffset();
#endif

private:
#ifdef __QT__
    void deleteSprites();
#endif

    void setPivot(const CCPoint &pivot);
    inline void setPivot(float x, float y);

    PTPAttributeFloat *_brightnessAttribute;
    PTPAttributeFloat *_contrastAttribute;
    PTPAttributeFloat *_hueAttribute;
    PTPAttributeFloat *_saturationAttribute;

    CCArray *_sprites;
    CCPoint _pivot;

    bool _excludeFromAtlas;

    friend class PTPAttributeAnimation;
    friend class PTDropImageWidget;
};

inline void PTModelSpriteContainer::setPivot(float x, float y) {
    setPivot(ccp(x, y));
}

#endif // PTMODELSPRITECONTAINER_H
