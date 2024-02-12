#include <iostream>
#include <set>
#include <vector>
#include <map>
#include "data.h"
#include <algorithm>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>
#include <iomanip>
using namespace std;

#pragma warning( disable : 4996 )

bool successTag = false;


//求每一个good 1-substring,返回他在x中的位置i，插入b的位置k，和a匹配的位置j
vector<tuple<int, int, int>> preProcess(Data& data);

//求冲突矩阵，冲突时为1
vector<vector<int>> conArray(vector<tuple<int, int, int>> p);

//贪心算法求初始的good 1-substring集合
vector<int> greedyAlg(vector<vector<int>> conMix);

//局部搜索任意增加元素
void addLocal(vector<int>& goodOneSubstring, vector<vector<int>>& conMix, int addNumber, int needAdd, int addNow);

//局部搜索任意删除元素
void delLocal(vector<int>& goodOneSubstring, int delNumber, int needDel, int delNow, vector<vector<int>>& conMix);

//局部搜索算法，用s+1个替换s个，任意删除s个任意增加s+1个
void localSearch(vector<int>& goodOneSubstring, vector<vector<int>>& conMix, int s);

//更新data
void updateData(Data& data, vector<int>& goodOneSubstring, vector<tuple<int, int, int>>& p, vector<vector<int>> conMix);

void basicInsert(Data& data);

