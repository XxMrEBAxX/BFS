#include "Queue.h"
#include "BFS.h"
#include <iostream>

int main()
{
	BFS bfs(0, 5);

	bfs.pathFinding();
	bfs.draw();
}