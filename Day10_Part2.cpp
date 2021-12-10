#include <iostream>
#include<vector>
#include<stack>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	int n=94;
	vector<string>s(n);
	vector<ll>score;
	for(int i=0;i<n;i++){
	    cin>>s[i];
	}
	for(int i=0;i<n;i++){
	    stack<char>st;
	    bool flag=false;
	    for(int j=0;j<s[i].size();j++){
	        if(s[i][j]=='[' || s[i][j]=='(' || s[i][j]=='{' || s[i][j]=='<'){
	            st.push(s[i][j]);
	        }else{
	            char top=st.top();
	            st.pop();
	            if(s[i][j]==')' && top!='('){
	                flag=true;
	                break;
	            }
	            if(s[i][j]==']' && top!='['){
	                flag=true;
	                break;
	            }
	            if(s[i][j]=='}' && top!='{'){
	                flag=true;
	                break;
	            }
	            if(s[i][j]=='>' && top!='<'){
	                flag=true;
	                break;
	            }
	        }
	    }
	    if(flag==false){
	        ll curr=0;
	        while(!st.empty()){
	            curr*=5;
	            char top=st.top();
	            st.pop();
	            if(top=='('){
	                curr+=1;
	            }
	            if(top=='['){
	                curr+=2;
	            }
	            if(top=='{'){
	                curr+=3;
	            }
	            if(top=='<'){
	                curr+=4;
	            }
	            
	        }
	        score.push_back(curr);
	    }   
	}
	
	sort(score.begin(),score.end());
	int mid=score.size()/2;
	cout<<score[mid];
	return 0;
}