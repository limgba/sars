#ifndef __COMMON_H__
#define __COMMON_H__
#include <assert.h>

template<typename Event>
constexpr bool IsValidate()
{
	static_assert(std::is_const<Event>::value == false, "struct must be without const");
	static_assert(std::is_volatile<Event>::value == false, "struct must be without volatile");
	static_assert(std::is_reference<Event>::value == false, "struct must be without reference");
	static_assert(std::is_pointer<Event>::value == false, "struct must be without pointer");
	return true;
}

#endif
