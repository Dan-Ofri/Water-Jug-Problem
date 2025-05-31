#include <stdlib.h>
#include <iostream>
#include <chrono>
#include <ios>
#include "DirectedGraph.h"
#include "AlgorithmManager.h"
using namespace std;


int main()
{
	auto start = chrono::high_resolution_clock::now();
	AlgorithmManager algorithmManager;
	bool runtime = algorithmManager.Run();
	auto end = chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	if (runtime)
	{
		algorithmManager.printRuntime(duration.count());
	}
	return 0;
}