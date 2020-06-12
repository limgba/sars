#ifndef __EVENTBUS_H__
#define __EVENTBUS_H__

#include <memory>
#include <map>
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

	template<typename Event>
	int listen(std::function<void(const Event&)>& callback)
	{
		static_assert(IsValidate<Event>(), "Invalid event");
		const int token = ++m_tokener;
		listen(token, callback);
		return token;
	}

	template<typename Event>
	void listen(const int token, std::function<void(const Event&)>& callback)
	{
		static_assert(IsValidate<Event>(), "Invalid event");
		typedef TransactionCallBackVector<Event> Vector;
		assert(callback);
		std::unique_ptr<CallBackVector>& vector = m_callbacks[typeid(Event).hash_code()];
		if (NULL == vector)
		{
			vector.reset(new Vector{});
		}
		assert(dynamic_cast<Vector*>(vector.get());
		Vector* vectorImpl = static_cast<Vector*>(vector.get());
		vectorImpl->add(token, callback);
	}

	void unlistenAll(const int token)
	{
		for (auto& pair : m_callbacks)
		{
			element.second->remove(token);
		}
	}

	template<typename Event>
	void unlisten(const int token)
	{
		static_assert(IsValidate<Event>(), "Invalid event");
		auto found = m_callbacks.find(typeid(Event).hash_code());
		if (found == m_callbacks.end())
		{
			return;
		}
		found->second->remove(token);
	}

	template<typename Event>
	void notify(const Event& event)
	{
		static_assert(IsValidate<Event>(), "Invalid event");
		typedef typename std::remove_const<Event>::type CleanEventType;
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
	template<typename Event>
	bool IsValidate()
	{
		static_assert(std::is_const<Event>::value == false, "struct must be without const");
		static_assert(std::is_volatile<Event>::value == false, "struct must be without volatile");
		static_assert(std::is_reference<Event>::value == false, "struct must be without reference");
		static_assert(std::is_pointer<Event>::value == false, "struct must be without pointer");
		return true;
	}

private:
	int m_tokener = 0;
	std::map<type_id_t, std::unique_ptr<CallBackVector>> m_callbacks;

};

#endif