int main()
{
	srand((unsigned)time(NULL));
	clock_t startTime, endTime;

	string fname = "record.csv";
	string fnametxt = "inOutPut.txt";

	ofstream ofs(fname, ios::out);

	ofstream ofstxt(fnametxt, ios::out);

	// 写入标题行
	ofs << "The length of genomes" << ','
		<< "OptimalSolution" << ','
		<< "BasicInsert" << ','
		<< "time2(ms)" << ','
		<< "GreedyScaffoldFilling" << ','
		<< "time3(ms)" << ','
		<< "LocalSearchScaffoldFilling" << ','
		<< "time4(ms)" << ','
		<< "SLocalSearchScaffoldFilling(s = 2)" << ','
		<< "time5(ms)" << ','
		<< "SLocalSearchScaffoldFilling(s = 3)" << ','
		<< "time6(ms)" <<endl;

	for (int length = 900; length < 901; length = length + 100)
	{
		int restag = 3;
		int restag1 = 2;
		int restag2 = 1;
		int restag3 = 0;

		int result = 0;
		while (result<10) {
			restag = 3;
			restag1 = 2;
			restag2 = 1;
			restag3 = 0;
			Data data(length, length / 5);
			cout << data.stringA.size() << " " << data.stringA << endl;
			cout << data.stringB.size() << " " << data.stringB << endl;
			cout << "oldDuo: " << data.oldDuo << endl;
			cout << "optimalSolution: " << data.optimalAdd << endl;

			ofstxt << "input:" << endl;
			ofstxt << "A: " << data.stringA << endl;
			ofstxt << "B: " << data.stringB << endl;
			ofstxt << "X: ";
			for (int i = 0; i < data.missX.size(); i++)
			{
				ofstxt << data.missX[i] << " ";
			}
			ofstxt << endl;
			ofstxt << "M:";
			for (int i = 0; i < data.matchedM.size(); i++)
			{
				ofstxt << data.matchedM[i] << " ";
			}
			ofstxt << endl;
			ofstxt << "matchedA:";
			for (int i = 0; i < data.matchedA.size(); i++)
			{
				ofstxt << data.matchedA[i] << " ";
			}
			ofstxt << endl;
			ofstxt << "matchedB:";
			for (int i = 0; i < data.matchedB.size(); i++)
			{
				ofstxt << data.matchedB[i] << " ";
			}
			ofstxt << endl;
			ofs << to_string(length) << "," << data.optimalAdd << ",";
			ofstxt << "The length of A: " << length << endl;
			ofstxt << "The length of B: " << data.stringB.size() << endl;
			ofstxt << "The length of X: " << data.missX.size() << endl;
			ofstxt << "The number of increasing Duo-preservations of optimal solution: " << data.optimalAdd << endl;
			ofstxt << "Output of BasicInsert algorithm: " << endl;
			startTime = clock();
			Data data1 = data;
			basicInsert(data1);
			endTime = clock();
			cout << "basicInsert:" << endl;
			cout << "basicInsert Solution: "<<data1.createDuo() - data1.oldDuo << endl;
			ofstxt << "B: " << data1.stringB << endl;
			ofstxt << "M:";
			for (int i = 0; i < data1.matchedM.size(); i++)
			{
				ofstxt << data1.matchedM[i] << " ";
			}
			ofstxt << endl;
			ofstxt << "The number of increasing Duo-preservations of BasicInsert algorithm: " << data1.createDuo() - data.oldDuo << endl;
			ofstxt << "RunTime:" << endTime - startTime << "ms" << endl;
			ofs << to_string(data1.createDuo() - data1.oldDuo) << ","<<endTime-startTime<<",";

			ofstxt << "Output of GreedyScaffoldFilling algorithm: " << endl;
			cout << "Scaffold Filling: " << endl;
			Data data3 = data;
			vector<tuple<int, int, int>> p = preProcess(data3);
			cout << "size of all goodOne: " << p.size() << endl;
			vector<vector<int>> conMix = conArray(p);
			startTime = clock();
			vector<int> goodOneSubstring = greedyAlg(conMix);
			cout << "optGood of greedyAlg : " << count(goodOneSubstring.begin(), goodOneSubstring.end(), 1) << endl;

			updateData(data3, goodOneSubstring, p, conMix);

			basicInsert(data3);
			endTime = clock();
			ofstxt << "B: " << data3.stringB << endl;
			ofstxt << "M:";
			for (int i = 0; i < data3.matchedM.size(); i++)
			{
				ofstxt << data3.matchedM[i] << " ";
			}
			ofstxt << endl;
			ofstxt << "The number of increasing Duo-preservations of GreedyScaffoldFilling algorithm: " << data3.createDuo() - data.oldDuo << endl;
			ofstxt << "RunTime:" << endTime - startTime << "ms" << endl;
			ofs << to_string(data3.createDuo() - data3.oldDuo) << "," <<endTime - startTime << ",";
			restag = data3.createDuo() - data3.oldDuo;
			cout << "Scaffold Filling algorithm :" << restag<< endl;
			
			cout << "Local Search Scaffold Filling: " << endl;
			for (int s = 1; s < 3; s++)
			{
				if (s == 1)
				{
					ofstxt << "Output of LocalSearchScaffoldFilling algorithm: " << endl;
				}
				else
				{
					ofstxt << "Output of SLocalSearchScaffoldFilling algorithm(s="<<s<<"): " << endl;
				}
				cout <<"s="<< s << endl;
				Data data2 = data;
				startTime = clock();
				localSearch(goodOneSubstring, conMix, s);

				cout << "optGood of localSearch : " << count(goodOneSubstring.begin(), goodOneSubstring.end(), 1) << endl;

				updateData(data2, goodOneSubstring, p, conMix);

				basicInsert(data2);
				endTime = clock();
				ofstxt << "B: " << data2.stringB << endl;
				ofstxt << "M:";
				for (int i = 0; i < data2.matchedM.size(); i++)
				{
					ofstxt << data2.matchedM[i] << " ";
				}
				ofstxt << endl;
				ofstxt << "The number of increasing Duo-preservations of Local Search Scaffold Filling algorithm: " << data2.createDuo() - data.oldDuo << endl;
				ofstxt << "RunTime:" << endTime - startTime << "ms" << endl;
				ofs << to_string(data2.createDuo() - data2.oldDuo) << "," << endTime - startTime << ",";
				if (data2.createDuo() - data2.oldDuo > data2.optimalAdd)
				{
					break;
				}
				if (s == 1)
				{
					restag1 = data2.createDuo() - data2.oldDuo;
					cout << "solution:"<< restag1 << endl;
				}
				if (s == 2)
				{
					restag2 = data2.createDuo() - data2.oldDuo;
					cout << "solution:" << restag2 << endl;
				}
				if (s == 3)
				{
					restag3 = data2.createDuo() - data2.oldDuo;
					cout << "solution:" << restag3 << endl;
				}

			}
			ofstxt << endl;
			ofs << endl;
			cout << endl;
			if (restag2 > restag1 && restag1 > restag)
				result++;
			cout << "result: " << result << endl;
		}
	}
	ofs.close();
	ofstxt.close();

}

