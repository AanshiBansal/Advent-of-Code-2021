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
    int days=80;
    while(days--){
        int size=v.size();
        for(int i=0;i<size;i++){
            if(v[i]==0){
                v[i]=6;
                v.push_back(8);
            }else{
                v[i]--;
            }
        }
    }
    cout<<v.size()<<endl;
	return 0;
}
