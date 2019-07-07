#include <vector>
using namespace std;

class figure
{
public:
	int x, y, size = 0;
	int **other_figures;
	figure(int x, int y, int **other_figures, int size)
	{
		this->x = x;
		this->y = y;
		this->other_figures = other_figures;
		this->size = size;
	}
	virtual std::vector<int> stay() = 0;
};
class queen : figure
{
public:
	using figure::figure;
	std::vector<int> stay()
	{
		std::vector<int> result;
		for (int i = 0; i < size; i++)
		{
			if ((this->x == other_figures[i][0]) || (this->y == other_figures[i][1]) || (this->x - this->y == other_figures[i][0] - other_figures[i][1]))
			{
				result.push_back(i);
			}
		}
		return result;
	}
};