//求每一个good 1-substring,返回他在x中的位置i，插入b的位置k，和a匹配的位置j
vector<tuple<int, int, int>> preProcess(Data& data)
{
	//记录每一个good 1-substring,包括他在x中的位置i，插入b的位置k，和a匹配的位置j
	vector<tuple<int, int, int>> p;
	for (int i = 0; i < data.missX.size(); i++)
	{
		for (int j = 0; j < data.stringA.size(); j++)
		{
			if (data.missX[i] == data.stringA[j] && data.matchedA[j] < 0)
			{
				for (int k = 0; k < data.stringB.size(); k++)
				{
					if (data.stringB[k] == data.stringA[j - 1] && data.stringB[k + 1] == data.stringA[j + 1])
					{
						if ((data.matchedA[j - 1] == k && data.matchedA[j + 1] == k + 1) || (data.matchedA[j - 1] == k && data.matchedA[j + 1] < 0 && data.matchedB[k + 1] < 0) || (data.matchedA[j - 1] < 0 && data.matchedB[k] < 0 && data.matchedA[j + 1] == k + 1) || (data.matchedA[j - 1] < 0 && data.matchedA[j + 1] < 0 && data.matchedB[k] < 0 && data.matchedB[k + 1] < 0))
							p.push_back(tuple<int, int, int>(i, k + 1, j));
					}
				}
			}

		}
	}
	return p;
}

//求冲突矩阵，冲突时为1
vector<vector<int>> conArray(vector<tuple<int, int, int>> p)
{
	//得到冲突矩阵
	vector<vector<int>> conMix;
	for (int i = 0; i < p.size(); i++)
	{
		vector<int> row;
		for (int j = 0; j < p.size(); j++)
		{
			int con = 0;
			if (get<0>(p[i]) == get<0>(p[j]))
			{
				con = 1;
			}
			else if (get<1>(p[i]) == get<1>(p[j]))
			{
				con = 1;
			}
			else if (get<2>(p[i]) == get<2>(p[j]))
			{
				con = 1;
			}
			else if (get<1>(p[i]) == get<1>(p[j]) - 1 && get<2>(p[i]) != get<2>(p[j]) - 2)
			{
				con = 1;
			}
			else if (get<1>(p[i]) == get<1>(p[j]) + 1 && get<2>(p[i]) != get<2>(p[j]) + 2)
			{
				con = 1;
			}
			else if (get<1>(p[i]) != get<1>(p[j]) - 1 && get<2>(p[i]) == get<2>(p[j]) - 2)
			{
				con = 1;
			}
			else if (get<1>(p[i]) != get<1>(p[j]) + 1 && get<2>(p[i]) == get<2>(p[j]) + 2)
			{
				con = 1;
			}
			else if (abs(get<2>(p[i]) - get<2>(p[j])) == 1)
			{
				con = 1;
			}
			row.push_back(con);

		}
		conMix.push_back(row);
	}
	return conMix;
}

//贪心算法求初始的good 1-substring集合
vector<int> greedyAlg(vector<vector<int>> conMix)
{
	//贪心得到初始解
	vector<int> goodOneSubstring(conMix.size());
	for (int i = 0; i < conMix.size(); i++)
	{
		int tab = 0;
		for (int j = 0; j < i; j++)
		{
			if (goodOneSubstring[j] == 1 && conMix[i][j] == 1)
			{
				tab = 1;
				break;
			}
		}
		if (tab == 0)
		{
			goodOneSubstring[i] = 1;
		}
	}
	return goodOneSubstring;

}

//局部搜索任意增加元素
void addLocal(vector<int>& goodOneSubstring, vector<vector<int>>& conMix, int addNumber, int needAdd, int addNow)
{
	//局部搜索增加元素
	if (successTag == true)
	{
		return;
	}
	if (addNumber == needAdd)
	{
		successTag = true;
		return;
	}
	if (addNow >= goodOneSubstring.size())
	{
		return;
	}
	if (goodOneSubstring[addNow] == 0)
	{
		int conTag = 0;
		for (int i = 0; i < goodOneSubstring.size(); i++)
		{
			if (i != addNow && goodOneSubstring[i] == 1 && conMix[i][addNow] == 1)
			{
				conTag = 1;
				break;
			}
		}
		if (conTag == 0)
		{
			goodOneSubstring[addNow] = 1;
			int newAddNumber = addNumber + 1;
			int newAddNow = addNow + 1;
			addLocal(goodOneSubstring, conMix, newAddNumber, needAdd, newAddNow);
			if (successTag == false)
				goodOneSubstring[addNow] = 0;
		}
	}
	if (successTag == false || goodOneSubstring[addNow] == 1)
	{
		int newAddNow = addNow + 1;
		addLocal(goodOneSubstring, conMix, addNumber, needAdd, newAddNow);
	}
}

