#include <stdlib.h>
#include <iostream>
#include <chrono>
#include <ios>
#include "DirectedGraph.h"
#include "AlgorithmManager.h"
using namespace std;

int main()
{
	auto start = chrono::high_resolution_clock::now(); // Start timing
	AlgorithmManager algorithmManager;
	bool runtime = algorithmManager.Run(); // Run the algorithm manager
	auto end = chrono::high_resolution_clock::now(); // End timing
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start); // Calculate duration in microseconds

	if (runtime)
	{
		algorithmManager.printRuntime(duration.count()); // Print runtime if requested
	}

	return 0;
}