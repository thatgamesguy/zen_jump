#ifndef PTMODELOBJECTVECTOR_H
#define PTMODELOBJECTVECTOR_H

#include "PTModelObject.h"
#include "attributes/PTPAttributeAction.h"
#include "attributes/PTPAttributeEnum.h"

class PTModelObjectVector : public PTModelObject {
public:
    PTModelObjectVector();

    PTPAttributeEnum *actionAttribute;

    virtual CCSize contentSize();

    static PTModel *PTSTDCALL create() {
        return new PTModelObjectVector();
    }
};

#endif // PTMODELOBJECTVECTOR_H
