#ifndef COMMON_H
#define COMMON_H

#define Add(a, b) \
{\
	auto c = a + b;\
	if (c <= a)\
	{\
		return false;\
	}\
	a = c;\
	return true;\
}

#define Dec(a, b) \
{\
	auto c = a - b;\
	if (c >= a)\
	{\
		return false;\
	}\
	a = c;\
	return true;\
}

#endif
