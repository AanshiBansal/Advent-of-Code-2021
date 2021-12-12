#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void dfs(string curr, unordered_map<string, vector<string> >&mp, unordered_map<string, int>&s, ll &ans){
    if(curr=="end"){
        ans++;
        return;
    }
    if(curr=="start"){
        if(s[curr]==0){
            s[curr]++;
            for( int i=0;i<mp[curr].size();i++){
                dfs(mp[curr][i], mp, s, ans);
            }
            s[curr]--;
            return;
        }
        else
            return;
    }
    if(curr[0]>='a' && curr[0]<='z'){
        int help=0;
        for(auto itr=s.begin();itr!=s.end();itr++){
            if(itr->second == 2)
                help++;
        }
        if(help==0 || s[curr]==0){
            s[curr]++;
            for( int i=0;i<mp[curr].size();i++){
                dfs(mp[curr][i], mp, s, ans);
            }
            s[curr]--;
        }
    
    }else{
        for( int i=0;i<mp[curr].size();i++){
            dfs(mp[curr][i], mp, s, ans);
        }
    }
}

int main() {
	int n=24;
	unordered_map<string, vector<string> >mp;
	unordered_map<string,int>s;
	string u,v;
	for(int i=0;i<n;i++){
	    cin>>u>>v;
	    mp[u].push_back(v);
	    mp[v].push_back(u);
	    s[u]=0;
	    s[v]=0;
	}
	ll ans=0;
	dfs("start", mp, s, ans);
	cout<<ans<<endl;
	return 0;
}
