#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[5105],dp[5105];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(a[j]<a[i]) dp[i]=max(dp[i],dp[j]+1);
		}
	}
	return 0;
}
