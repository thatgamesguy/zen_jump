#ifndef PTMODELANIMATION_H
#define PTMODELANIMATION_H


#include "models/PTModel.h"
#include "models/objects/PTModelObject.h"

class PTModelAnimation : public PTModel {
public:
    PTModelAnimation();

    virtual CCDictionary *getDictionary();
    virtual void initWithDictionary(CCDictionary *dict);
    virtual void initConnectionsWithDictionary(CCDictionary *dict);

    virtual void cleanup();

    void clear();
    void addChild( PTModelObject *obj );
    void removeChild(PTModelObject *obj);
    int childrenCount();
    PTModelObject *childAt( int index);

    virtual void update(float dt);

#ifdef __QT__
    QPixmap spritePixmap();
    QRect spriteBoundingRect();
#endif

    float animationSpeed;
    float duration;
    void setLooped( bool looped);
    bool isLooped();


    static PTModel * create() {
        return new PTModelAnimation();
    }

private:
    CCArray *_children;

    bool _looped;
};


#endif // PTMODELANIMATION_H
