#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void help(int i, int j, int n, int val, vector<vector<ll>>&risk, priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> &pq,vector<vector<int>>&ans){
    if(i>=0 && i<n && j>=0 && j<n && ans[i][j]>risk[i][j]+val){
        ans[i][j]=risk[i][j]+val;
        pq.push({ans[i][j],i*1000+j});
    }
}
int main() {
	int n=100;
	vector<string>s(n);
	for(int i=0;i<n;i++){
	    cin>>s[i];
	}
	vector<vector<ll>>risk(n*5,vector<ll>(n*5));
	for(int i=0;i<n;i++){
	    for(int j=0;j<n;j++){
	        risk[i][j]=s[i][j]-'0';
	    }
	}
	for(int k=1;k<5;k++){
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            risk[k*n+i][j]=risk[i][j]+k;
	            if(risk[k*n+i][j]>9)
	                risk[k*n+i][j]-=9;
	        }
	    }
	}
	for(int l=1;l<5;l++){
    	for(int k=0;k<5;k++){
    	    for(int i=0;i<n;i++){
    	        for(int j=0;j<n;j++){
    	            risk[k*n+i][l*n+j]=risk[k*n+i][j]+l;
    	            if(risk[k*n+i][l*n+j]>9)
    	            risk[k*n+i][l*n+j]-=9;
    	        }
    	    }
    	}
	}

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    vector<vector<int>>ans(n*5,vector<int>(n*5,INT_MAX));
    pq.push({0,0});
    ans[0][0]=0;
    while(!pq.empty()){
        pair<int,int> top=pq.top();
        pq.pop();
        int val=top.first;
        int i=top.second/1000;
        int j=top.second%1000;
        if(i==499 && j==499){
            cout<<val;
            break;
        }
        help(i-1,j,n*5,val,risk,pq,ans);
        help(i,j-1,n*5,val,risk,pq,ans);
        help(i,j+1,n*5,val,risk,pq,ans);
        help(i+1,j,n*5,val,risk,pq,ans);
        
    }
	return 0;
}