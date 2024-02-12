#include "data.h"
#include <set>
#include <algorithm>
using namespace std;

Data::Data(int aLength, int missLength)
{
	int finishTag = 1;
	while(finishTag)
	{
	//随机生成长度为aLength的字符串A
	this->stringA ="##xyz";
	vector<vector<int>> disturb;
	for (int i = 5; i < aLength-5; )
	{
		vector<int> disturbTag;
		disturbTag.push_back(i);
		int num = 0;
		while (num < 30 && i < aLength - 5)
		{
			int a = rand() % 23 + 97;
			this->stringA += (char)a;
			num++;
			i++;
		}
		if (i + 3 < aLength - 5)
		{
			disturbTag.push_back(i - disturbTag.back());
			disturb.push_back(disturbTag);
			this->stringA += "xyz";
			i += 3;
		}
		else
		{
			while (i < aLength - 5)
			{
				int a = rand() % 23 + 97;
				this->stringA += (char)a;
				i++;
			}
			disturbTag.push_back(i - disturbTag.back());
			disturb.push_back(disturbTag);
		}
	}
	this->stringA += "xyz$$";
	random_shuffle(disturb.begin(), disturb.end());
	//构造字符串B
	this->stringB = "##zyx";
	this->matchedB = { 0,1,-1,-1,-1 };
	this->missX = {};

	//不做删除的字符位置
	vector<int> unDelete = {0,1,2,3,4};
	//生成打乱的字符串B和B的匹配
	for (int i = 0; i < disturb.size(); i++)
	{
		for (int j = 0; j < disturb[i][1]; j++)
		{
			this->stringB += this->stringA[disturb[i][0]+j];
			this->matchedB.push_back(disturb[i][0] + j);
		}
		this->stringB += "zyx";
		this->matchedB.push_back(-1);
		this->matchedB.push_back(-1);
		this->matchedB.push_back(-1);
		unDelete.push_back(this->matchedB.size() - 3);
		unDelete.push_back(this->matchedB.size() - 2);
		unDelete.push_back(this->matchedB.size() - 1);
	}
	this->stringB += "$$";
	this->matchedB.push_back(this->stringA.size()-2);
	this->matchedB.push_back(this->stringA.size()-1);
	unDelete.push_back(this->matchedB.size() - 2);
	unDelete.push_back(this->matchedB.size() - 1);
	//生成时重构
	restructMatchedB();
	
	this->maxDuo = createDuo();

	//随机删除字符作为缺失字符编号
	set<int> missTag;
	while (missTag.size() < missLength + 1)
	{
		int tag = rand() % aLength;
		vector<int>::iterator it= find(unDelete.begin(), unDelete.end(), tag);
		set<int>::iterator it1= find(missTag.begin(), missTag.end(), tag-1);
		set<int>::iterator it2= find(missTag.begin(), missTag.end(), tag+1);
		if (it== unDelete.end()&&it1== missTag.end()&&it2== missTag.end())
		{
			missTag.insert(tag);
		}
		
	}

	vector<int> missTag1;
	for (set<int>::iterator it = missTag.begin(); it != missTag.end(); it++)
	{
		missTag1.push_back(*it);
	}
	int optGood = 0;
	
	int offset = 0;//偏移量
	for (set<int>::iterator it = missTag.begin(); it != missTag.end(); it++)
	{
		this->missX.push_back(*(this->stringB.begin() + (*it - offset)));
		this->stringB.erase(this->stringB.begin() + (*it - offset));
		this->matchedB.erase(this->matchedB.begin() + (*it - offset));
		offset++;
	}
	
	//删除缺失字符后重构
	restructMatchedB();
	
	//删除字符使匹配更少
	for (int i = 2; i < this->matchedA.size() - 2; i++)
	{
		if (this->matchedA[i] - this->matchedA[i - 1] == 1 && this->matchedA[i+1] - this->matchedA[i] == 1)
		{
			for (int j = 0; j < this->matchedB.size(); j++)
			{
				if (this->matchedB[j] == i)
				{
					this->missX.push_back(*(this->stringB.begin() + (j)));
					this->stringB.erase(this->stringB.begin() + (j));
					this->matchedB.erase(this->matchedB.begin() + (j));
					i++;
					break;
				}
			}
		}
	}
	restructMatchedB();
	
	//为了已给匹配是最大匹配，还需删除一些字符
	while (true)
	{
		int matchTag = 0;
		for (; matchTag < this->stringA.size() - 1; matchTag++)
		{
			if (this->matchedA[matchTag] == -1 && this->matchedA[matchTag + 1] == -1)
			{
				int i = 0;
				for (; i < this->stringB.size() - 1; i++)
				{
					if (this->matchedB[i] == -1 && this->matchedB[i + 1] == -1 && this->stringB[i] == this->stringA[matchTag] && this->stringB[i + 1] == this->stringA[matchTag + 1])
					{
						this->missX.push_back(*(this->stringB.begin() + (i+1)));
						this->stringB.erase(this->stringB.begin() + (i+1));
						this->matchedB.erase(this->matchedB.begin() + (i+1));
						break;
					}
				}
				if (i < this->stringB.size() - 1)
					break;
			}
		}
		if (matchTag == this->stringA.size() - 1)
			break;
	}
	//删除后重构
	restructMatchedB();
	random_shuffle(this->missX.begin(), this->missX.end());
	this->oldDuo = createDuo();
	
	this->optimalAdd = this->maxDuo - this->oldDuo;
	
	
	this->createMatchedM();
	int matchTag = 0;
	for (; matchTag < this->stringA.size()-1; matchTag++)
	{
		if (this->matchedA[matchTag] == -1 && this->matchedA[matchTag + 1] == -1)
		{
			int i = 0;
			for (; i < this->stringB.size()-1; i++)
			{
				if (this->matchedB[i] == -1 && this->matchedB[i + 1] == -1 && this->stringB[i] == this->stringA[matchTag] && this->stringB[i + 1] == this->stringA[matchTag + 1])
				{
					cout << "初始化数据：----------------" << endl;
					break;
				}
			}
			if (i < this->stringB.size() - 1)
				break;
		}
	}
	if (matchTag == this->stringA.size() - 1)
	{
		finishTag = 0;
	}

	}
}

