#include <iostream>
#include<vector>
typedef long long ll;
using namespace std;

int main() {
	int n=100;
	ll ans=0;
	vector<string>s(n);
	for(int i=0;i<n;i++){
	    cin>>s[i];
	}
	int m=s[0].size();
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++){
	        int count=0;
	        //cout<<s[i][j]<<" ";
	        if(i-1>=0 && s[i-1][j]<=s[i][j])
	        count++;
	        if(j-1>=0 && s[i][j-1]<=s[i][j])
	        count++;
	        if(i+1<n && s[i+1][j]<=s[i][j])
	        count++;
	        if(j+1<m && s[i][j+1]<=s[i][j])
	        count++;
	        if(count==0){
	            cout<<s[i][j]-'0'<<endl;
	            ans+=s[i][j]-'0'+1;
	        }
	    }
	}
	cout<<ans;
	return 0;
}