//局部搜索任意删除元素
void delLocal(vector<int>& goodOneSubstring, int delNumber, int needDel, int delNow, vector<vector<int>>& conMix)
{
	//局部搜索移除元素
	if (needDel == delNumber)
	{
		addLocal(goodOneSubstring, conMix, 0, needDel + 1, 0);
		if (successTag == false)
		{
			return;
		}
	}
	if (successTag == true)
	{
		return;
	}
	if (delNow >= goodOneSubstring.size())
	{
		return;
	}
	else
	{
		if (goodOneSubstring[delNow] == 1)
		{
			goodOneSubstring[delNow] = 0;
			int newDelNumber = delNumber + 1;
			int newDelNow = delNow + 1;
			delLocal(goodOneSubstring, newDelNumber, needDel, newDelNow, conMix);
			if (successTag == false)
				goodOneSubstring[delNow] = 1;
		}
		if (successTag == false || goodOneSubstring[delNow] == 0)
		{
			int newDelNow = delNow + 1;
			delLocal(goodOneSubstring, delNumber, needDel, newDelNow, conMix);
		}

	}
}

//局部搜索算法，用s+1个替换s个，任意删除s个任意增加s+1个
void localSearch(vector<int>& goodOneSubstring, vector<vector<int>>& conMix, int s)
{
	for (int i = s; i < s + 1; i++)
	{
		while (!successTag)
		{
			delLocal(goodOneSubstring, 0, i, 0, conMix);
			successTag = !successTag;
			//形态改变，可能有一些解可以直接快速得到，减少运行时间
			for (int k = 0; k < goodOneSubstring.size(); k++)
			{
				if (goodOneSubstring[k] == 0)
				{
					int tab = 0;
					for (int j = 0; j < goodOneSubstring.size(); j++)
					{
						if (j != k && goodOneSubstring[j]==1 && conMix[k][j] == 1)
						{
							tab = 1;
							break;
						}
					}
					if (tab == 0)
					{
						goodOneSubstring[k] = 1;
					}
				}

			}
		}
		successTag = false;
	}

}


void updateData(Data& data, vector<int>& goodOneSubstring, vector<tuple<int, int, int>>& p, vector<vector<int>> conMix)
{
	int conNum = 0;
	int conMatch = 0;
	int conMatch1 = 0;
	for (int i = 0; i < goodOneSubstring.size(); i++)
	{
		if (goodOneSubstring[i] == 1)
		{
			for (int j = 0; j < goodOneSubstring.size(); j++)
			{
				if (i != j && goodOneSubstring[j] == 1 && conMix[i][j] == 1)
				{
					conNum++;
				}
				if (i != j && goodOneSubstring[j] == 1 && get<2>(p[i]) == get<2>(p[j]))
				{
					conMatch++;
				}
			}
			for (int j = 0; j < data.matchedB.size(); j++)
			{
				if (get<2>(p[i]) == data.matchedB[j])
				{
					conMatch1++;
				}
			}
		}
	}
	if (conNum != 0)
	{
		cout << "conNum:" << conNum << endl;
	}
	if (conMatch != 0)
	{
		cout << "conMatch:" << conMatch << endl;
	}
	if (conMatch1 != 0)
	{
		cout << "conMatch1:" << conMatch1 << endl;
	}
	vector<int> offset = vector<int>(data.stringB.size(), 0);
	for (int i = 0; i < goodOneSubstring.size(); i++)
	{
		if (goodOneSubstring[i] == 1)
		{
			data.stringB.insert(get<1>(p[i]) + offset[get<1>(p[i])], 1, data.missX[get<0>(p[i])]);
			data.missX[get<0>(p[i])] = '%';
			vector<int>::iterator it1 = find(data.matchedB.begin(), data.matchedB.end(), get<2>(p[i]));
			if (it1 != data.matchedB.end())
			{
				cout << distance(data.matchedB.begin(), it1) << data.stringB[distance(data.matchedB.begin(), it1)] << " " << data.stringA[get<2>(p[i])] << endl;
			}
			data.matchedB.insert(data.matchedB.begin() + get<1>(p[i]) + offset[get<1>(p[i])], get<2>(p[i]));
			data.matchedB[get<1>(p[i]) + offset[get<1>(p[i])] + 1] = -1;
			data.matchedB[get<1>(p[i]) + offset[get<1>(p[i])] - 1] = -1;
			vector<int>::iterator it2 = find(data.matchedB.begin(), data.matchedB.end(), get<2>(p[i]) + 1);
			if (it2 != data.matchedB.end())
			{
				cout << distance(data.matchedB.begin(), it2) << data.stringB[distance(data.matchedB.begin(), it2)] << " " << data.stringA[get<2>(p[i]) + 1] << endl;

			}
			vector<int>::iterator it3 = find(data.matchedB.begin(), data.matchedB.end(), get<2>(p[i]) - 1);
			if (it3 != data.matchedB.end())
			{
				cout << distance(data.matchedB.begin(), it3) << data.stringB[distance(data.matchedB.begin(), it3)] << " " << data.stringA[get<2>(p[i]) - 1] << endl;

			}
			data.matchedB[get<1>(p[i]) + offset[get<1>(p[i])] + 1] = get<2>(p[i]) + 1;
			data.matchedB[get<1>(p[i]) + offset[get<1>(p[i])] - 1] = get<2>(p[i]) - 1;
			data.createMatchedA();
			for (int k = get<1>(p[i]); k < offset.size(); k++)
			{
				offset[k]++;
			}
		}
	}
}

