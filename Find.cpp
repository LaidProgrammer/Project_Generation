#include <string>
#include "UTypes.h"
#include <Math.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <stdio.h>
#include <direct.h>
#include <set>

using namespace std;

int deep = 0;
int a = 0;
int b = 0;
bool unbeat_figures(int** field, int** positions, int count)
{
	for (int i = 0; i < count; i++)
	{
		int** f = new int*[field_size];
		for (int k = 0; k < field_size; k++)
		{
			f[k] = new int[field_size];
		}
		queen::stay(field, f, positions[i][0], positions[i][1]);
		for (int q = 0; q < count; q++)
		{
			if (f[positions[i][0]][positions[i][1]] = 2)return false;
		}
	}
	return true;
}
int count_positions(int** arr, int** arr_of_positions)
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
	for (int i = 0; i < out; i++)
	{
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
			}
		}
	}
	return out;
}

int count_figures(int** field)
{
	int t = 0;
	for (int i = 0; i < field_size; i++)
	{
		for (int k = 0; k < field_size; k++)
		{
			if (field[i][k] == 3)t += 1;
		}
	}
	return t;
}

int build_tree(leav root)
{ 
	int** f;
	f = new int*[field_size];
	ifstream input;
	input.open(root.name);
	for (int i = 0; i < field_size; i++)
	{
		f[i] = new int[field_size];
		for (int k = 0; k < field_size; k++)
		{
			string cell = "";
			input >> cell;
			f[i][k] = atoi(cell.c_str());
		}
	}
	while (!input.end) {}
	input.close();
	int size = (field_size - 2)*(field_size - 2);
	int** full_arr_of_positions = new int*[size];
	for (int i = 0; i < size; i++)
	{
		full_arr_of_positions[i] = new int[2];
		full_arr_of_positions[i][0] = 0;
		full_arr_of_positions[i][1] = 0;
	}
	int count = count_positions(f, full_arr_of_positions);

	int** arr_of_positions = new int*[count];
	for (int i = 0; i < count; i++)
	{
		arr_of_positions[i] = new int[2];
		arr_of_positions[i][0] = full_arr_of_positions[i][0];
		arr_of_positions[i][1] = full_arr_of_positions[i][1];
	}
	delete full_arr_of_positions;
	if (unbeat_figures(f, arr_of_positions, count)&count!=0)
	{
		count = 1;
	}
	root.len_of_children = count;
	if (count == 0)
	{
		a += 1;
		int c = count_figures(f);
		b += c;
		if (c < deep)root.len_of_children = -1;
		else deep = c;
		return 0;
	}
	delete f;
	root.children = new leav[count];
	for (int i = 0; i < count; i++)
	{
		int** f;
		f = new int*[field_size];
		ifstream input;
		input.open(root.name);
		for (int i = 0; i < field_size; i++)
		{
			f[i] = new int[field_size];
			for (int k = 0; k < field_size; k++)
			{
				string cell = "";
				input >> cell;
				f[i][k] = atoi(cell.c_str());
			}
		}
		while (!input.end) {}
		input.close();
		int** arr = new int*[field_size];
		for (int i = 0; i < field_size; i++)
		{
			arr[i] = new int[field_size];
		}
		queen::stay(f, arr, arr_of_positions[i][0], arr_of_positions[i][1]);
		delete f;
		leav l;
		l.parent = &root;
		l.name = root.dir + to_string(int(&l)) + ".txt";
		l.dir = root.dir;
		ofstream output;
		output.open(l.name);
		for (int i = 0; i < field_size; i++)
		{
			for (int k = 0; k < field_size; k++)
			{
				output << to_string(arr[i][k]) << endl;
			}
		}
		while (!output.end) {}
		output.close();
		root.children[i] = l;
		delete arr;
	}
	delete arr_of_positions;
	for (int i = 0; i < count; i++)
	{
		build_tree(root.children[i]);
	}
	int res = 1;
	for (int k = 0; k < count; k++)
	{
		if (root.children[k].len_of_children != -1)
		{
			res = 0;
			break;
		}
	}
	if (res == 1)
	{
		root.len_of_children = -1;
		delete root.children;
	}
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
	leav root;
	std::string path;
	char buffer[FILENAME_MAX];
	_getcwd(buffer, FILENAME_MAX);
	path = string(buffer);
	root.dir = path + "\\Tree\\";
	path += "\\Tree\\" + to_string(int(&root)) + ".txt";
	root.name = path;
	ofstream output;
	output.open(root.name);
	for (int k = 0; k < field_size; k++)
	{
		for (int i = 0; i < field_size; i++)
		{
			output << to_string(field[k][i]) << endl;
		}
	}
	while(!output.end){}
	output.close();
	build_tree(root);
	






	cout << a;
	system("pause>nul");


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