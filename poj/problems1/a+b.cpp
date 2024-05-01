#include<stdio.h>
#include<string>
#include<cstring>
#include<string.h>

using namespace std;

struct Num{
	int a[1000];
	int len, poi;
	Num(){
		memset(a, 0, sizeof a);
	}

	void setOne(){
		memset(a, 0, sizeof a);
		a[0]=1;
		len = 1;
		poi=0;
	}

	void pre(char c[]){
		// 预处理
		int l = strlen(c);
		// 反过来
		for(int i=l-1; i>=l/2; i--){
			char t = c[i];
			c[i] = c[l-1-i];
			c[l-1-i] = t;
		}

		poi = 0; len = 0;
		memset(a, 0, sizeof a);
		for(int i=0; i<l; i++){
			if(c[i]=='.'){
				poi=i; // 小数点后有几位
			} else {
				a[len++] = c[i] - '0';
			}
		}

		// debug
		// for(int i=0; i<len; i++){
		// 	printf("%d", a[i]);
		// }
		// printf(" %d\n", poi);
	}
	void print(){
	
		// printf("poi %d\n", poi);
		int pi = 0, idx=0;
		char c[1000];
		for(int i=len-1; i>=0; i--){
			// 打印了 pi 个后打印 .
			if(poi>0 && pi==len-poi){ // 1234.56789, poi=5, len=9, len-poi=4, 允许先打印4个
				c[idx++]='.';
			}
			c[idx++]=a[i]+'0';
			pi++;
		}
		
		// 打印结果
		int i = 0, j=idx-1;
		while(c[i]=='0')i++;
		while(poi>0 && c[j]=='0')j--;
		if(c[j]=='.')j--;
		for(; i<=j; i++){
			printf("%c", c[i]);
		}

		printf("\n");
	}

	Num mul(Num b){
		Num ans;
		for(int i=0; i<len; i++){
			for(int j=0; j<b.len; j++){
				ans.a[i+j] += a[i] * b.a[j];
			}
		}
		ans.len = len + b.len - 1;
		for(int i=0; i<ans.len; i++){
			if (ans.a[i]>=10){
				ans.a[i+1] += ans.a[i]/10;
				ans.a[i] %= 10;
			}
		}
		if(ans.a[ans.len]>0){
			ans.len++;
		}
		ans.poi = poi + b.poi;
		return ans;
	}
};

Num qpow(Num a, int q) {
	Num ans;
	ans.setOne();
	while(q){
		if (q&1)ans=ans.mul(a);
		a = a.mul(a);
		q>>=1;
	}
	return ans;
}

int main(){
	char a[1000];
	int n;	
	while(~scanf("%s %d", a, &n)) {
		Num ans;
		ans.pre(a);
		ans = qpow(ans, n);
		ans.print();
	}
	return 0;
}
