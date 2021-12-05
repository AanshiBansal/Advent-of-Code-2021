#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int n=500;
    int m=1000;
    vector<vector<int>>arr(m, vector<int>(m,0));
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        stringstream ss(str);
        vector<int>v;
        for (int i; ss >> i;) {
            v.push_back(i);
            if (ss.peek() == ',')
                ss.ignore();
        }
        cin>>str;
        cin>>str;
        stringstream ss2(str);
        for (int i; ss2 >> i;) {
            v.push_back(i);
            if (ss2.peek() == ',')
                ss2.ignore();
        }
        
        if(v[0]>v[2]){
            swap(v[0],v[2]);
            swap(v[1],v[3]);
        }
        if(v[0]==v[2] && v[1]>v[3]){
            swap(v[1],v[3]);
        }
        
        if(v[0]==v[2]){
            for(int j=v[1];j<=v[3];j++){
                arr[v[0]][j]++;
            }
            continue;
        }
        
        if(v[1]==v[3]){
            for(int j=v[0];j<=v[2];j++){
                arr[j][v[1]]++;
            }
            continue;
        }
        
        if(v[0]-v[2] == v[1]-v[3] && v[1]<=v[3]){
            int diff=v[2]-v[0];
            for(int j=0;j<=diff;j++){
                arr[v[0]+j][v[1]+j]++;
            }
            continue;
        }
        
        if(abs(v[0]-v[2]) == abs(v[1]-v[3]) && v[1]>=v[3]){
            int diff=v[2]-v[0];
            for(int j=0;j<=diff;j++){
                arr[v[0]+j][v[1]-j]++;
            }
            continue;
        }
        
    }
    int ans=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]>1){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
	return 0;
}
