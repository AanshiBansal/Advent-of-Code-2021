#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<string>help(vector<string>&v, int n, char c, string &algo){
    vector<string>ans(n+4);
    string temp="";
    for(int i=0;i<n+4;i++){
        temp+=c;
    }
    ans[0]=temp;
    ans[1]=temp;
    ans[n+2]=temp;
    ans[n+3]=temp;
    string temp2="";
    temp2+=c;
    temp2+=c;
    for(int i=0;i<n;i++){
        ans[i+2]=temp2+v[i]+temp2;
    }
    n=n+4;
    vector<string>prev=ans;
    vector<string>result(n-2);
    for(int i=1;i<n-1;i++){
        for(int j=1;j<n-1;j++){
            string curr="";
            curr+=prev[i-1].substr(j-1,3);
            curr+=prev[i].substr(j-1,3);
            curr+=prev[i+1].substr(j-1,3);
            int index=0;
            for(int k=0;k<9;k++){
                index*=2;
                if(curr[k]=='#')
                index++;
            }
            ans[i][j]=algo[index];
        }
        result[i-1]=ans[i].substr(1,n-2);
    }
    return result;
}

int main() {
	string algo;
	cin>>algo;
	int n=100;
	vector<string>v(n);
	for(int i=0;i<n;i++){
	    cin>>v[i];
	}
	vector<string>ans1=help(v,n,'.',algo);
	vector<string>ans2=help(ans1,n+2,'#',algo);
	ll result=0;
	for(int i=0;i<n+4;i++){
	    for(int j=0;j<n+4;j++){
	        if(ans2[i][j]=='#')
	        result++;
	    }
	}
	cout<<result;
	return 0;
}