//重构匹配
void Data::restructMatchedB()
{
	for (int i = 2; i < this->matchedB.size() - 1; i++)
	{
		if ((this->matchedB[i - 1] == -1 && this->matchedB[i + 1] == -1) || (this->matchedB[i] - this->matchedB[i - 1] != 1 && this->matchedB[i + 1] - this->matchedB[i] != 1))
			this->matchedB[i] = -1;
	}
	createMatchedA();
	int alterTag = 1;
	//左右相邻可以匹配的加上
	while (alterTag)
	{
		alterTag = 0;
		for (int i = 1; i < this->matchedB.size() - 1; i++)
		{
			if (this->matchedB[i] == -1 && this->matchedB[i + 1] != -1 && this->matchedA[this->matchedB[i + 1] - 1] == -1 && this->stringB[i] == this->stringA[this->matchedB[i + 1] - 1])
			{
				this->matchedB[i] = this->matchedB[i + 1] - 1;
				this->matchedA[this->matchedB[i + 1] - 1] = i;
				alterTag = 1;
			}
			if (this->matchedB[i] != -1 && this->matchedB[i + 1] == -1 && this->matchedA[this->matchedB[i] + 1] == -1 && this->stringB[i + 1] == this->stringA[this->matchedB[i] + 1])
			{
				this->matchedB[i + 1] = this->matchedB[i] + 1;
				this->matchedA[this->matchedB[i] + 1] = i + 1;
				alterTag = 1;
			}
		}
	}
	
}

//根据B的匹配构造A的匹配
void Data::createMatchedA()
{
	this->matchedA = vector<int>(this->stringA.size(), -1);
	for (int i = 0; i < this->matchedB.size(); i++)
	{
		if (this->matchedB[i] > -1)
		{
			this->matchedA[this->matchedB[i]] = i;
		}
	}
}

//根据已有的匹配识别出保留对的数量
int Data::createDuo()
{
	int duoNum=0;
	for (int i = 1; i < this->matchedB.size(); i++)
	{
		if (this->matchedB[i] > -1 && this->matchedB[i - 1] > -1 && this->matchedB[i] - this->matchedB[i - 1] == 1)
		{
			duoNum++;
		}
	}
	return duoNum;
}

//根据已有的匹配识别出匹配块
void Data::createMatchedM()
{
	this->matchedM.clear();
	string block = "";
	for (int i = 0; i < this->matchedB.size(); i++)
	{
		while (i < this->matchedB.size() && this->matchedB[i] > -1)
		{
			if ((block.size() > 0 && this->matchedB[i] - this->matchedB[i - 1]==1) || block.size() == 0)
			{
				block += this->stringB[i];
				i++;
			}
			else if (block.size() > 0 && this->matchedB[i] - this->matchedB[i - 1] != 1)
			{
				i--;
				break;
			}
			else
			{
				break;
			}
		}
		if (block.size() > 0)
		{
			this->matchedM.push_back(block);
			block = "";
		}
	}
}