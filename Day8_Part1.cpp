#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int n=200;
    vector<vector<string> >in(n,vector<string>(10));
    vector<vector<string> >out(n,vector<string>(4));
    string help;
    for(int i=0;i<n;i++){
        for(int j=0;j<10;j++){
            cin>>in[i][j];
        }
        cin>>help;
        for(int j=0;j<4;j++)
        {
            cin>>out[i][j];
        }
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            if(out[i][j].size()==2 || out[i][j].size()==3 || out[i][j].size()==4 || out[i][j].size()==7){
                ans++;
            }
        }
    }
    cout<<ans;
	return 0;
}
