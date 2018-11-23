#ifndef PTMODELSPRITE_H
#define PTMODELSPRITE_H


#include "PTModel.h"
#include "cocos2d.h"
#include "attributes/PTPAttributeFloat.h"

#ifdef __QT__
#include <QPoint>
#include <QPixmap>
#endif

USING_NS_CC;

class PTModelSprite : public PTModel {
public:
    PTModelSprite(CCString name = CCString());

    virtual void initWithDictionary(CCDictionary *container);
    virtual CCDictionary *getDictionary();

    virtual void cleanup();
    PTModelSprite* duplicated();

    // TODO: Encpsulate these members
    float brightness;
    float contrast;
    float hue;
    float saturation;

    cocos2d::CCPoint pos;

    void setOffset( CCPoint p );
    CCPoint offset();

    void setSize(CCSize size);
    CCSize size();

    void setSourceSize( CCSize size );
    CCSize sourceSize();

    cocos2d::CCRect sourceRect;

    CCSprite *getSprite();
    CCSpriteFrame *getSpriteFrame();

    static PTModel * create() {
        return new PTModelSprite();
    }

    void setExcludeFromAtlas( bool value );
    bool isExcludeFromAtlas();

    // QT spcific
#ifdef __QT__
    static PTModelSprite *create(const QUrl &url, bool excludeFromAtlas = false);

    void buildPixmap();
    QPixmap pixmap(); // image representation for Qt Editor
    void setPixmap(QPixmap);
    void paint(QPainter *painter);

    virtual bool isUsed( ) const;


#endif

private:

    CCPoint _offset;
    CCSize _sourceSize;
    CCSize _size;

    bool _exludeFromAtlas;

#ifdef __QT__
    void deleteSpriteFile();
    QPixmap _spritePixmap;
    QPixmap _spritePixmapOriginal;
#endif

    friend class PTModelSpriteContainer;
};

#endif // PTMODELSPRITE_H
