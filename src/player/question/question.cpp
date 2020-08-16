#include "question.h"
#include <iostream>


Question::Question() : qa_vec(100, qa("",{}))
{
	qa_index = 0;
	this->init_event();
	qa_vec[0] = 
	{
		"2100年，人类被一种名为“根”的超级细菌侵害着, 你所处的城市叫做G城",
		{
			{"根是什么", 1},
			{"进入G城", 2},
			{"寻找同伴", 3},
			{"搜寻武器", 4},
		},
	};
}

void Question::init_event()
{
	{
		std::function<void(const question_confirm&)> f = [this](const auto& e)
		{
			this->display(e.qa_index);
		};
		event_bus.listen(f);
	}
}

void Question::display(size_t choose)
{
	const auto& qa = qa_vec[qa_index];
	std::cout << qa.q << std::endl;
	for (size_t i = 0; i < qa.a_vec.size(); ++i)
	{
		if (i == choose)
		{
			std::cout << ">";
		}
		std::cout << qa.a_vec[i].a << std::endl;
	}
}

bool Question::confirm(size_t choose)
{
	auto& qa = qa_vec[qa_index];
	if (choose >= qa.a_vec.size())
	{
		return false;
	}
	qa_index = qa.a_vec[choose].next;
	event_bus.notify(question_confirm{qa_index});
	return true;
}
