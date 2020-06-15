#include<bits/stdc++.h>
using namespace std;

void Stones(vector<int> &a, int maxHeapVal)
{
	int n = a.size();
	
	vector<int> playerList = {0, 1};

	vector<vector<int>> dp(maxHeapVal + 1, vector<int>(2, -1));
	
	/* dp[heap_val][first_player] denotes the winner when the game starts with 'heap_val' stones
	 * and the player numbered 'first_player' is the first to play
	 */
	
	// Nothing to pick. You lose.
	for(int first_player : playerList)
		dp[0][first_player] = not first_player;

	for(int heap_val = 1; heap_val <= maxHeapVal; heap_val++)
	{
		for(int first_player : playerList)
		{
			bool possible_to_win = false;
			for(auto choice : a)
				if(choice <= heap_val)
					if(dp[heap_val - choice][not first_player] == first_player)
						possible_to_win = true;
		
			if(possible_to_win)
				dp[heap_val][first_player] = first_player;
			else
				dp[heap_val][first_player] = not first_player;
		}
	}
	
	if(dp[maxHeapVal][0] == 0)
		cout << "First" << endl;
	else
		cout << "Second" << endl;
}

int main()
{
	int n, maxHeapVal;
	cin >> n >> maxHeapVal;

	vector<int> a(n);
	for(auto &ele : a)
		cin >> ele;

	Stones(a, maxHeapVal);
	return 0;
}

