#pragma once

#ifndef ACTOR_H_
#define ACTOR_H_

#include"cocos2d.h"
#include"Component/Buff.h"
#include"Component/Debuff.h"
#include"Constant/Constant.h"
#include<iostream>

USING_NS_CC;

class Actor :public Sprite
{

    CC_SYNTHESIZE(int, _HP, HP);//生命值
    CC_SYNTHESIZE(int, _attack, Attack);//攻击力
    CC_SYNTHESIZE(bool, _alreadyDead, AlreadyDead);//判断是否已经死亡
    CC_SYNTHESIZE(float, _attackRadius, AttackRadius);//攻击范围半径
    CC_SYNTHESIZE(EAttackMode, _attactMode, AttackMode);//攻击方式
    CC_SYNTHESIZE(Actor*, _attactTarget, AttackTarget);//攻击目标
    CC_SYNTHESIZE(EDebuffType, _releaseDebuff, ReleaseDebuff);//释放Debuff的类型

public:
    virtual void takeDebuff(Debuff* debuff);//获得Debuff,Hero版本会重写,宠物版本会重写
    virtual void takeDamage(Actor* actor);//受到伤害,Hero和宠物会重写
    virtual void releaseDebuff(Actor* actor);//释放debuff
    virtual void releaseDamage(Actor* actor);//攻击
    

    virtual bool init(const std::string& filename);
    static Actor* create(const std::string& filename);
    void initData();
};


#endif // !ACTOR_H_



