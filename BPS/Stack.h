#pragma once
#include <cassert>

template <class T>
struct node
{
	T data;
	node<T>* next;
};
template <class T>
class Stack
{
	node<T>* m_top;
public:
	Stack() {}
	~Stack();
	void push(T item);
	T pop();
	T getTop() { return isEmpty() ? T() : m_top->data; }
	bool isEmpty() { return m_top == nullptr ? true : false; }
};
#include "Stack.inl"