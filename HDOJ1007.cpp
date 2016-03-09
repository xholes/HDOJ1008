#include<iostream>
#include<cmath>
#include<iomanip>
#include<float.h> 
using namespace std;
typedef struct
{
	double x;
	double y;
}coord;
const int S= 100005;
coord dot[S];//存储点组
double dis[S];//存储每一组数据的结果
double temps[S];//临时存储 

//merge_sort{A 为数组ptr，r为数组的首尾元素下标}
void mymerge(coord A[], int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	coord *L, *R;
	L = new coord[n1 + 1];
	R = new coord[n2 + 1];
	for (int i = 0; i < n1; i++)
		L[i] = A[p + i];
	for (int i = 0; i < n2; i++)
		R[i] = A[q + i + 1];
	L[n1].x = DBL_MAX;
	R[n2].x = DBL_MAX;
	for (int k = p, i = 0, j = 0; k <= r; k++)
	{
		if (L[i].x <= R[j].x)
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
		}
	}
}
void mymerge_sort(coord A[], int p, int r)
{
	int q = 0;
	if (p < r)
	{
		q = (r + p) / 2;
		mymerge_sort(A, p, q);
		mymerge_sort(A, q + 1, r);
		mymerge(A, p, q, r);
	}
}

double mindis(int n)
{
	int index = 0;
	for (int i = 0; i < n; i++)
		if (temps[index]>temps[i])
			index = i;
	return temps[index];
}
double distance(coord &a,coord &b)
{
		return	 sqrt(pow(a.x - b.x,2.0) + pow(a.y - b.y, 2.0));
}

double  divide_conquer(int low,int high)
{
	double dis;
	int cnt, mid;
	cnt = high - low;
	if (cnt == 1)
		 dis=distance(dot[0], dot[1]);
	if (cnt == 2)
	{
		temps[0] = distance(dot[0], dot[1]);
		temps[1] = distance(dot[0], dot[2]);
		temps[2] = distance(dot[2], dot[1]);
		dis=mindis(3);
	}
	if (cnt > 2)
	{  
		double midlength;
		int k,l=0;
		coord *neigdot;
		mid = (low + high) / 2;
		temps[0]=divide_conquer(low,mid);
		temps[1]=divide_conquer(mid + 1, high);
		dis = mindis(2);
		//计算点分在两边的情况
		neigdot = new coord[S]; 

		for (k = 0; k <= cnt; k++)
			if (dot[k].x >= dot[mid].x - dis && dot[k].x <= dot[mid].x + dis)
				neigdot[k] = dot[k];
		mymerge_sort(neigdot,0,k-1);
		for (int i = 0; i < k; i++)
		{
			for (int j = i; j < 7; j++)
				for (int m = j; m < 7; m++)
					temps[l] = distance(neigdot[j], neigdot[m]);
			midlength = mindis(21);
			if (midlength < dis)
				dis = midlength;
		}
	}

	return dis;
}

int main()
{
	int n,cnt=0;
	while (cin >> n && n!=0)
	{
		for (int i = 0; i < n;i++)
			cin >> dot[i].x >> dot[i].y;
		mymerge_sort(dot, 0, n - 1);
		dis[cnt]=divide_conquer(0,n-1);
		cnt++;
	}
	for (int i = 0; i < cnt; i++)
		cout <<fixed<<setprecision(2)<< dis[i]/2 << endl;
//	system("pause");
	return 0;
}
 
