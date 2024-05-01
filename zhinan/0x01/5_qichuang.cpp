#include<stdio.h>

using namespace std;

/*
https://ac.nowcoder.com/acm/contest/996/E
*/

int n, m;
int a[100005];
char c[100005][3];

// ^|& 计算每一位都是单独的, 不影响其他结果
int calc(int v){
    for(int i=1; i<=n; i++){
        if(c[i][0]=='A'){
            v &= a[i];
        } else if(c[i][0]=='O'){
            v |= a[i];
        } else {
            v ^= a[i];
        }
    }
    return v;
}

int main(){
    scanf("%d %d", &n, &m);
    
    for(int i=1; i<=n; i++){
        scanf("%s %d", c[i], &a[i]);
    }
    
    int ans = 0;
    int res0 = calc(0);
    // 枚举 m 的高位
    for(int i=30; i>=0; i--) {
        // 如果超过 m 就不行
        // 如果结果变大就选, 从高位往下必是最优, 贪心
        int temp = ans | (1<<i); // 注意加括号
        if(temp>m) continue; 
        
        // 解法1: 选或者不选
//         int res1 = calc(ans);
//         int res2 = calc(temp);
//         if(res2>res1) ans = temp;
        
        // 解法2: 判断第i位0, 1的情况
        if((res0>>i)&1) continue; // 第i位不选就能得出, 第i位结果位1
        int res = calc(1<<i);
        if((res>>i)&1) ans = temp;
    }
    printf("%d", calc(ans));
    return 0;
}