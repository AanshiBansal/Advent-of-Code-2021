#include <iostream>
#include<vector>
#include<queue>
#include<stack>
typedef long long ll;
using namespace std;

int main() {
	int n=100;
	ll ans=1;
	vector<string>s(n);
	vector<pair<int,int> >basin;
	for(int i=0;i<n;i++){
	    cin>>s[i];
	}
	int m=s[0].size();
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++){
	        int count=0;
	        if(i-1>=0 && s[i-1][j]<=s[i][j])
	        count++;
	        if(j-1>=0 && s[i][j-1]<=s[i][j])
	        count++;
	        if(i+1<n && s[i+1][j]<=s[i][j])
	        count++;
	        if(j+1<m && s[i][j+1]<=s[i][j])
	        count++;
	        if(count==0){
	            basin.push_back({i,j});
	        }
	    }
	}
	priority_queue<int>pq;
	for(int i=0;i<basin.size();i++){
	    stack<pair<int,int>>st;
	    int count=1;
	    st.push(basin[i]);
	    s[st.top().first][st.top().second]='-';
	    while(!st.empty()){
	        pair<int,int>top=st.top();
	        st.pop();
	        int j=top.first;
	        int k=top.second;
	        if(j-1>=0  && s[j-1][k]!='9' && s[j-1][k]!='-'){
	            s[j-1][k]='-';
	            count++;
	            st.push({j-1,k});
	        }
	        if(k-1>=0 && s[j][k-1]!='9' && s[j][k-1]!='-'){
	            s[j][k-1]='-';
	            count++;
	            st.push({j,k-1});
	        }
	        if(j+1<n  && s[j+1][k]!='9' && s[j+1][k]!='-'){
	            s[j+1][k]='-';
	            count++;
	            st.push({j+1,k});
	        }
	        if(k+1<m && s[j][k+1]!='9' && s[j][k+1]!='-'){
	            s[j][k+1]='-';
	            count++;
	            st.push({j,k+1});
	        }
	    }
	    pq.push(count);
	}
	for(int i=0;i<3;i++){
	    ans*=pq.top();
	    pq.pop();
	}
	cout<<ans;
	return 0;
}
