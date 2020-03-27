#include "stdafx.h"
//#include "stdafx.cpp"

int shudu[9][9], s, t, block = 0, block_line = 0, block_column = 0;
void Input()
{
	for (int i = 0; i < s; ++i)
	{
		for (int j = 0; j < s; ++j)
		{
			cin >> shudu[i][j];
		}
	}
}

void Output()
{
	for (int i = 0; i < s; ++i)
	{
		for (int j = 0; j < s; ++j)
		{
			cout << shudu[i][j];
			if (j != s - 1) cout << " ";
		}
		cout << endl;
	}
	if (t)
		cout << endl;
}


//num为待检查的数字，now_line和now_column为待检查的坐标，
bool Check(int num, int now_line, int now_column)
{
	for (int i = 0; i < s; ++i)//检查与待检查的坐标同行或同列的位置 
	{
		if (shudu[now_line][i] == num || shudu[i][now_column] == num)
			return false;
	}
	if (block != 0)
	{
		int i, j;
		for (i = now_line / block_line * block_line; i < now_line / block_line * block_line + block_line; i++)//检查与待检查的坐标同宫的位置 
		{
			for (j = now_column / block_column * block_column; j < now_column / block_column * block_column + block_column; j++)
			{
				if (shudu[i][j] == num)
					return false;
			}
		}
	}
	return true;//通过所有检查，返回true 
}


//将Work函数定义为bool，如果数独有解则返回true，无解则返回false*
bool Work(int now_line, int now_column)
{
	if (now_line == s)
	{
		return true;//如果将数独解完，返回true 
	}
	else
	{
		int next_line, next_column;
		next_column = now_column + 1;
		next_line = (next_column == s ? now_line + 1 : now_line);
		next_column = (next_column == s ? 0 : next_column);
		if (shudu[now_line][now_column] != 0)//如果当前坐标有数字，则对下一个坐标进行工作 
		{
			if (Work(next_line, next_column)) return true;//如果数独最终有解，则不断向前返回true 
		}
		else
		{
			for (int i = 1; i <= s; i++)
			{
				if (Check(i, now_line, now_column))
				{
					shudu[now_line][now_column] = i;//如果i值合法，则对下一个坐标进行工作
					if (Work(next_line, next_column)) return true;
				}
			}
			shudu[now_line][now_column] = 0;//回溯操作 
			return false;//如果i的值为1-9均不合法，则返回上一层继续循环 
		}
	}
}


int main(int argc, char* argv[])
{
	s = atoi(argv[2]);
	t = atoi(argv[4]);
	
	freopen(argv[6], "r", stdin);
		
	freopen(argv[8], "w", stdout);
	while (t--)
	{
		Input();
		switch (s)
		{
		case 4:block = 1, block_line = 2, block_column = 2; break;
		case 6:block = 1, block_line = 2, block_column = 3; break;
		case 8:block = 1, block_line = 4, block_column = 2; break;
		case 9:block = 1, block_line = 3, block_column = 3; break;
		default:break;
		}
		if (Work(0, 0)) Output();//如果有解，则调用输出函数 
		else cout << "No Answer." << endl;//如果无解，则输出“No Answer.”
	}
	//system("pause"); 
	return 0;
}
