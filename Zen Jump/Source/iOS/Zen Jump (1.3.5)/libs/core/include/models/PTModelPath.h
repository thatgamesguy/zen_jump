#ifndef PTMODELPATH_H
#define PTMODELPATH_H

#include "models/PTModel.h"
#include <list>
#include "cocos2d.h"

class PTModelPath : public PTModel
{
public:
    PTModelPath();

    std::vector<CCPoint> vertices;
};

#endif // PTMODELPATH_H
