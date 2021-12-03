#include <iostream>
#include<vector>
typedef long long ll;
using namespace std;

int main() {
	int n=1000;
	int m=12;
	ll x=0;
	ll y=0;
	vector<string>s(n);
	for(int i=0;i<n;i++){
	    cin>>s[i];
	}
	
	int count=n;
	int index=0;
	vector<bool>flag(n,true);
	while(count>0){
	    int zero=0;
	    int one=0;
	    for(int i=0;i<n;i++){
	        if(flag[i]){
	            if(s[i][index]=='0')
	                zero++;
	            else
	                one++;
	        }
	    }
	    char help=one>=zero?'1':'0';
	    for(int i=0;i<n;i++){
	        if(flag[i]){
	            if(s[i][index]!=help){
	                flag[i]=false;
	                count--;
	            }
	            if(count==0){
	                for(int j=0;j<m;j++){
	                    x*=2;
	                    if(s[i][j]=='1')
	                        x+=1;
	                }
	                break;
	            }
	        }
	    }
	    index++;
	}
	
	count=n;
	index=0;
	flag=*new vector<bool>(n,true);
	while(count>0){
	    int zero=0;
	    int one=0;
	    for(int i=0;i<n;i++){
	        if(flag[i]){
	            if(s[i][index]=='0')
	                zero++;
	            else
	                one++;
	        }
	    }
	    char help=zero<=one?'0':'1';
	    for(int i=0;i<n;i++){
	        if(flag[i]){
	            if(s[i][index]!=help){
	                flag[i]=false;
	                count--;
	            }
	            if(count==0){
	                for(int j=0;j<m;j++){
	                    y*=2;
	                    if(s[i][j]=='1')
	                        y+=1;
	                }
	                break;
	            }
	        }
	    }
	    index++;
	}
	cout<<x<<" "<<y<<" "<<x*y<<endl;
	return 0;
}
