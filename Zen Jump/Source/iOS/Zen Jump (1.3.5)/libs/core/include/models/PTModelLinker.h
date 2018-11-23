#ifndef PTMODELLINKER_H
#define PTMODELLINKER_H

#include "PTModel.h"
#include "models/objects/PTModelObject.h"
#include "attributes/PTPAttributeFloat.h"
#include "attributes/PTPAttributeBoolean.h"

class PTModelLinker : public PTModel {
public:
    PTModelLinker();

    virtual void initConnectionsWithDictionary(CCDictionary *container);
    virtual CCDictionary *getDictionary();

    virtual PTModelLinker *duplicated();

    PTModelObject *objectA;
    PTModelObject *objectB;

    void setSpeed(float);
    float speed() const;
    void setTorgue(float);
    float torque() const;
    bool isControlled() const;
    void setControlled( bool controlled );

    static PTModel * create() {
        return new PTModelLinker();
    }

private:
    PTPAttributeFloat *_speedAttribute;
    PTPAttributeFloat *_torqueAttribute;
    PTPAttributeBoolean *_controlledAttribute;
};

#endif // PTMODELLINKER_H
