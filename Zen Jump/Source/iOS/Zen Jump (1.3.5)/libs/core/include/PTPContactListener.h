//
//  ContactListener.h
//  PZPlayer
//
//  Created by Nik Rudenko on 6/24/12.
//  Copyright (c) 2012 Kayabit. All rights reserved.
//

#ifndef PTPContactListener_h
#define PTPContactListener_h

#include "box2D/Box2D.h"

class PTPContactListener : public b2ContactListener
{
    
public:
    PTPContactListener();
	virtual void BeginContact( b2Contact* contact);
    virtual void EndContact(b2Contact* contact);
	virtual void PreSolve( b2Contact* contact, const b2Manifold* oldManifold);
    
};


#endif
