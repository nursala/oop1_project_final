#pragma once

#include "GameObject/GameObject.h"

class StaticObject : public GameObject
{
public:
	StaticObject() = default;
	virtual ~StaticObject() = default;
	bool checkIfstandAble();
	void setStandAble(bool standAble);

	virtual void handleCollision(GameObject&)
	{ 
		std::cout << "Collision Stati detected\n";

	};
	virtual void handleCollision(Robot&) {};
	virtual void handleCollision(Wall&) {};
	virtual void handleCollision(Guard&) {};
	virtual void handleCollision(Rock&) {};
	virtual void handleCollision(Door&) {};
	//virtual void handleCollision(MovingObject&) = 0;
private:
	bool m_standAble = false;
};
