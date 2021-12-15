#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	int n=100;
	vector<string>s(n);
	for(int i=0;i<n;i++){
	    cin>>s[i];
	}
	vector<vector<ll> >dp(n,vector<ll>(n,LLONG_MAX));
	s[0][0]='0';
	dp[0][0]=0;
	for(int i=1;i<n;i++){
	    dp[i][0]=dp[i-1][0]+s[i][0]-'0';
	}
	for(int i=1;i<n;i++){
	    dp[0][i]=dp[0][i-1]+s[0][i]-'0';
	}
	for(int i=1;i<n;i++){
	    for(int j=1;j<n;j++){
	        dp[i][j]=min(dp[i-1][j],dp[i][j-1])+s[i][j]-'0';
	    }
	}
	cout<<dp[n-1][n-1];
	return 0;
}
