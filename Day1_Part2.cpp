#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
int main() {
	int n=2000;
	vector<int>arr(n);
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	int ans=0;
	int prev=arr[0]+arr[1]+arr[2];
	for(int i=1;i+2<n;i++){
	    int curr=arr[i]+arr[i+1]+arr[i+2];
	    if(curr>prev){
	        ans++;
	    }
	    prev=curr;
	}
	cout<<ans<<endl;
	return 0;
}
