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
		"刚想往前一步，车前突然横跳出一名壮汉挡住了你的去路，并竖起了中指",
		{
			{"回敬中指", 110},
			{"无视他， 绕开走过去", 111},
		},
	};
	qa_vec[102] = 
	{
		"咚，石头从车窗弹了下来， 反而惊醒了车内的人， 他打开车门， 瞧了瞧周围， 把断手接上， 吐口水抹了抹接口处的血， 便下车向你走来, 伸出刚接好的手， 似乎摆出了欢迎的姿势， 想和你握手",
		{
			{"欣然接受， 多个伙伴更安全", 114},
			{"退后一步, 质问他的来历", 115},
		},
	};
	qa_vec[103] = 
	{
		"掀起后备箱， 探头看看里面有什么工具， 却被里面的一直手掐住喉咙，隐约听见车窗拉了下来， 伴随低沉的声音：别挣扎了， 喊破喉咙也不会有人来救你了",
		{
			{"额头青筋暴起， 呼吸逐渐困难， 身体不自觉的提高了音调， 大喊：破喉咙， 破喉咙， 破喉咙", 104},
			{"顺着喉咙抓住他的指甲盖， 猛的一掀， 希望能有点效果", 105},
		},
	};
	qa_vec[104] = 
	{
		"如他所说， 喊破喉咙也没有用",
		{
			{"无法呼吸， 身体逐渐虚弱， 伴随着身体突然的蜷缩， 眼角渗出了泪水， 裤裆被染黄， 眼睛已无法再看到这个世界", 0},
		},
	};
	qa_vec[105] = 
	{
		"这似乎像一只没有知觉的假手， 被拔出指甲片的拇指血流不止， 手指的力气丝毫不减",
		{
			{"或许进入陌生区域的时候需要和同伴一起， 但这一切已经为时已晚， 生命结束于一只假手", 0},
		},
	};
	qa_vec[110] = 
	{
		"暗号对接成功, 壮汉递了一把匕首过来",
		{
			{"接过匕首", 112},
			{"拒绝他", 113},
		},
	};
	qa_vec[111] = 
	{
		"壮汉感到自己颜面无存，怒发冲冠， 原地旋转3圈之后， 砸来一个摆拳",
		{
			{"太阳穴凹下去一个拳头印子， 大脑眩晕不已， 倒地便不能再起", 0},
		},
	};
	qa_vec[112] = 
	{
		"正准备伸手接过匕首时， 他缓慢而有力的刺了过来",
		{
			{"躲开匕首", 0},
			{"相信他， 对队友的信任的重要的生存法则", 0},
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
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
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

