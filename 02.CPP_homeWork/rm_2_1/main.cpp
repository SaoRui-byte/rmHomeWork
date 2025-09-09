#include<iostream>
using namespace std;

int fb(int n)
{
	if (n == 1 || n == 2)
		return 1;
	return fb(n - 1) + fb(n - 2);

}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int t;
		cin >> t;
		cout << fb(t) << endl;
	}
	return 0;
}