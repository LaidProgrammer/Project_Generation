using namespace std;

const int field_size = 11;
const int stone_gen = 5;
struct leav
{
	int field[field_size][field_size];
	leav* parent;
	leav** children;
	int len_of_children;
};

class figure
{
	public:
		
	protected:
		virtual int stay(int in_arr[field_size][field_size], int arr[field_size][field_size], int x, int y)
		{
			return 0;
		}
		/*virtual void rollback(int in_arr[field_size][field_size], int arr[field_size][field_size], int x, int y)
		{
			
		}*/
		void copy_field(int field[field_size][field_size], int out_field[field_size][field_size])
		{
			for (int i = 0; i <= field_size - 1; i++)
			{
				for (int k = 0; i <= field_size - 1; i++)
				{
					out_field[i][k] = field[i][k];
				}
			}
		}
	private:

};

class queen : figure
{
	public:
		queen()
		{

		}
		int stay(int in_arr[field_size][field_size], int arr[field_size][field_size], int x, int y)
		{
			for (int i = 0; i <= field_size - 1; i++)
			{
				for (int k = 0; k <= field_size - 1; k++)
				{
					arr[i][k] = in_arr[i][k];
				}
			}
			figure::copy_field(in_arr, arr);
			arr[x][y] = 3;
			int i, k, l, m, o, p, q;
			for (i = 1; (arr[x][y + i] != 0) && (arr[x][y + i] != 4); i++)
			{
				arr[x][y + i] = 2;
			}

			for (k = 1;  (arr[x + k][y] != 0) && (arr[x + k][y] != 4); k++)
			{
				arr[x + k][y] = 2;
			}

			for (l = 1;(arr[x + l][y + l] != 0) && (arr[x + l][y + l] != 4); l++)
			{
				arr[x + l][y + l] = 2;
			}

			for (m = 1;  (arr[x][y - m] != 0) && (arr[x - m][y] != 4); m++)
			{
				arr[x][y - m] = 2;
			}
			
			for (o = 1; (arr[x - o][y] != 0) && (arr[x - o][y] != 4); o++)
			{
				arr[x - o][y] = 2;
			}

			for (q = 1; (arr[x - q][y - q] != 0) && (arr[x - q][y - q] != 4); q++)
			{
				arr[x - q][y - q] = 2;
			}
			return i + k + l + m + o + q;
		}

		/*void rollback(int in_arr[field_size][field_size], int arr[field_size][field_size], int x, int y)
		{
			arr[x][y] = 1;
			int i = 0, k = 0, l = 0, m = 0, o = 0, p = 0, q = 0;
			for (i = 1; (arr[x][y + i] != 0) && (arr[x][y + i] != 4); i++)
			{
				arr[x][y + i] = 1;
			}

			for (k = 1; (arr[x + k][y] != 0) && (arr[x + k][y] != 4); k++)
			{
				arr[x + k][y] = 1;
			}

			for (l = 1; (arr[x + l][y + l] != 0) && (arr[x + l][y + l] != 4); l++)
			{
				arr[x + l][y + l] = 1;
			}

			for (m = 1; (arr[x][y - m] != 0) && (arr[x - m][y] != 4); m++)
			{
				arr[x][y - m] = 1;
			}

			for (o = 1; (arr[x - o][y] != 0) && (arr[x - o][y] != 4); o++)
			{
				arr[x - o][y] = 1;
			}

			for (q = 1; (arr[x - q][y - q] != 0) && (arr[x - q][y - q] != 4); q++)
			{
				arr[x - q][y - q] = 1;
			}
		}*/
};

class rook : figure
{
	public:

};