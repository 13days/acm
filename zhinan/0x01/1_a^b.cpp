#include<stdio.h>
#define ll long long

using namespace std;
/*
题目: https://ac.nowcoder.com/acm/contest/996/A
*/

ll qpow(ll a, ll b, ll p) {
    a %= p;
    ll ans = 1;
    for(; b; b>>=1) {
        if(b&1) ans = (ans*a)%p;
        a = (a*a)%p;
    }
    return ans%p; // 注意这里要 %p; 输入 1 0 1, 结果 0
}

int main(){
    ll a, b, p;
    scanf("%lld %lld %lld", &a, &b, &p);
    
    printf("%lld", qpow(a, b, p));
    
    return 0;
}