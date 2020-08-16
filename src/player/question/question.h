#ifndef __QUESTION_H__
#define __QUESTION_H__
#include <string>
#include <vector>
#include "../../other/event/event.h"
#include "../../other/event/eventdef.h"

struct a_next
{
	a_next(const std::string& a, const size_t& next)
	{
		this->a = a;
		this->next = next;
	}
	std::string a;
	size_t next = 0;
};

struct qa
{
	qa(const std::string& q, const std::vector<a_next>& a_vec)
	{
		this->q = q;
		this->a_vec = a_vec;
	}
	std::string q;
	std::vector<a_next> a_vec;
};

class Question
{
public:
	Question();
	void init_event();
	void display(size_t choose);
	bool confirm(size_t choose);


private:
	size_t qa_index;
	std::vector<qa> qa_vec;
	EventBus event_bus;
};

#endif
