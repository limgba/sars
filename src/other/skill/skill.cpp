#include "skill.h"

bool skill::UpLevelSkill()
{
	++m_level;
	return true;
}

bool skill::Perform()
{
	if (m_perform_interval > 0)
	{
		return false;
	}
	m_perform_interval = 8;
	//get config by skill_id and perform
	return true;
}

bool skill::ReplaceSkill(int skill_id)
{
	m_skill_id = skill_id;
	return true;
}
