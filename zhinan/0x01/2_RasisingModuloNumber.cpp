#include<stdio.h>

using namespace std;

/*
题目: https://ac.nowcoder.com/acm/contest/996/B
*/


int qpow(int a, int b, int p) {
    a %= p;  // 2374859 * 3029382 会溢出
    int ans = 1;
    for(; b; b >>= 1){
        if(b&1) ans = ans * a % p;
        a = a * a % p;
    }
    return ans % p ;
}

int main() {
    int n;
    scanf("%d", &n);
    
    while(n--){
        int mod, h;
        scanf("%d", &mod);
        scanf("%d", &h);
        
        int ans = 0;
        while(h--){
            int a, b;
    
            scanf("%d %d", &a, &b);
            ans = (ans + qpow(a, b, mod)) % mod;
        }
        printf("%d\n", ans%mod);
    }
    
    return 0;
}