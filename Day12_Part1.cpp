#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void dfs(string curr, unordered_map<string, vector<string> >&mp, unordered_set<string>&s, ll &ans){
    if(curr=="end"){
        ans++;
        return;
    }
    if(s.find(curr)!=s.end()){
        return;
    }
    if(curr[0]>='a' && curr[0]<='z'){
        s.insert(curr);
    }
    for( int i=0;i<mp[curr].size();i++){
        dfs(mp[curr][i], mp, s, ans);
    }
    if(curr[0]>='a' && curr[0]<='z'){
        s.erase(curr);
    }
}

int main() {
	int n=24;
	unordered_map<string, vector<string> >mp;
	unordered_set<string>s;
	string u,v;
	for(int i=0;i<n;i++){
	    cin>>u>>v;
	    mp[u].push_back(v);
	    mp[v].push_back(u);
	}
	ll ans=0;
	dfs("start", mp, s, ans);
	cout<<ans<<endl;
	return 0;
}
