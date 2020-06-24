#include <bits/stdc++.h>
using namespace std;

const long long m_inf = -1e18;

long long dist(int x1, int y1, int x2, int y2)
{
	long long res = 1LL*(x1 - x2)*(x1 - x2);
	res += 1LL*(y1 - y2)*(y1 - y2);

	return res;
}

/* ### READ-ONLY PART ### */
double pizzaDelivery(int input1, int input2, int** input3)
/* ### READ-ONLY PART ### */
{
	int speed = input1;
	int n = input2;

	vector<int> x(n), y(n);

	for(int i = 0; i < n; i++)
	{
		x[i] = input3[i][0];
		y[i] = input3[i][1];
	}

	long long max_dist = m_inf;
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			max_dist = max(max_dist, dist(x[i], y[i], x[j], y[j]));
	
	long double _time = (long double)sqrt(max_dist)/speed;

	long long extract_seven = _time*(int)(1e7);

	long long extract_six;

	/* Check how to roundoff the last digit */
	if(extract_seven % 10 >= 5)
		extract_six = extract_seven/10 + 1;
	else
		extract_six = extract_seven/10;

	double res = (double)1.0*extract_six/(int)(1e6);

	return res;
}

int main()
{
	int input1, input2;
	
	int** input3;

	const int max_n = 1e3 + 3;
	input3 = (int**)malloc(max_n*sizeof(int*));

	for(int i = 0; i < max_n; i++)
		input3[i] = (int*)malloc(2*sizeof(int));

	scanf("%d %d", &input1, &input2);
	for(int i = 0; i < input2; i++)
	{
		scanf("%d %d", &input3[i][0], &input3[i][1]);
	}

	double res = pizzaDelivery(input1, input2, input3);
	printf("%lf\n", res);

	return 0;
}
