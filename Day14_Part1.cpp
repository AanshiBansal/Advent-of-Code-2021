#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	int n=100;
	string start;
	cin>>start;
	unordered_map<string,string>mp;
	string u,v,arrow;
	for(int i=0;i<n;i++){
	    cin>>u>>arrow>>v;
	    mp[u]=v;
	}
	for(int i=0;i<10;i++){
	    string curr="";
	    for(int j=0;j<start.size()-1;j++){
	        curr+=start[j];
	        if(mp.find(start.substr(j,2))!=mp.end()){
	            curr+=mp[start.substr(j,2)];
	        }
	    }
	    curr+=start[start.size()-1];
	    start=curr;
	}
	vector<ll>count(26,0);
	for(int i=0;i<start.size();i++){
	    count[start[i]-'A']++;
	}
	sort(count.begin(),count.end());
	int i=0;
	while(count[i]==0){
	    i++;
	}
	cout<<count[25]-count[i];
	return 0;
}
