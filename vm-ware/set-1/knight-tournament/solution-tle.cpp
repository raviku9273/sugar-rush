#include <bits/stdc++.h>
using namespace std;

void Knight_Tournament(int n, int fights)
{
    vector<int> killer(n + 1, 0);
    
    set<int> remain;
    for(int person = 1; person <= n; person++)
        remain.insert(person);
    
    for(int i = 0; i < fights; i++)
    {
        int left, right, winner;
        cin >> left >> right >> winner;
        
        auto itr = lower_bound(remain.begin(), remain.end(), left);
        
        while(itr != remain.end() and *itr <= right)
        {
            if(*itr != winner)
                killer[*itr] = winner;
                
            itr = remain.erase(itr);
        }
        
        remain.insert(winner);
    }
    
    for(int i = 1; i <= n; i++)
        cout << killer[i] << " ";
    
    cout << endl;
}

int main()
{
	int n, fights;
	cin >> n >> fights;
	
	Knight_Tournament(n, fights);
	return 0;
}
