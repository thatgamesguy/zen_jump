#ifndef PTMODELFONT_H
#define PTMODELFONT_H

#include "PTModel.h"
#include "PTFontCharacter.h"
#include "cocos2d.h"
#include <vector>


//TODO: NEED TO COMBINE PTMODELFONT WITH PTMODELATLAs becouse they pretty mych the same.
//or we need to inherit PTModelAtlas class at least

class PTPAttributePoint;
class PTPAttributeFloat;
class PTPAttributeString;
class PTPAttributeColor;
class PTPAttributeBoolean;

class PTModelFont : public PTModel {
    static ccColor4F DefaultFillColor;
    static ccColor4F DefaultStrokeColor;
    static ccColor4F DefaultGradientColor;
    static ccColor4F DefaultShadowColor;

public:
    PTModelFont();

    CCString fontName() const;
    void setFontName(const CCString &name);

    CCSize canvasSize() const;
    float fontSize() const;
    int padding() const;
    CCSize shadowOffset() const;
    float strokeWidth() const;

    bool drawShadow() const;
    bool drawStroke() const;
    bool drawGradient() const;

    std::vector<PTFontCharacter *> fontCharacters;

    CCLabelBMFont *getLabelFont();

    virtual void initWithDictionary( cocos2d::CCDictionary *dict );
    virtual cocos2d::CCDictionary *getDictionary();

    static PTModel * create() {
        return new PTModelFont();
    }

#ifdef __QT__
    QColor gradientColor() const;
    QColor fillColor() const;
    QColor strokeColor() const;
    QColor shadowColor() const;
    
    void buildFont();
#endif

private:
#ifdef __QT__
    void exportFont();
    void pack();
    void initializeFontCharacters();
#endif

    PTPAttributeString *_fontNameAttribute;
    PTPAttributeFloat *_fontSizeAttribute;

    PTPAttributePoint *_canvasSizeAttribute;
    PTPAttributePoint *_shadowOffsetAttribute;
    PTPAttributeFloat *_paddingAttribute;
    PTPAttributeFloat *_strokeWidthAttribute;

    PTPAttributeColor *_gradientColorAttribute;
    PTPAttributeColor *_fillColorAttribute;
    PTPAttributeColor *_strokeColorAttribute;
    PTPAttributeColor *_shadowColorAttribute;

    PTPAttributeBoolean *_drawShadowAttribute;
    PTPAttributeBoolean *_drawStrokeAttribute;
    PTPAttributeBoolean *_drawGradientAttribute;
};

static bool compareFontSpriteHeight(const void *p1, const void *p2);

#endif // PTMODELFONT_H
