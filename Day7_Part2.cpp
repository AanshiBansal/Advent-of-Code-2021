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
    ll mean=0;
    for(int i=0;i<v.size();i++){
        mean+=v[i];
    }
    mean/=v.size();
    ll fuel=0;
    for(int i=0;i<v.size();i++){
        ll change = abs(v[i]-mean);
        fuel+=(change*(change+1))/2;
    }
    cout<<fuel;
	return 0;
}
