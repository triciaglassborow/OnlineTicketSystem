#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

class FloorChart
{
public:
	FloorChart();
	~FloorChart();
	void DisplayFloorChart();

protected:
	int floor[3][5];
};

FloorChart::FloorChart()
{
	for (int r = 0; r < 3; ++r)
		for (int c = 0; c < 5; ++c)
			floor[r][c] = ' ';
}

void FloorChart::DisplayFloorChart()
{

}
