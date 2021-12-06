#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    string str;
    cin>>str;
    stringstream ss(str);
    vector<int>v;
    for (int i; ss >> i;) {
        v.push_back(i);
        if (ss.peek() == ',')
            ss.ignore();
    }
    vector<ll>mp(9,0);
    for(int i=0;i<v.size();i++){
        mp[v[i]]++;
    }
    int days=256;
    while(days--){
        vector<ll>temp(9,0);
        for(int i=0;i<9;i++){
            if(i==0){
                temp[6]+=mp[0];
                temp[8]+=mp[0];
            }else{
                temp[i-1]+=mp[i];
            }
        }
        mp=temp;
    }
    ll ans=0;
    for(int i=0;i<9;i++){
        ans+=mp[i];
    }
            
    cout<<ans<<endl;
	return 0;
}
