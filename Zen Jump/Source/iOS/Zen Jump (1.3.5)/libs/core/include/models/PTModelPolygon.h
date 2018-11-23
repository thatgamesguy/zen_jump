#ifndef PTMODELPOLYGON_H
#define PTMODELPOLYGON_H

#include "models/PTModel.h"
#include <list>
#include "cocos2d.h"
//#include "CCPointExtension.h"
#include "box2D/Common/b2Math.h"

class PTModelPolygon : public PTModel {
    static int DefaultNumberOfVertices;
    static int DefaultShapeWidth;
    static int DefaultShapeHeight;

public:
    explicit PTModelPolygon(CCString className = "PTModelPolygon", CCString name = CCString());

    virtual void initWithDictionary(CCDictionary *dict);
    virtual CCDictionary *getDictionary();

    // Appends new vertex to the end of verticies list
    virtual void addVertex(const CCPoint &point);
    inline void addVertex(float x, float y);

    // Inserts new vertex at specified index
    virtual void insertVertex(int index, const CCPoint &point);
    inline void insertVertex(int index, float x, float y);

    // Removes vertex at specified index
    virtual void removeVertex(int index);

    // Replaces vertex at index with new value
    virtual void setVertexAt(int index, const CCPoint &point);
    inline void setVertexAt(int index, float x, float y);

    // Removes all the verticies
    void clear();

    CCPoint vertexAt(int index) const;

    bool isEmpty() const;
    int vertexCount() const;

    // Allows to check if polygon is convex shape
    virtual bool isConvex() const;

    int copyVertexPoints(b2Vec2 *const points, int pointCount, float xScale, float yScale);

    // Initializes polygon with new box shape
    virtual void initialize(const CCSize &size = CCSize(), const CCPoint &pivot = CCPoint());
    inline void initialize(float width, float height, float pivotx ,float pivoty);

private:
    std::vector<CCPoint> _vertices;
};

inline void PTModelPolygon::addVertex(float x, float y) {
    addVertex(ccp(x, y));
}

inline void PTModelPolygon::insertVertex(int index, float x, float y) {
    insertVertex(index, ccp(x, y));
}

inline void PTModelPolygon::setVertexAt(int index, float x, float y) {
    setVertexAt(index, ccp(x, y));
}

inline void PTModelPolygon::initialize(float width, float height, float pivotx ,float pivoty) {
    initialize(CCSizeMake(width, height), CCPoint(pivotx, pivoty));
}

#endif // PTMODELPOLYGON_H
