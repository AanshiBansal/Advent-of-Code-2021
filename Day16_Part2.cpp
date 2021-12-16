#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll calc(string type,vector<ll>v){
    ll ans;
    if(type=="000"){
        ans=0;
        for(int i=0;i<v.size();i++){
            ans+=v[i];
        }
    }
    if(type=="001"){
        ans=1;
        for(int i=0;i<v.size();i++){
            ans*=v[i];
        }
    }
    if(type=="010"){
        ans=LLONG_MAX;
        for(int i=0;i<v.size();i++){
            ans=min(ans,v[i]);
        }
    }
    if(type=="011"){
        ans=LLONG_MIN;
        for(int i=0;i<v.size();i++){
            ans=max(ans,v[i]);
        }
    }
    if(type=="101"){
        if(v[0]>v[1])
        ans=1;
        else
        ans=0;
    }
    if(type=="110"){
        if(v[0]<v[1])
        ans=1;
        else
        ans=0;
    }
    if(type=="111"){
        if(v[0]==v[1])
        ans=1;
        else
        ans=0;
    }
    return ans;
};

int helper(string &s, int i, int packets, int end, string id, vector<ll>&ans){
    if(end==-1){
        if(packets==0){
            return i;
        }
        i+=3;
        string type=s.substr(i,3);
        i+=3;
        if(type=="100"){
            ll literal=0;
            while(s[i]=='1'){
                for(int j=i+1;j<i+5;j++){
                    literal*=2;
                    if(s[j]=='1')
                        literal++;
                }
                i+=5;
            }
            for(int j=i+1;j<i+5;j++){
                literal*=2;
                if(s[j]=='1')
                    literal++;
            }
            i+=5;
            ans.push_back(literal);
            return helper(s, i, packets-1, -1, id, ans);
        }else{
            char lengthType=s[i];
            i++;
            if(lengthType=='0'){
                string size=s.substr(i,15);
                int sizeNum=stoi(size, 0, 2);
                i+=15;
                vector<ll>temp;
                int end=helper(s, i, -1, i+sizeNum,type,temp);
                ll curr=calc(type,temp);
                ans.push_back(curr);
                return helper(s,end,packets-1,-1,id,ans);
            }else{
                string count=s.substr(i,11);
                int countNum=stoi(count, 0, 2);
                i+=11;
                vector<ll>temp;
                int end=helper(s, i, countNum, -1,type,temp);
                ll curr=calc(type,temp);
                ans.push_back(curr);
                return helper(s,end,packets-1,-1,id,ans);
            }
        }
    }else{
        if(end==i)
            return end;
        i+=3;
        string type=s.substr(i,3);
        i+=3;
        if(type=="100"){
            ll literal=0;
            while(s[i]=='1'){
                for(int j=i+1;j<i+5;j++){
                    literal*=2;
                    if(s[j]=='1')
                        literal++;
                }
                i+=5;
            }
            for(int j=i+1;j<i+5;j++){
                literal*=2;
                if(s[j]=='1')
                    literal++;
            }
            i+=5;
            ans.push_back(literal);
            return helper(s,i,-1,end,id,ans);
        }else{
            char lengthType=s[i];
            i++;
            if(lengthType=='0'){
                string size=s.substr(i,15);
                int sizeNum=stoi(size, 0, 2);
                i+=15;
                vector<ll>temp;
                helper(s, i, -1, i+sizeNum, type,temp);
                ll curr=calc(type,temp);
                ans.push_back(curr);
                return helper(s,i+sizeNum,-1,end,id,ans);
            }else{
                string count=s.substr(i,11);
                int countNum=stoi(count, 0, 2);
                i+=11;
                vector<ll>temp;
                int start=helper(s,i,countNum,-1,type,temp);
                ll curr=calc(type,temp);
                ans.push_back(curr);
                return helper(s,start,-1,end,id,ans);
            }
        }
    }
}
int main() {
	string s;
	cin>>s;
	string ss;
	unordered_map<char,string>mp;
	mp['0']="0000";
	mp['1']="0001";
	mp['2']="0010";
	mp['3']="0011";
	mp['4']="0100";
	mp['5']="0101";
	mp['6']="0110";
	mp['7']="0111";
	mp['8']="1000";
	mp['9']="1001";
	mp['A']="1010";
	mp['B']="1011";
	mp['C']="1100";
	mp['D']="1101";
	mp['E']="1110";
	mp['F']="1111";
	for(int i=0;i<s.size();i++){
	    ss+=mp[s[i]];
	}
	int i=0;
	int packets=1;
	string id="000";
	vector<ll>ans;
	helper(ss,i,packets,-1, id,ans);
	cout<<ans[0];
	return 0;
}
