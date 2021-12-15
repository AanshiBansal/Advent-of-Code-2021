#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	string str;
	cin>>str;
    vector<int> v;
    stringstream ss(str);
    for (int i; ss >> i;) {
        v.push_back(i);
        if (ss.peek() == ',')
            ss.ignore();
    }
    sort(v.begin(),v.end());
    int median=v[v.size()/2];
    ll fuel=0;
    for(int i=0;i<v.size();i++){
        fuel+=abs(v[i]-median);
    }
    cout<<fuel;
	return 0;
}
