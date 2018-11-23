#ifndef PTNODE_H
#define PTNODE_H

#include "models/PTModel.h"
#include "attributes/PTPAttributeAction.h"
#include "models/PTModelScreen.h"

class PTNode : public PTModel {
public:
    PTNode(CCString name = "PTNode");

    PTModel* model();
    void setModel( PTModel* model);
    void setInputActionConnectable(bool arg);

private:
    PTModel *_model;
    PTPAttributeAction* _inputAction;
};

#endif // PTPNODESCENE_H
