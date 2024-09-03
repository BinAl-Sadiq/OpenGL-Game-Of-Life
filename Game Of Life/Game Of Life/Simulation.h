#pragma once

#include <vector>

class Simulation
{
private:
	unsigned int gridXSize, gridYSize;

	unsigned int* grid;
	unsigned int* oldGrid;

	std::vector<float> spots;

public:
	Simulation(unsigned int gridXSize, unsigned int gridYSize);

	void simulate();

	void draw();

	~Simulation();
};