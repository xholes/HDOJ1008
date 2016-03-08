#include<iostream>
#include<cmath>
#include<iomanip>
using  namespace std;
const int SIZE= 100005;
typedef struct
{
	double x;
	double y;
}coord;

coord dot[SIZE];
double dis[SIZE];

double min(int n)
{
	int index = 0;
	for (int i = 0; i < n; i++)
		if (dis[index]>dis[i])
			index = i;
	return dis[index];
}

double distance(int n)
{
	double temp, distance = 65536;
	for (int num = 0; num < n; num++)
	{
		for (int i = 0; i < n; i++)
		{
			if (i == num) continue;
			temp = sqrt(pow(dot[num].x - dot[i].x,2.0) + pow(dot[num].y - dot[i].y, 2.0));
			if (temp < distance)
				distance = temp;
			
		}
	} 
	return distance;
}




int main()
{
	int n,cnt=0;
	while (cin >> n && n!=0)
	{
		for (int i = 0; i < n;i++)
			cin >> dot[i].x >> dot[i].y;
		dis[cnt]=distance(n);
		cnt++;
	}
	for (int i = 0; i < cnt; i++)
		cout <<fixed<<setprecision(2)<< dis[i]/2 << endl;
//	system("pause");
	return 0;
}
 
