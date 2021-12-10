#include <iostream>
#include<vector>
#include<stack>
typedef long long ll;
using namespace std;

int main() {
	int n=94;
	ll ans=0;
	vector<string>s(n);
	for(int i=0;i<n;i++){
	    cin>>s[i];
	}
	for(int i=0;i<n;i++){
	    stack<char>st;
	    for(int j=0;j<s[i].size();j++){
	        if(s[i][j]=='[' || s[i][j]=='(' || s[i][j]=='{' || s[i][j]=='<'){
	            st.push(s[i][j]);
	        }else{
	            char top=st.top();
	            st.pop();
	            if(s[i][j]==')' && top!='('){
	                ans+=3;
	                break;
	            }
	            if(s[i][j]==']' && top!='['){
	                ans+=57;
	                break;
	            }
	            if(s[i][j]=='}' && top!='{'){
	                ans+=1197;
	                break;
	            }
	            if(s[i][j]=='>' && top!='<'){
	                ans+=25137;
	                break;
	            }
	        }
	    }
	}
	cout<<ans;
	return 0;
}
