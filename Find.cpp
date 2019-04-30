#include <string>
#include "UTypes.h"
#include <Math.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int count_positions(int arr[field_size][field_size],int** arr_of_positions)
{
	int out = 0;
	for (int i = 0; i < field_size; i++)
	{
		for (int k = 0; k < field_size; k++)
		{
			if (arr[i][k] == 1)
			{
				
				out++;
			}
		}
	}
	arr_of_positions = new int*[out];
	for (int i = 0; i < out; i++)
	{
		arr_of_positions[i] = new int[2];
		for (int k = 0; k < 2; k++)
		{
			arr_of_positions[i][k] = -1;
		}
	}
	int pos = 0;
	for (int i = 0; i < field_size; i++)
	{
		for (int k = 0; k < field_size; k++)
		{
			if (arr[i][k] == 1)
			{

				arr_of_positions[pos][0] = i;
				arr_of_positions[pos][1] = k;
				pos++;
				out++;
			}
		}
	}
	return out;
}

int build_tree(int arr[field_size][field_size],leav root)
{
	int** arr_of_positions = 0;
	int count = count_positions(arr,arr_of_positions);
	arr_of_positions = new int*[count];
	for (int k = 0; k < count; k++)
	{
		arr_of_positions[count] = new int[2];
		cout << arr_of_positions[count][0] << endl;
		cout << arr_of_positions[count][1] << endl;
	}
	system("pause>nul");
	return 0;
}

int main()
{
	system("chcp 1251>nul");
	int field[field_size][field_size];
	for (int i = 0; i <= field_size - 1; i++)
	{
		for (int k = 0; k <= field_size - 1; k++)
		{
			field[i][k] = 0;
		}
	}

	srand(time(NULL));
	int middle = round((field_size + 1) / 2) - 1;

	for (int i = 1;i <= middle; i++)
	{
		for (int k = 1; k <= middle + i - 1; k++)
		{
			if (rand()%stone_gen == 0) field[i][k] = 4;
			else field[i][k] = 1;
		}
	}

	for (int i = middle + 1; i <= field_size - 2; i++)
	{
		for (int k = field_size - 3 * middle + i; k <= field_size-2; k++)
		{
			if (rand() % stone_gen == 0) field[i][k] = 4;
			else field[i][k] = 1;
		}
	}
	leav l;
	l.parent = &l;
	for (int k = 0; k < field_size; k++)
	{
		for (int i = 0; i < field_size; i++)
		{
			l.field[k][i] = field[k][i];
		}
	}
	build_tree(field, l);










	/*for (int i = 0; i <= field_size - 1; i++)
	{
		for (int k = 0; k <= field_size - 1; k++)
		{
			cout << field[i][k];
		}
		cout << endl;
	}
	system("pause>nul");*/
}