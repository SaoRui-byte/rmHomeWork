#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	vector<int> v;
	cin >> n;
	while (n--)
	{
		int t;
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ' ';
	}
	cout << endl;

	return 0;
}