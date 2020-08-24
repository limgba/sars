#ifndef __EVENTDEF_H__
#define __EVENTDEF_H__

struct question_confirm
{
	size_t qa_index = 0;
};

struct gamestatus_change
{
	int old_status = 0;
	int cur_status = 0;
};

#endif
