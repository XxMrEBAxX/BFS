#pragma once
template <class T>
class Queue
{
	T* m_queue;
	int m_front;
	int m_tail;
	int m_max;
	int m_size;
public:
	Queue(int m = 100) : m_front(0), m_tail(0), m_size(0), m_max(m)
	{
		m_queue = new T[m];
	}
	~Queue()
	{
		if (m_queue != nullptr)
			delete[] m_queue;
	}
	void enqueue(T item);
	T dequeue();
	bool isEmpty() { return m_size == 0; }
	bool isFull() { return m_size == m_max; }
	T getFront() { return isEmpty() ? T() : m_queue[m_front]; }
	int getSize() { return m_size; }
};
template <class T>
void Queue<T>::enqueue(T item)
{
	if (!isFull())
	{
		m_queue[m_tail] = item;
		m_tail = (m_tail + 1) % m_max;
		m_size++;
	}
	/*
	if (!isFull())
	{
		m_queue[m_tail] = item;
		m_tail++;
		if (m_tail == m_max)
			m_tail = 0;
	}
	*/
}
template <class T>
T Queue<T>::dequeue()
{
	if (!isEmpty())
	{
		int retVal = m_queue[m_front];
		m_front = (m_front + 1) % m_max;
		m_size--;
		return retVal;
	}
	return T();
}

template<class T>
struct Node
{
	T data;
	Node<T>* next;
};
template<class T>
class ListQueue
{
	Node<T>* m_front;
	Node<T>* m_tail;
	int m_size;
public:
	ListQueue() : m_size(0)
	{
		m_front = nullptr;
		m_tail = nullptr;
	}
	~ListQueue();

	void Enqueue(int data);
	T Dequeue();
	int GetSize() {return m_size;}
	bool IsEmpty() { return m_size == 0; }
	T getFront() { return m_front != nullptr ? m_front->data : T(); }
};
template<class T>
ListQueue<T>::~ListQueue()
{
	int a = GetSize();
	for (int i = 0; i < a; i++)
	{
		Dequeue();
	}
}
template<class T>
void ListQueue<T>::Enqueue(int data)
{
	if (!m_tail)
	{
		m_tail = new Node<T>;
		m_front = m_tail;
		m_tail->data = data;
		m_size++;
		return;
	}
	m_tail->next = new Node<T>;
	m_tail->next->data = data;
	m_tail = m_tail->next;
	m_size++;
}
template<class T>
T ListQueue<T>::Dequeue()
{
	if (m_size == 0) return T();

	int returnValue = m_front->data;
	Node<T>* deleteNode = m_front;
	m_front = m_front->next;
	if (m_size == 1)
		m_tail = nullptr;

	m_size--;
	delete deleteNode;
	return returnValue;
}