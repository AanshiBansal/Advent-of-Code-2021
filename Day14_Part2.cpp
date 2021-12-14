#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	int n=100;
	string s;
	cin>>s;
	
	unordered_map<string,string>mp;
	string u,v,arrow;
	for(int i=0;i<n;i++){
	    cin>>u>>arrow>>v;
	    mp[u]=v;
	}
    
    unordered_map<string,ll>ans;
    for(int i=0;i<s.size()-1;i++){
        string start=s.substr(i,2);
        ans[start]++;
    }
    
    for(int i=0;i<40;i++){
        unordered_map<string,ll>temp;
        for(auto itr=ans.begin();itr!=ans.end();itr++){
            if(mp.find(itr->first)!=mp.end()){
                string u=itr->first[0]+mp[itr->first];
                string v=mp[itr->first]+itr->first[1];
                temp[u]+=itr->second;
                temp[v]+=itr->second;
            }else{
                temp[itr->first]+=itr->second;
            }
        }
        ans=temp;
    }
    
    vector<ll>count(26,0);
    for(auto itr=ans.begin();itr!=ans.end();itr++){
        count[itr->first[0]-'A']+=itr->second;
    }
    count[s[s.size()-1]-'A']++;
    
	sort(count.begin(),count.end());
	int i=0;
	while(count[i]==0){
	    i++;
	}
	cout<<count[25]-count[i];
	return 0;
}
