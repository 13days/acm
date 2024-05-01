#include<stdio.h>
#define ll long long

using namespace std;

/*
题目: https://ac.nowcoder.com/acm/contest/996/C
*/

ll qmul(ll a, ll b, ll p) {
    a %= p;
    ll ans = 0;
    for(; b; b>>=1) {
        if(b&1) ans = (ans+a)%p;
        a = a * 2 % p;
    }
    
    return ans % p;
}

int main(){
    ll a, b, p;
    scanf("%lld %lld %lld", &a, &b, &p);
    printf("%lld", qmul(a, b, p));
    return 0;
}