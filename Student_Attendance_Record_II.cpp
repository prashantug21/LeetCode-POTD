class Solution {
public:
    int checkRecord(int n) {
        vector<vector<long long>>dp(n,(vector<long long>(7,0)));
        dp[0][0]=1;
        dp[0][2]=1;
        dp[0][3]=1;

        for(int i=1;i<n;i++){
            dp[i][0]=(dp[i-1][0]+dp[i-1][3]+dp[i-1][5])%(int(1e9+7));
            dp[i][1]=(dp[i-1][1]+dp[i-1][2]+dp[i-1][4]+dp[i-1][6])%(int(1e9+7));
            dp[i][2]=(dp[i-1][0]+dp[i-1][3]+dp[i-1][5])%(int(1e9+7));
            dp[i][3]=dp[i-1][0];
            dp[i][4]=(dp[i-1][1]+dp[i-1][2])%(int(1e9+7));
            dp[i][5]=dp[i-1][3];
            dp[i][6]=dp[i-1][4];
        }
        return (dp[n-1][0]+dp[n-1][1]+dp[n-1][2]+dp[n-1][3]+dp[n-1][4]+dp[n-1][5]+dp[n-1][6])%(int(1e9+7));
        
    }
};