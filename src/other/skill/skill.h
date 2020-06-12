#ifndef __SKILL_H__
#define __SKILL_H__

class skill
{
public:
	skill(int skill_id) : m_skill_id(skill_id) {}

	bool UpLevelSkill();
	bool Perform();
	bool ReplaceSkill(int skill_id);
	int GetSkillId() { return m_skill_id; }
	int GetSkillLevel() { return m_level; }
private:
	int m_skill_id = 0;
	int m_level = 0;
	int m_perform_interval = 0;
};

#endif
