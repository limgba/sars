#ifndef __ATTRIBUTE_H__
#define __ATTRIBUTE_H__

class Attribute
{
public:
	bool AddAttr(size_t index, long long attr);
	long long GetBaseAttr(size_t index);
	long long GetFightAttr(size_t index);
	void Reset();
	
private:
	long long m_attr[2][20];	// [0] fight, [1] base
};

#endif
