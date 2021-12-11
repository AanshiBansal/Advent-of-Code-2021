#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void help(vector<vector<int>>&v, int i, int j, stack<pair<int,int>>&s, int n){
    if(i>=0 && i<n && j>=0 && j<n && v[i][j]!=0){
        v[i][j]++;
        if(v[i][j]==10){
            s.push({i,j});
        }
    }
}

int main() {
	int n=10;
	vector<vector<int>>v(n,vector<int>(10));
	vector<string>a(10);
	for(int i=0;i<n;i++){
	    cin>>a[i];
	    for(int j=0;j<n;j++)
	        v[i][j]=a[i][j]-'0';
	}
	for(int x=0;;x++){
	    int curr=0;
	    stack<pair<int,int>>s;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            v[i][j]++;
	            if(v[i][j]==10){
	                s.push({i,j});
	            }
	        }
	    }
	    while(!s.empty()){
	        pair<int,int>top=s.top();
	        s.pop();
	        curr++;
	        int q=top.first;
	        int r=top.second;
	        v[q][r]=0;
	        help(v,q-1,r-1,s,n);
	        help(v,q-1,r,s,n);
	        help(v,q-1,r+1,s,n);
	        help(v,q,r-1,s,n);
	        help(v,q,r+1,s,n);
	        help(v,q+1,r-1,s,n);
	        help(v,q+1,r,s,n);
	        help(v,q+1,r+1,s,n);
	    }
	    if(curr==100){
	        cout<<x+1<<endl;
	        break;
	    }
	}
	return 0;
}
