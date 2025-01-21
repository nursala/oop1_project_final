#include "GameObject/StaticObject.h"

bool StaticObject::checkIfstandAble()
{
	return m_standAble;
}

void StaticObject::setStandAble(bool standAble)
{
    m_standAble = standAble;
}
