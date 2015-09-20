#include "stdafx.h"
#include "DataStructure.h"

/*
There're 7 red tiles, 8 blue titles and one white title in a 4 x 4 plane. We could only move the white tile. When moving it, the white tile swaps the position with the adjacent tile. L, R, U, D are corresponding to four directions which the tile could be moved to (Left, Right, Up, Down) For example, starting from configuration (S), by the move sequence RDRDL we reach the configuration (E). Now, starting from configuration (S), find the shortest way to reach configuration (T).
*/

class GlowingPuzzle
{
public:
	string GetShortestPath()
	{
		string startBoard = "0122112211221122";
		string endBoard = "0212212112122121";
		int len = sqrt(startBoard.size());
		unordered_map<string, string> isVisited;
		queue<pair<pair<int, int>, string>> quIndex;
		quIndex.push(pair<pair<int, int>, string>(pair<int, int>(0, 0), startBoard));
		isVisited.insert(pair<string, string>(startBoard, ""));
		int index = 0;
		vector<string> result;
		while (!quIndex.empty())
		{
			int iIndex = quIndex.front().first.first;
			int jIndex = quIndex.front().first.second;
			string curBoard = quIndex.front().second;
			string curSeq = isVisited[curBoard];
			quIndex.pop();
			if (curBoard == endBoard)
			{
				result.push_back(curSeq);
				continue;
			}
			if (iIndex - 1 >= 0)
			{
				string tmp = MoveUp(iIndex, jIndex, curBoard);
				if (isVisited.find(tmp) == isVisited.end())
				{
					quIndex.push(pair<pair<int, int>, string>(pair<int, int>(iIndex - 1, jIndex), tmp));
					isVisited.insert(pair<string, string>(tmp, curSeq + "U"));
				}
			}
			if (iIndex + 1 < len)
			{
				string tmp = MoveDown(iIndex, jIndex, curBoard);
				if (isVisited.find(tmp) == isVisited.end())
				{
					quIndex.push(pair<pair<int, int>, string>(pair<int, int>(iIndex + 1, jIndex), tmp));
					isVisited.insert(pair<string, string>(tmp, curSeq + "D"));
				}
			}
			if (jIndex - 1 >= 0)
			{
				string tmp = MoveLeft(iIndex, jIndex, curBoard);
				if (isVisited.find(tmp) == isVisited.end())
				{
					quIndex.push(pair<pair<int, int>, string>(pair<int, int>(iIndex, jIndex - 1), tmp));
					isVisited.insert(pair<string, string>(tmp, curSeq + "L"));
				}
			}
			if (jIndex + 1 < len)
			{
				string tmp = MoveRight(iIndex, jIndex, curBoard);
				if (isVisited.find(tmp) == isVisited.end())
				{
					quIndex.push(pair<pair<int, int>, string>(pair<int, int>(iIndex, jIndex + 1), tmp));
					isVisited.insert(pair<string, string>(tmp, curSeq + "R"));
				}
			}
		}
		int minLen = INT_MAX;
		int minIndex = -1;
		for (size_t i = 0; i < result.size(); i++)
		{
			if (result[i].size()<minLen)
			{
				minLen = result[i].size();
				minIndex = i;
			}
		}
		return result[minIndex];
	}

	string MoveUp(int iIndex, int jIndex, string board)
	{
		int len = sqrt(board.size());
		swap(board[iIndex*len + jIndex], board[(iIndex - 1)*len + jIndex]);
		return board;
	}
	string MoveDown(int iIndex, int jIndex, string board)
	{
		int len = sqrt(board.size());
		swap(board[iIndex*len + jIndex], board[(iIndex + 1)*len + jIndex]);
		return board;
	}
	string MoveLeft(int iIndex, int jIndex, string board)
	{
		int len = sqrt(board.size());
		swap(board[iIndex*len + jIndex], board[iIndex*len + jIndex - 1]);
		return board;
	}
	string MoveRight(int iIndex, int jIndex, string board)
	{
		int len = sqrt(board.size());
		swap(board[iIndex*len + jIndex], board[iIndex*len + jIndex + 1]);
		return board;
	}
};







