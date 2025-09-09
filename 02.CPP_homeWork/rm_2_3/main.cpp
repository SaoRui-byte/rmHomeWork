#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int x)
{
	if (x <= 1)
		return false;
	if (x == 2)
		return true;
	if (x % 2 == 0)
		return false;
	for (int i = 3; i <= sqrt(x); i+=2)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}


int main()
{
	int n;
	cin >> n;
	int sum = 2;
	int cnt = 1;
	cout << 2 << endl;
	for (int i = 3;; i += 2)
	{
		if (isPrime(i))
		{
			sum += i;
			if (sum <= n)
			{
				cout << i << endl;
				cnt++;
			}
			else
				break;
		}


	}
	cout << cnt << endl;

	return 0;
}