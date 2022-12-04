#include <iostream>
#include <ctime>
using namespace std;

void triangle(int* a, int* b)
{
	double S;
	S = (*a * *b) / 2.0;
	cout << "Area = " << S << endl;
}

double& maxValue(double& q, double& w, double& e)
{
	double Max = -1000, Min = 1000, Middle;
	if (q > Max)
	{
		Max = q;
		if (w > Max)
		{
			Max = w;
			if (e > Max)//123
			{
				Max = e;
				Middle = w;
				Min = q;
				return e;
			}
			if (q > e)//231
			{
				Middle = q;
				Min = e;
				return w;
			}
			else //132
			{
				Middle = e;
				Min = q;
				return w;
			}
		}
		else if (e > Max)//213
		{
			Max = e;
			Min = w;
			Middle = q;
			return e;
		}
		else
		{
			if (w < e)//312
			{
				Min = w;
				Middle = e;
				return q;
			}
			else //321
			{
				Min = e;
				Middle = w;
				return q;
			}
		}
	}
	return q;
}

double* maximum(double* q, double* w, double* e)
{
	double Max = -1000;
	if (*q > Max)
	{
		Max = *q;
		if (*w > Max)
		{
			Max = *w;
			if (*e > Max)//123
			{
				return e;
			}
			else //231, 132
			{
				return w;
			}
		}
		else if (*e > Max)//213
		{
			return e;
		}
		else //312, 321
		{
			return q;
		}
	}
	return q;
}

void writeArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 20 - 10;
	}
}

void printArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n";
}


int& MaxArray(int a[],int n)
{
	int max = -1000, j;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
			j = i;
		}
	}
	return a[j];
}

int& MinArray(int a[],int n)
{
	int min = 1000, j;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
			j = i;
		}
	}
	return a[j];
}

int* maxArray(int b[], int n)
{
	int max = -1000, j;
	for (int i = 0; i < n; i++)
	{
		if (b[i] > max)
		{
			max = b[i];
			j = i;
		}
	}
	return &b[j];
}

int* minArray(int b[], int n)
{
	int min = 1000, j;
	for (int i = 0; i < n; i++)
	{
		if (b[i] < min)
		{
			min = b[i];
			j = i;
		}
	}
	return &b[j];
}

int main()
{
	int x, A, B, n, c;
	int* a = new int[50];
	int b[50];
	double q, w, e, Q, W, E;
	srand(time(0));
	int* ptr = &x;
	int* ptr2 = ptr;
	*ptr = 100;
	cout << *ptr << endl;
	*ptr2 = 200;
	cout << *ptr2 << endl << endl;

	cout << "Lenght = ";
	cin >> A;
	cout << "Height = ";
	cin >> B;
	triangle(&A, &B);
	cout << endl;

	cout << "First value = ";
	cin >> q;
	cout << "Second value = ";
	cin >> w;
	cout << "Third value = ";
	cin >> e;
	double& res = maxValue(q, w, e);
	res = (q + w + e) / 3;
	cout << "Result = " << res << endl;
	cout << "First value = " << q << " | Second value = " << w << " | Third value = " << e << "\n\n";

	cout << "First value = ";
	cin >> Q;
	cout << "Second value = ";
	cin >> W;
	cout << "Third value = ";
	cin >> E;
	double* RES = maximum(&Q, &W, &E);
	*RES = (Q + W + E) / 3;
	cout << "Result = " << *RES << endl;
	cout << "First value = " << Q << " | Second value = " << W << " | Third value = " << E << "\n\n";

	cout << "N = ";
	cin >> n;
	writeArray(a, n);
	cout << "Old array:" << endl;
	printArray(a, n);
	int& max = MaxArray(a,n);
	cout << "Max = " << max << endl;
	int& min = MinArray(a,n);
	cout << "Min = " << min << endl;
	c = max;
	max = min;
	min = c;
	cout << "New array:" << endl;
	printArray(a, n);

	cout << endl;
	writeArray(b, n);
	cout << "Old array:" << endl;
	printArray(b, n);
	int* Max = maxArray(b, n);
	cout << "Max = " << *Max << endl;
	int* Min = minArray(b, n);
	cout << "Min = " << *Min << endl;
	int* t = new int;
	*t = *Max;
	*Max = *Min;
	*Min = *t;
	cout << "New array:" << endl;
	printArray(b, n);

	delete[] a;
	delete t;
	return 0;
}