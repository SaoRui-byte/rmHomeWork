#include<iostream>
using namespace std;

int cb(int n)
{
	int a = 1, b = 1, s;
	for (int i = 0; i < n - 1; i++)
	{
		s = a + b;
		a = b;
		b = s;
	}
	return b;
}

int main()
{
	int n;
	while (cin >> n)
	{
		cout << cb(n) << endl;
	}
	return 0;
}

/*

	int cb(int n) {
		if (n == 1)
		{
			return 1;
		}
		if(n == 2)
		{
			return 2;
		}
		return cb(n-1)+cb(n-2);
	}

	这种递归更简单，但是超时了。

*/