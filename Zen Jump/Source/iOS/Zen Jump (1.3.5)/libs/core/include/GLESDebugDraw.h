/*
* Copyright (c) 2006-2007 Erin Catto http://www.gphysics.com
*
* iPhone port by Simon Oliver - http://www.simonoliver.com - http://www.handcircus.com
*
* This software is provided 'as-is', without any express or implied
* warranty.  In no event will the authors be held liable for any damages
* arising from the use of this software.
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
*/

//
// File modified for cocos2d integration
// http://www.cocos2d-iphone.org
//

#ifndef GLES_RENDER_H
#define GLES_RENDER_H

#include "cocos2d.h"

#ifdef __CC_PLATFORM_IOS
#include <OpenGLES/EAGL.h>
#elif defined(__CC_PLATFORM_MAC)
#include <OpenGL/OpenGL.h>

#endif




#include "Box2D/Box2D.h"

USING_NS_CC;

struct b2AABB;

struct GLESDebugDrawSettings
{
    GLESDebugDrawSettings() :
    hz(60.0f),
    velocityIterations(10),
    positionIterations(4),
    drawStats(0),
    drawShapes(1),
    drawJoints(1),
    drawAABBs(0),
    drawPairs(0),
    drawContactPoints(0),
    drawContactNormals(0),
    drawContactForces(0),
    drawFrictionForces(0),
    drawCOMs(0),
    enableWarmStarting(1),
    enableContinuous(1),
    pause(0),
    singleStep(0)
    {}

    float32 hz;
    int32 velocityIterations;
    int32 positionIterations;
    int32 drawShapes;
    int32 drawJoints;
    int32 drawAABBs;
    int32 drawPairs;
    int32 drawContactPoints;
    int32 drawContactNormals;
    int32 drawContactForces;
    int32 drawFrictionForces;
    int32 drawCOMs;
    int32 drawStats;
    int32 enableWarmStarting;
    int32 enableContinuous;
    int32 pause;
    int32 singleStep;
};

// This class implements debug drawing callbacks that are invoked
// inside b2World::Step.
class GLESDebugDraw : public b2Draw QGLFUNCTIONS
{
	float32 mRatio;
	CCGLProgram *mShaderProgram;
	GLint		mColorLocation;

	void initShader( void );
public:
	GLESDebugDraw();

	GLESDebugDraw( float32 ratio );

	void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);

	void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);

	void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color);

	void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color);

	void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);

	void DrawTransform(const b2Transform& xf);

    void DrawPoint(const b2Vec2& p, float32 size, const b2Color& color);

    void DrawString(int x, int y, const char* string, ...);

    void DrawAABB(b2AABB* aabb, const b2Color& color);
};


#endif // GLES_RENDER_H
