#ifndef PTSRPITEATLASPACKNODE_H
#define PTSRPITEATLASPACKNODE_H

#include "cocos2d.h"

USING_NS_CC;

class PTSpriteAtlasPackNode
{

private:
    CCRect p_rect;

    PTSpriteAtlasPackNode* p_packNode_1;
    PTSpriteAtlasPackNode* p_packNode_2;

public:

    PTSpriteAtlasPackNode( CCSize size );
    PTSpriteAtlasPackNode( CCRect rect );

    PTSpriteAtlasPackNode* insert(PTSpriteAtlasPackNode *area);

    CCRect rect(){
        return p_rect;
    }

    float width(){
        return p_rect.size.width - p_rect.origin.x;
    }

    float height(){
        return p_rect.size.height - p_rect.origin.y;
    }

};

#endif // PTSRPITEATLASPACKNODE_H
