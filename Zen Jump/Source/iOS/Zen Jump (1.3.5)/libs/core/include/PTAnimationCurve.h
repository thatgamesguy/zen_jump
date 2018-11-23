#ifndef PTANIMATIONCURVE_H
#define PTANIMATIONCURVE_H

#include "cocos2d.h"

USING_NS_CC;

typedef struct
{
    float	hdl1;
    CCPoint	knot;
    float	hdl2;

} bez3;

typedef enum
{
    PTAnimationCurveInterpolationConstant = 0,
    PTAnimationCurveInterpolationLinear,
    PTAnimationCurveInterpolationBizer

} PTAnimationCurveInterpolationType;

typedef enum
{
    PTAnimationCurveExtrapolationConstant = 0,
    PTAnimationCurveExtrapolationExtrapolation,
    PTAnimationCurveExtrapolationCyclic,
    PTAnimationCurveExtrapolationCyclicExtrapolation

} PTAnimationCurveExtrapolationType;


class PTAnimationCurve
{
public:
    PTAnimationCurve();

    PTAnimationCurveExtrapolationType extrapolation;
    PTAnimationCurveInterpolationType interpolation;

    float time;

    void updated(float dt);
    float cubicBezier(float t, float a, float b, float c, float d);
    void calculateRatio();
    void reset();
    void setPoints( bez3 *points );
    void setValue(float _value, float _time);
    float value(float _time);
    float value();
    void removePoint(float _time);

    std::vector<int> keyFrameMarkers();

private:
    float tRatio;
    float vRatio;
    float tvRatio;
    int currentPoint;
    float deltaTime;
    bez3 *pPoints;
    unsigned int pNumberOfPoints;
    float pValue;
};

#endif // PTANIMATIONCURVE_H
