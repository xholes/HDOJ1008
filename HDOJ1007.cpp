#include<iostream>
#include<cmath>
#include<iomanip>
using  namespace std;
double min(double *r,int);
int main()
{
	int N,cnt=0;
	double *x, *y, *r,R[100001],rmax,temp;
	
	while (cin >> N)
	{
		int k=0;
		if (N == 0) break;
		x = new double[N];
		y = new double[N];
		r = new double[N*(N-1)/2]();
		for (int i = 0; i < N; i++)
			cin >> x[i] >> y[i];
		for (int i = 0; i < N; i++)
			for (int j = i+1 ; j < N; j++,k++)
			{ 
				int cnt = 0;
				temp = sqrt(pow((x[i] - x[j]),2)+pow((y[i] - y[j]),2))/2;		
				r[k] = temp;		 
			}				
		rmax = min(r,k);
		R[cnt] = rmax;
		cnt++;
		delete[]x;
		delete[]y;
		delete[]r;
	}
	for (int i = 0; i < cnt;i++)
			cout <<fixed<<setprecision(2)<< R[i] << endl;
//	system("pause");
	return 0;
}
double min(double *r,int cnt )
{
	int index= 0;
	for (int i = 0; i < cnt; i++)
		if (r[index] > r[i])
			index = i;
	return r[index];
}
