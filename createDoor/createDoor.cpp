#include "createDoor.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

//If you want to create a door in a scene,you need to include "createDoor.h"
//��������ڳ��������ϴ����ŵĶ���������Ҫinclude"createDoor.h"
//You should write like this:
//����Ҫ��ôд��

//auto door = setDoor(x,y,length);
//addChild(door);

Sprite* setDoor(float x,float y,float length)
{	

	auto door = Sprite::create("1.png");

	door->setPosition(x, y);

	auto spriteSize = door->getContentSize();
	float scaleSize = length / spriteSize.width;
	door->setScale(scaleSize);
	//door->setScale(1);

	auto doorcache = SpriteFrameCache::getInstance();
	doorcache->addSpriteFramesWithFile("door.plist");
	Vector<SpriteFrame*>vec;
	char name[20];
	memset(name, 0, 20);
	for (int i = 0; i < 17; i++)
	{
		sprintf(name, "door%04d", i);
		vec.pushBack(doorcache->getSpriteFrameByName(name));
	}
	Animation* doorAnimation = Animation::createWithSpriteFrames(vec, 0.1f);
	Animate* doorAnimate = Animate::create(doorAnimation);

	door->runAction(RepeatForever::create(doorAnimate));

	return door;
}