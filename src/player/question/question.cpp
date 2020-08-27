#include "question.h"
#include "../player.h"
#include <iostream>


Question::Question() : qa_vec(200, qa("",{}))
{
	qa_index = 0;
	this->init_event();
	qa_vec[0] = 
	{
		"2100年，人类被一种名为“根”的超级细菌侵害着, 你所处的城市叫做G城",
		{
			{"根是什么", 1},
			{"进入G城", 2},
		},
	};
	qa_vec[1] = 
	{
		"根的起源目前仍然是未知数，人们只知道被根感染的人会体力大增， 最后身体瘦成木乃伊般死去",
		{
			{"太可怕了", 0},
		},
	};
	qa_vec[2] = 
	{
		"你来到了G城， 左手边有一家便利店，店员望向天花板, 眼神略显呆滞， 右手边是停车场, 车窗布满了灰尘， 似乎可以进车里躲起来",
		{
			{"店员为何会变成这样， 带着疑惑进入便利店", 3},
			{"走向停车场", 4},
			{"继续前进", 5},
		},
	};
	qa_vec[3] = 
	{
		"你来到门前， 刚想伸手推门， 你听到了‘嗞嗞嗞’的声音， 门自己缓缓打开了",
		{
			{"迅速缩回右手， 逃离便利店", 2},
			{"镇静走入便利店", 10},
		},
	};
	qa_vec[4] = 
	{
		"你径直走向停车场，一步两步，车窗的尘埃一层层的掉，隐约能看见车内有......",
		{
			{"一只断手， 车内还有人在痛苦的挣扎", 100},
			{"靠近车门可能会有危险， 远离跑车", 101},
		},
	};
	qa_vec[5] = 
	{
		"在这广阔无垠的大地竟没有一个人， 这份寂静，不禁让人耸起肩膀",
		{
			{"感慨之际，脚背似乎还有点暖", 6},
		},
	};
	qa_vec[6] = 
	{
		"寒冷寂静的大地上， 竟然多了一份温暖，可这只右脚似乎走不动了，你低头看了看，膝盖被钢筋刺穿，生存下去的机会变得渺茫",
		{
			{"还没来得及看是谁在背后动的手， 视线已经越来越模糊， 身体已经感觉不到痛， 大口呼吸， 满脸青筋依然缺氧， 你倒在了这片看似平静的大地上， 闭眼回顾这精彩的一生", 0},
		},
	};
	qa_vec[10] = 
	{
		"寒冷寂静的大地上， 竟然多了一份温暖，可这只右脚似乎走不动了，你低头看了看，膝盖被钢筋刺穿，生存下去的机会变得渺茫",
		{
			{"还没来得及看是谁在背后动的手， 视线已经越来越模糊， 身体已经感觉不到痛， 大口呼吸， 满脸青筋依然缺氧， 你倒在了这片看似平静的大地上， 闭眼回顾这精彩的一生", 0},
		},
	};
	qa_vec[100] = 
	{
		"车门紧锁， 你得想个办法把门打开",
		{
			{"拾起地下的石头，往后撤退几步，一个箭步往里砸", 102},
			{"车的后备箱微微翘起， 去看看有没有可以用的工具", 103},
		},
	};
	qa_vec[101] = 
	{
		"刚想往前一步，车前突然横跳出一名壮汉挡住了你的去路，并摆出了国际友好手势， 看来免不了一战",
		{
			{"迎接战斗", 110},
			{"抱头鼠窜", 111},
		},
	};
}

void Question::init_event()
{
	{
		std::function<void(const question_confirm&)> f = [this](const auto& e)
		{
			SetChoose(m_player, 0);
			m_player->OnConfirm(e.qa_index);
		};
		event_bus.listen(f);
	}
}

void Question::display(size_t choose)
{
	if (qa_index < 0 || qa_index >= qa_vec.size())
	{
		return;
	}
	system("clear");
	const auto& qa = qa_vec[qa_index];
	std::cout << qa.q << std::endl;
	for (size_t i = 0; i < qa.a_vec.size(); ++i)
	{
		if (i == choose)
		{
			std::cout << ">";
		}
		else
		{
			std::cout << " ";
		}
		std::cout << qa.a_vec[i].a << std::endl;
	}
}

bool Question::confirm(size_t choose)
{
	if (qa_index < 0 || qa_index >= qa_vec.size())
	{
		return false;
	}
	const auto& qa = qa_vec[qa_index];
	if (choose >= qa.a_vec.size())
	{
		return false;
	}
	const size_t next_index = qa.a_vec[choose].next;
	if (next_index >= qa_vec.size())
	{
		return false;
	}
	const auto& next_qa = qa_vec[next_index];
	if (next_qa.q.empty() || next_qa.a_vec.empty())
	{
		return false;
	}
	
	qa_index = next_index;
	event_bus.notify(question_confirm{qa_index, choose});
	return true;
}

size_t Question::GetChooseSize()
{
	if (qa_index < 0 || qa_index >= qa_vec.size())
	{
		return 0;
	}
	const auto& qa = qa_vec[qa_index];
	return qa.a_vec.size();
}

