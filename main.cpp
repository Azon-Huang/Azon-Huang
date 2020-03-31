
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,track;
    while(cin >> n >> track){
        vector<vector<int>> dp(n+1,vector<int>(track+1,0));
        vector <int> cost(track+1);
        for(int i=1;i<=track;i++)
            cin >> cost[i];

        for(int i=1;i<=n;i++){
            for(int j=1;j<=track;j++){
                if(cost[j]<=i)
                    dp[i][j] = max(dp[i-cost[j]][j-1]+cost[j],dp[i][j-1]);
                else
                    dp[i][j] = dp[i][j-1];
            }
        }

/*
        for(int i=0;i<=n;i++){
            for(int j=0;j<=track;j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
*/
        vector <int> ans;
        int i=n,j=track;
        while(true){
            if(i==0||j==0)break;
            if(dp[i][j]==dp[i][j-1])
                j = j-1;
            else{
                ans.push_back(cost[j]);
                i = i-cost[j];
                j = j-1;
            }
        }
        for(int i=ans.size()-1;i>=0;i--){
            cout << ans[i] << " ";
        }
        cout << "sum:" << dp[n][track];
        cout << endl;

    }
    return 0;
}

/*
\  1 2 3    1 2 3
1  0 0 0    1 3 4
2  0 0 0
3  0 0 0
3  0 0 0
4  0 0 0
5  0 0 0

*/
