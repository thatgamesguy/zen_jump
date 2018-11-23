//
//  GLESDEbugDrawLayer.h
//  ProjectMayhem
//
//  Created by Nik Rudenko on 12/10/12.
//
//

#ifndef __ProjectMayhem__GLESDEbugDrawLayer__
#define __ProjectMayhem__GLESDEbugDrawLayer__

#include <iostream>
#include "cocos2d.h"
#include "Box2D/Box2D.h"

class GLESDebugDrawLayer : public cocos2d::CCLayer
{
    
    public:

    b2World *world;
    virtual void draw( void );
    
	static cocos2d::CCScene* scene();
    
    CREATE_FUNC( GLESDebugDrawLayer );
};


#endif /* defined(__ProjectMayhem__GLESDEbugDrawLayer__) */
