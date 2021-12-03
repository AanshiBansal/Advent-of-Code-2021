#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
int main() {
	int n=1000;
	ll x=0;
	ll y=0;
	string dir;
	ll val;
	for(int i=0;i<n;i++){
	    cin>>dir>>val;
	    if(dir=="forward")
			x+=val;
	    if(dir=="up")
			y-=val;
	    if(dir=="down")
			y+=val;
	}
	cout<<x*y<<endl;
	return 0;
}
