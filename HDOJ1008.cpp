#include<iostream>
using namespace std;
int num[5000];
int total(int n)
{
	int t=0;
	
	for (int i = 0; i < n; i++)
		num[i + 1] > num[i] ? t += 6 * (num[i + 1] - num[i]) : t += 4 * (num[i] - num[i + 1]);
	t += 5 * n;
	return t;
}
int main()
{
	int n,m=0;
	int time[50000];
	num[0] = 0;
	while (cin >> n && n)
	{
		for (int i = 1; i <= n; i++)
			cin >> num[i];
		time[m++]=total(n);	
	}
	for (int i = 0; i < m; i++)
		cout << time[i] << endl;
//	system("pause");
	return 0;
}