#include<iostream>
using namespace std;

int jc(int n)
{
	int s = 1;
	if (n == 1 || n == 0)
		return 1;
	return n * jc(n - 1);
}


int main()
{
	int n;
	while (cin >> n)
	{
		cout << jc(n) << endl;
	}

	return 0;
}