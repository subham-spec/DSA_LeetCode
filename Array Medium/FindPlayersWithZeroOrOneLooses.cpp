#include <bits/stdc++.h>
#include <set>
using namespace std;
vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        // set for winners
        set<int> win;
        // set for loosers
        set<int> loose;
        // storing all the players one by one
        for(int i=0; i<matches.size(); i++){
            if(!win.count(matches[i][0])){
                win.insert(matches[i][0]);
                loose.insert(matches[i][0]);
            }
            if(!win.count(matches[i][1])){
                win.insert(matches[i][1]);
                loose.insert(matches[i][1]);
            }
        }
        for(int i=0; i<matches.size(); i++){
            // if the player looses then it will be removed from winners
            if(win.count(matches[i][1]))
                win.erase(matches[i][1]);
            // if the players is not in winners that is he already loose one match
            else
                loose.erase(matches[i][1]);
        }
        // result for answer
        vector<vector<int>> ans;
        // for winners
        vector<int> v1;
        for(auto i=win.begin(); i!=win.end(); i++)
            v1.push_back(*i);
        // sorting the wins
        sort(v1.begin(), v1.end());
        ans.push_back(v1);

        // for loosers
        vector<int> v2;
        for(auto i= loose.begin(); i!=loose.end(); i++){
            if(win.count(*i))
                continue;
            v2.push_back(*i);
        }
        // sorting the loosers
        sort(v2.begin(), v2.end());
        ans.push_back(v2);

        return ans;
    }

/*
You are given an integer array matches where matches[i] = [winneri, loseri] indicates that the player winneri defeated player loseri in a match.

Return a list answer of size 2 where:

answer[0] is a list of all players that have not lost any matches.
answer[1] is a list of all players that have lost exactly one match.
The values in the two lists should be returned in increasing order.

Note:

You should only consider the players that have played at least one match.
The testcases will be generated such that no two matches will have the same outcome.
 

Example 1:

Input: matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
Output: [[1,2,10],[4,5,7,8]]
Explanation:
Players 1, 2, and 10 have not lost any matches.
Players 4, 5, 7, and 8 each have lost one match.
Players 3, 6, and 9 each have lost two matches.
Thus, answer[0] = [1,2,10] and answer[1] = [4,5,7,8].
Example 2:

Input: matches = [[2,3],[1,3],[5,4],[6,4]]
Output: [[1,2,5,6],[]]
Explanation:
Players 1, 2, 5, and 6 have not lost any matches.
Players 3 and 4 each have lost two matches.
Thus, answer[0] = [1,2,5,6] and answer[1] = [].

Constraints:

1 <= matches.length <= 105
matches[i].length == 2
1 <= winneri, loseri <= 105
winneri != loseri
All matches[i] are unique.
*/