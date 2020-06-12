#ifndef __CALLBACKVECTOR_H__
#define __CALLBACKVECTOR_H__

typedef size_t typeid_t;

class CallBackVector
{
public:
	void remove(const int token) = 0;
};

template<typename Event>
class TransactionCallBackVector : public CallBackVector
{
public:
	typedef std::function<void(const Event&)> CallBackType;
	typedef std::pair<int, CallBackType> ContainerElement;
	typedef std::vector<ContainerElement> ContainerType;
	ContainerType m_container;
	ContainerType m_to_add;
	std::vector<int> m_to_remove;
	int m_in_transaction;
	void remove(const int token)
	{
		if (m_in_transaction > 0)
		{
			m_to_remove.push_back(token);
			return;
		}
		auto remove_begin_it = std::remove_if(m_container.begin(), m_container.end(), [token](const ContainerElement& element) {
			return element.first == token;
		});
		if (remove_begin_it != m_container.end())
		{
			m_container.erase(remove_begin_it, m_container.end());
		}
	}

	void add(const int token, const CallBackType& callback)
	{
		if (m_in_transaction > 0)
		{
			m_to_add.emplace_back(token, callback);
		}
		else
		{
			m_container.emplace_back(token, callback);
		}
	}

	void beginTransaction()
	{
		++m_in_transaction;
	}

	void commitTransaction()
	{
		--m_in_transaction;
		if (m_in_transaction > 0)
		{
			return;
		}
		m_in_transaction = 0;
		if (!m_to_add.empty())
		{
			m_container.insert(m_container.end(), m_to_add.begin(), m_to_add.end());
			m_to_add.clear();
		}
		if (!m_to_remove.empty())
		{
			for (auto token : m_to_remove)
			{
				this->remove(token);
			}
			m_to_remove.clear();
		}
	}
};

#endif
