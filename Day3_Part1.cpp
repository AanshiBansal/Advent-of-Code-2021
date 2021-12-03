#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
int main() {
	int n=1000;
	int m=12;
	vector<int>ones(m,0);
	ll x=0;
	ll y=0;
	string s;
	for(int i=0;i<n;i++){
	    cin>>s;
	    for(int j=0;j<m;j++){
	        if(s[j]=='1')
	            ones[j]++;
	    }
	}
	for(int j=0;j<m;j++){
	    x*=2;
	    y*=2;
	    if(ones[j]>n/2)
	        x+=1;
        else
	        y+=1;
	}
	cout<<x*y<<endl;
	return 0;
}
