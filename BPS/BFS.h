#pragma once
#include "Queue.h"
#include "Stack.h"

class BFS
{
	Stack<int> m_stack;
	Queue<int> m_queue;

	int sNode;
	int tNode;
public:
	BFS(int a, int b) : sNode(a), tNode(b) {}
	bool pathFinding();
	void draw();
};

