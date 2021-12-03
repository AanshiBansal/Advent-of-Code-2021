#include <iostream>
#include<vector>
using namespace std;

int main() {
	// your code goes here
	int n=1000;
	int m=12;
	long long x=0;
	long long y=0;
	vector<string>s(n);
	for(int i=0;i<n;i++){
	    cin>>s[i];
	}
	int count=n;
	int index=0;
	vector<bool>flago(n,true);
	while(count>0){
	    cout<<index<<" "<<count<<endl;
	    vector<int>zero(m,0);
	    vector<int>one(m,0);
	    for(int i=0;i<n;i++){
	        if(flago[i]){
	            if(s[i][index]=='0')
	            zero[index]++;
	            else
	            one[index]++;
	        }
	    }
	    cout<<zero[index]<<" "<<one[index]<<endl;
	    char help=one[index]>=zero[index]?'1':'0';
	    for(int i=0;i<n;i++){
	        if(flago[i]){
	            if(s[i][index]!=help){
	                flago[i]=false;
	                count--;
	            }
	            if(count==0){
	                //count--;
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
	vector<bool>flag(n,true);
	while(count>0){
	    
	    vector<int>zero(m,0);
	    vector<int>one(m,0);
	    for(int i=0;i<n;i++){
	        if(flag[i]){
	            if(s[i][index]=='0')
	            zero[index]++;
	            else
	            one[index]++;
	        }
	    }
	    
	    char help=zero[index]<=one[index]?'0':'1';
	    for(int i=0;i<n;i++){
	        if(flag[i]){
	            if(s[i][index]!=help){
	                flag[i]=false;
	                count--;
	            }
	            if(count==0){
	                //count--;
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
