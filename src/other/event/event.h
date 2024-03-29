#ifndef __EVENTBUS_H__
#define __EVENTBUS_H__

#include <memory>
#include <type_traits>
#include "common.h"
#include "callbackvector.h"

class EventBus
{
public:
	EventBus() = default;
	~EventBus()
	{
		m_callbacks.clear();
	}
	EventBus(const EventBus&) = delete;
	EventBus(EventBus&&) = delete;
	EventBus& operator=(const EventBus&) = delete;
	EventBus& operator=(EventBus&&) = delete;

	template<typename T>
	int listen(std::function<void(const T&)>& callback)
	{
		static_assert(IsValidate<T>(), "Invalid event");
		const int token = ++m_tokener;
		listen(token, callback);
		return token;
	}

	template<typename T>
	void listen(const int token, std::function<void(const T&)>& callback)
	{
		static_assert(IsValidate<T>(), "Invalid event");
		typedef TransactionCallBackVector<T> Vector;
		assert(callback);
		std::unique_ptr<CallBackVector>& vector = m_callbacks[typeid(T).hash_code()];
		if (NULL == vector)
		{
			vector.reset(new Vector{});
		}
		assert(dynamic_cast<Vector*>(vector.get()));
		Vector* vectorImpl = static_cast<Vector*>(vector.get());
		vectorImpl->add(token, callback);
	}

	void unlistenAll(const int token)
	{
		for (auto& pair : m_callbacks)
		{
			pair.second->remove(token);
		}
	}

	template<typename T>
	void unlisten(const int token)
	{
		static_assert(IsValidate<T>(), "Invalid event");
		auto found = m_callbacks.find(typeid(T).hash_code());
		if (found == m_callbacks.end())
		{
			return;
		}
		found->second->remove(token);
	}

	template<typename T>
	void notify(const T& event)
	{
		static_assert(IsValidate<T>(), "Invalid event");
		typedef typename std::remove_const<T>::type CleanEventType;
		typedef TransactionCallBackVector<CleanEventType> Vector;
		auto it = m_callbacks.find(typeid(CleanEventType).hash_code());
		if (it == m_callbacks.end())
		{
			return;
		}
		std::unique_ptr<CallBackVector>& vector = it->second;
		assert(dynamic_cast<Vector*>(vector.get()));
		Vector* vectorImpl = static_cast<Vector*>(vector.get());
		vectorImpl->beginTransaction();
		for (const auto& element : vectorImpl->m_container)
		{
			element.second(event);
		}
		vectorImpl->commitTransaction();
	}

private:
	int m_tokener = 0;
	std::map<type_id_t, std::unique_ptr<CallBackVector>> m_callbacks;

};

#endif
