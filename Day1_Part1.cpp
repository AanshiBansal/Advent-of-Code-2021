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
	for(int i=1;i<n;i++){
	    if(arr[i]>arr[i-1]){
	        ans++;
	    }
	}
	cout<<ans<<endl;
	return 0;
}