void basicInsert(Data& data)
{
	for (int i = 0; i < data.missX.size(); i++)
	{
		if (data.missX[i] != '%')
		{
			int j = 0;
			for (; j < data.stringA.size(); j++)
			{
				if (data.missX[i] == data.stringA[j] && data.matchedA[j] < 0)
				{
					string str = "";
					str += data.missX[i];
					data.missX[i] = '%';
					int insertTag = 0;
					while (insertTag==0)
					{
						if (data.matchedA[j + 1] >= 0)
						{
							insertTag = data.matchedA[j + 1];
							break;
						}
						else
						{
							vector<char>::iterator it = find(data.missX.begin(), data.missX.end(), data.stringA[j + 1]);
							if (it != data.missX.end())
							{
								str += data.missX[distance(data.missX.begin(), it)];
								data.missX[distance(data.missX.begin(), it)] = '%';
								j++;
							}
							else
							{
								for (int k = 0; k < data.stringB.size(); k++)
								{
									if (data.stringB[k] == data.stringA[j + 1] && data.matchedB[k] < 0)
									{
										insertTag = k;
										break;
									}
								}
								if (insertTag == 0)
								{
									cout << "-------------没找到------------" << endl;
									insertTag = 1;
								}
							}

						}
					}
					data.stringB.insert(insertTag, str);
					data.matchedB.insert(data.matchedB.begin() + insertTag, str.size(), -1);
					for (int k = insertTag + str.size(); k >= insertTag; k--)
					{
						data.matchedB[k] = -1;
						vector<int>::iterator it4 = find(data.matchedB.begin(), data.matchedB.end(), j + 1);
						if (it4 != data.matchedB.end())
						{
							cout << distance(data.matchedB.begin(), it4) << data.stringB[distance(data.matchedB.begin(), it4)] << " " << data.stringA[j + 1] << endl;

						}
						data.matchedB[k] = j + 1;
						j--;
					}
					if (insertTag - 1 >= 0 && data.stringB[insertTag - 1] == data.stringA[j + 1] && ((data.matchedA[j + 1] < 0 && data.matchedB[insertTag - 1] < 0) || (data.matchedA[j + 1] == insertTag - 1)))
					{
						data.matchedB[insertTag - 1] = -1;
						vector<int>::iterator it5 = find(data.matchedB.begin(), data.matchedB.end(), j + 1);
						data.matchedB[insertTag - 1] = j + 1;
					}
					data.createMatchedA();
					break;
				}
			}
			if (j == data.stringA.size())
			{
				cout << "data.miss: " << data.missX[i] << endl;
				cout << "count of A:  " << count(data.stringA.begin(), data.stringA.end(), data.missX[i]);
				cout << "count of B:  " << count(data.stringB.begin(), data.stringB.end(), data.missX[i]);
				cout << "count of X:  " << count(data.missX.begin(), data.missX.end(), data.missX[i]) << endl;
				for (int x = 0; x < data.stringA.size(); x++)
				{
					if (data.missX[i] == data.stringA[x])
					{
						cout << "matched of B:" << data.stringB[data.matchedA[x]] << endl;
					}
				}

			}
		}
	}
	data.createMatchedM();
}


