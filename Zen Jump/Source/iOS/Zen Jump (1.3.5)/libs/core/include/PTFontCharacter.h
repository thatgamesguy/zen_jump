#ifndef PTFONTCHARACTER_H
#define PTFONTCHARACTER_H

#include "models/PTModelSprite.h"
#include "cocos2d.h"

#ifdef __QT__

#include <QRect>
#include <QColor>
#include <QImage>
#include <QPoint>

#endif

class PTFontCharacter {
public:
    explicit PTFontCharacter();

    void draw();

    float fontSize;

    bool gradientEnabled;
    bool strokeEnabled;
    bool shadowEnabled;

    float advance;
    float strokeWidth;
    CCSize shadowOffset;

    PTModelSprite *sprite;

    int tag;

#ifdef __QT__

    void initWithString(const QString charatcer, QFont *font);

    QColor fillColor;
    QColor strokeColor;
    QColor gradientColor;
    QColor shadowColor;
    QRect rect;
    QImage image;

    QString symbol;
    QString fontName;

#endif
};

#endif // PTFONTCHARACTER_H
