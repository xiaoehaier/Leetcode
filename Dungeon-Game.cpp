#include <vector>
#include <algorithm>
using namespace std;


class Solution {
  public :
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
    //二维空间DP问题
    int m = dungeon.size();
    int n = dungeon[0].size();
    //0225
    int dp[m][n];//dp[i][j]表示从(i,j)到目的地(m-1,n-1)需要的最小生命值
    //初始化
    dp[m-1][n-1] = max(0 - dungeon[m-1][n-1], 0);
    for(int i = m-2; i >= 0; i--){
      dp[i][n-1] = max(dp[i+1][n-1] - dungeon[i][n-1], 0);
    }
    for(int i = n-2; i >= 0; i--){
      dp[m-1][i] = max(dp[m-1][i+1] - dungeon[m-1][i], 0);
    }
    //从下向上，从右向左填表
    //dp方程为  dp[i][j] = min(dp[i][j+1], dp[i+1][j]) - dungeon[i][j] 再和0取最大
    for(int i = m-2; i >= 0; i--){
      for(int j = n-2; j >= 0; j--){
        dp[i][j] = max(min(dp[i][j+1], dp[i+1][j]) - dungeon[i][j], 0);
      }
    }
    return dp[0][0] + 1;

  }
};