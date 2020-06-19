#include<bits/stdc++.h>
using namespace std;

void simulate()
{
	long long leaves_remain = 1e16;
	int percentage = 30;

	int day = 1;
	while(leaves_remain > 0)
	{
		cout << "Day is " << day << endl;

		long long leaves_fallen = ceil(1.0*leaves_remain*percentage/100);
		leaves_remain -= leaves_fallen;

		assert(leaves_remain >= 0);

		cout << "Leaves fallen is " << leaves_fallen << endl;
		cout << "Leaves remaining is " << leaves_remain << endl;

		day++;
	}
}

int main()
{
	simulate();
	return 0;
}
