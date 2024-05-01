#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;


/*
题目: https://ac.nowcoder.com/acm/contest/996/D
*/

int n;
int mp[33][33];
int dp[1<<20][33];
int ans = 1e9;
bool used[33];

// 当前在 x 点， 当前答案， 单前步数
// 复杂度过高, 超时了
void dfs(int x, int tempAns, int level) {
    if(tempAns >= ans) {
        return;
    }
    if(x==n && level==n){
        ans = min(ans, tempAns);
        return;
    }
    
    for(int i=2; i<=n; i++) {
        if(!used[i]){
            used[i]=true;
            tempAns += mp[x][i];
            dfs(i, tempAns, level+1);
            tempAns -= mp[x][i];
            used[i]=false;
        }
    }
    return;
}

int solve(){
    memset(mp, 0x3f, sizeof mp);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &mp[i][j]);
        }
    }
    
    
    // dp[i][j], 表示当前走过了i, 在j
    // dp[h][k] + mp[k][j], 表示走过了h, 在k, 从k走到h, h不包含k
    // dp[i][j] = min(dp[i][j], dp[h][k]+mp[k][j]), 则 h=i^(1<<j)
    
    memset(dp, 0x3f, sizeof dp);
    dp[1][0] = 0; // 1表示走了0号位置, 0表示当前在0
    for(int i=1; i<1<<n; i++) { // 枚举所有状态
        for(int j=0; j<n; j++){ // 当前位置
            if(i>>j&1){ // i中有j号位置
                for(int k=0; k<n; k++){
                    int h=i^(1<<j); // i中没有j号位置
                    if(h>>k&1){ // h中有k
                        dp[i][j] = min(dp[i][j], dp[h][k]+mp[k][j]);
                        //printf("i=%d, j=%d, h=%d, k=%d, dij=%d, mp=%d\n", i, j, h, k, dp[i][j], mp[k][j]);
                    }
                }
            }
        }
    }
    
    // 走过了 0~n-1, 在n-1
    return dp[(1<<n)-1][n-1];
}

int main(){
    scanf("%d", &n);
//     memset(mp, 0x3f, sizeof mp);
//     for(int i=1; i<=n; i++){
//         for(int j=1; j<=n; j++){
//             scanf("%d", &mp[i][j]);
//         }
//     }
//     dfs(1, 0, 1);
//     printf("%d", ans);
    printf("%d", solve());
    return 0;
}