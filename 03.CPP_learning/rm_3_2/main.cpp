#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

vector<vector<int>> v(10000);

int rI()
{
	int n = 0;
	char c;
	while ((c = getchar()) == ' '){}
	while (c >= '0' && c <= '9')
	{
		n = n * 10 + (c - '0');
		c = getchar();
	}
	return n;
}

string rS()
{
	string s;
	char c;
	while ((c = getchar()) == ' '){}
	while (c >= 'a' && c <= 'z')
	{
		s += c;
		c = getchar();
	}
	return s;
}


int main()
{
	int n;
	cin >> n;
	getchar();
	while (n--)
	{
		string choice = rS();
		if (choice == "new")
		{
			int id = rI();
		}
		else if (choice == "add")
		{
			int id = rI();
			int num = rI();
			v[id].push_back(num);
		}
		else if (choice == "merge")
		{
			int id1 = rI();
			int id2 = rI();
			if (id1 != id2)
			{
				for (int i : v[id2])
				{
					v[id1].push_back(i);
				}
				v[id2].clear();
			}
		}
		else if (choice == "unique")
		{
			int id = rI();
			sort(v[id].begin(), v[id].end());
			vector<int>::iterator iter = unique(v[id].begin(), v[id].end());
			v[id].erase(iter, v[id].end());
		}
		else if (choice == "out")
		{
			int id = rI();
			sort(v[id].begin(), v[id].end());
			for (int i = 0; i < v[id].size(); i++)
			{
				cout << v[id][i] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}