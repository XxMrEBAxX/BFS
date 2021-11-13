#include "Stack.h"

template <class T>
Stack<T>::~Stack()
{
	while (!isEmpty())
	{
		pop();
	}
}

template <class T>
void Stack<T>::push(T item)
{
	node<T>* inNode = new node<T>;
	inNode->data = item;
	inNode->next = m_top;
	m_top = inNode;
}

template <class T>
T Stack<T>::pop()
{
	assert(!isEmpty());

	node<T>* delNode = m_top;
	T retVal = m_top->data;

	m_top = m_top->next;
	delete delNode;
	return retVal;
}