#ifndef PTMODELCIRCLE_H
#define PTMODELCIRCLE_H

#include "PTModelPolygon.h"

class PTModelCircle : public PTModelPolygon {
    static int DefaultCircleRadius;

public:
    explicit PTModelCircle();

    float radius() const;
    CCPoint centerPoint() const;

    virtual void addVertex(const CCPoint &point);
    virtual void insertVertex(int index, const CCPoint &point);
    virtual void removeVertex(int index);
    virtual void setVertexAt(int index, const CCPoint &point);

    virtual bool isConvex() const;
    virtual void initialize(const CCSize &size = CCSize(), const CCPoint &pivot = CCPoint());

private:
    void createCircle(float radius, CCPoint pivot = CCPoint());
};

#endif // PTMODELCIRCLE_H
