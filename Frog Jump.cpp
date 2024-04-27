#include <bits/stdc++.h> 

 

int frogJump(int n, vector<int> &heights)

{

    int prev1 = 0;

    int prev2 = 0;

 

    for(int ind = 1; ind < n; ind++)

    {

        int one = prev1 + abs( heights[ind] - heights[ind-1] );

        int two = INT_MAX;

        if(ind > 1)

            two = prev2 + abs( heights[ind] - heights[ind-2] );

 

        int curr = min(one , two);

        prev2 = prev1;

        prev1 = curr;

    }

 

    return prev1;

}
