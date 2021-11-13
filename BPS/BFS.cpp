#include "BFS.h"
#include <iostream>
#include <memory>
using namespace std;
int city[9][9] = {
	//   A  B  C  D  E  F  G  H  I
		{0, 1, 0, 0, 0, 0, 1, 0, 0}, // A
		{0, 0, 1, 0, 1, 0, 0, 0, 0}, // B
		{0, 0, 0, 1, 0, 0, 0, 0, 0}, // C
		{0, 1, 0, 0, 0, 0, 0, 0, 0}, // D
		{0, 0, 0, 0, 0, 1, 1, 0, 0}, // E
		{0, 0, 0, 0, 0, 0, 0, 0, 0}, // F
		{0, 0, 0, 0, 0, 0, 0, 1, 0}, // G
		{0, 0, 0, 0, 0, 0, 0, 0, 0}, // H
		{0, 0, 0, 0, 0, 0, 0, 1, 0}  // I
};

enum { UNIVISIT, VISIT };
char cityName[9] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };

#define MAXNODE 9
bool BFS::pathFinding()
{
	bool visitInfo[MAXNODE];
	int parent[MAXNODE]; // 백트래킹
	bool bFound = false;

	memset(visitInfo, UNIVISIT, sizeof(visitInfo));
	memset(parent, -1, sizeof(parent));

	m_queue.enqueue(sNode);
	visitInfo[sNode] = true;
	parent[sNode] = sNode;

	while (!m_queue.isEmpty())
	{
		int front = m_queue.getFront();
		m_queue.dequeue();
		if (front == tNode)
		{
			bFound = true;
			break;
		}
		for (int i = 0; i < MAXNODE; i++)
		{
			if (city[front][i] && visitInfo[i] == UNIVISIT)
			{
				m_queue.enqueue(i);
				visitInfo[i] = VISIT;
				parent[i] = front;
			}
		}
	}
	if (bFound)
	{
		int curNode = tNode;
		m_stack.push(curNode);
		do
		{
			curNode = parent[curNode];
			m_stack.push(curNode);
		} while (curNode != sNode);
	}
	return bFound;
}

void BFS::draw()
{
	while (!m_stack.isEmpty())
	{
		int cur = m_stack.pop();
		cout << cityName[cur];
		if (!m_stack.isEmpty())
			cout << " -> ";
	}
	cout << endl;
}
