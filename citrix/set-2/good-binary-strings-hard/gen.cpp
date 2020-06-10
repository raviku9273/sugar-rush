#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b)
{
	return a + rand()%(b - a + 1);
}

int main(int argc, char* argv[])
{
	srand(atoi(argv[1]));

	int half_n = rand(1000, 2000);
	int n = half_n*2;

	vector<int> a(n);
	int opening = 0, closing = 0;

	for(int i = 0; i < n; i++)
	{
		if(opening == closing)
		{
			a[i] = 1;
			opening++;
		}
		else
		{
			if(opening == half_n)
			{
				a[i] = 0;
				closing++;
			}
			else
			{
				a[i] = rand(0, 1);

				if(a[i] == 1)
					opening++;
				else
					closing++;
			}
		}
	}

	for(int i = 0; i < n; i++)
		cout << a[i];

	cout << endl;
	return 0;
}
