#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int helper(string &s, int i, ll &ans, int packets, int end){
    if(end==-1){
        if(packets==0){
            return i;
        }
        ans+=stoi(s.substr(i,3), 0, 2);
        cout<<"New Packet starting at "<<i<<endl;
        i+=3;
        string type=s.substr(i,3);
        i+=3;
        if(type=="100"){
            while(s[i]=='1'){
                i+=5;
            }
            i+=5;
            cout<<"Literal Packet ending at "<<i<<endl;
            return helper(s, i, ans, packets-1, -1);
        }else{
            char lengthType=s[i];
            i++;
            if(lengthType=='0'){
                string size=s.substr(i,15);
                int sizeNum=stoi(size, 0, 2);
                cout<<"Operator Packet with subpackets of size "<<sizeNum<<endl;
                i+=15;
                int end=helper(s, i, ans, -1, i+sizeNum);
                return helper(s,end,ans,packets-1,-1);
            }else{
                string count=s.substr(i,11);
                int countNum=stoi(count, 0, 2);
                i+=11;
                cout<<"Operator Packet with subpackets number "<<countNum<<endl;
                int end=helper(s, i, ans, countNum, -1);
                return helper(s,end,ans,packets-1,-1);
            }
        }
        
    }else{
        if(end==i)
            return end;
        ans+=stoi(s.substr(i,3), 0, 2);
        cout<<"New Packet starting at "<<i<<endl;
        i+=3;
        string type=s.substr(i,3);
        i+=3;
        if(type=="100"){
            while(s[i]=='1'){
                i+=5;
            }
            i+=5;
            cout<<"Literal Packet ending at "<<i<<endl;
            return helper(s,i,ans,-1,end);
        }else{
            char lengthType=s[i];
            i++;
            if(lengthType=='0'){
                string size=s.substr(i,15);
                int sizeNum=stoi(size, 0, 2);
                i+=15;
                cout<<"Operator Packet with subpackets of size "<<sizeNum<<endl;
                helper(s, i, ans, -1, i+sizeNum);
                return helper(s,i+sizeNum,ans,-1,end);
            }else{
                string count=s.substr(i,11);
                int countNum=stoi(count, 0, 2);
                i+=11;
                cout<<"Operator Packet with subpackets number "<<countNum<<endl;
                int start=helper(s, i, ans, countNum, -1);
                return helper(s,start,ans,-1,end);
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
	ll ans=0;
	int i=0;
	int packets=1;
	helper(ss,i,ans,packets,-1);
	cout<<ans;
	return 0;
}
