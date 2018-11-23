#ifndef PTMODELLEVELSECTION_H
#define PTMODELLEVELSECTION_H

#include "PTModel.h"
#include "attributes/PTPAttributeFloat.h"
#include "models/PTModelLinker.h"
#include "models/objects/PTModelObjectAssetUnit.h"

class PTModelLevelSection : public PTModel {
public:
    PTModelLevelSection(CCString name = "Untitled");
    ~PTModelLevelSection();

    virtual CCDictionary *getDictionary();
    virtual void initConnectionsWithDictionary(CCDictionary *container);

    float activeDistanceStart() const;
    float activeDistanceEnd() const;
    float width() const;

    virtual PTModelLevelSection *duplicated();

    bool isMuted();
    void setMuted( bool value );
    bool isSolo();
    void setSolo( bool value );

    bool isInitSection();
    void setInitSection( bool initSection );

    CCArray *children();
    void addModel( PTModelObjectAsset *model);

    CCArray *childLinkers();
    void addLinker( PTModelLinker *linker);

    static PTModel * create() {
        return new PTModelLevelSection();
    }    

    float _position;

private:
    void setActiveDistanceStart(float distance);
    void setActiveDistanceEnd(float distance);
    void setWidth(float width);

    bool _initSection;
    bool _muted;
    bool _solo;

    CCArray *_children;
    CCArray *_childLinkers;

    PTPAttributeFloat *_activeDistanceStartAttribute;
    PTPAttributeFloat *_activeDistanceEndAttribute;
    PTPAttributeFloat *_widthAttribute;

    friend class PTLevelEditorScreen;
    friend class PTLevelEditorSectionsEditor;

};

#endif // PTMODELLEVELSECTION_H
