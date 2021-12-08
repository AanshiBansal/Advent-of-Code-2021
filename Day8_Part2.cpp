#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int countPairs(string s1, int n1, string s2, int n2)
{
    int freq1[26] = { 0 };
    int freq2[26] = { 0 };
    int count = 0;
    for (int i = 0; i < n1; i++)
        freq1[s1[i] - 'a']++;
    for (int i = 0; i < n2; i++)
        freq2[s2[i] - 'a']++;
    for (int i = 0; i < 26; i++)
        count += (min(freq1[i], freq2[i]));
    return count;
}
int main() {
    int n=200;
    vector<vector<string> >in(n,vector<string>(10));
    vector<vector<string> >out(n,vector<string>(4));
    string help;
    for(int i=0;i<n;i++){
        for(int j=0;j<10;j++){
            cin>>help;
            sort(help.begin(),help.end());
            in[i][j]=help;
        }
        cin>>help;
        for(int j=0;j<4;j++){
            cin>>help;
            sort(help.begin(),help.end());
            out[i][j]=help;
        }
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        int counter=0;
        vector<string>mp(10,"");
        while(counter<10){
            for(int j=0;j<10;j++){
                if(counter==10)
					break;
                if(mp[1]=="" && in[i][j].size()==2){
                    mp[1]=in[i][j];
                    counter++;
                }
                if(mp[7]=="" && in[i][j].size()==3){
                    mp[7]=in[i][j];
                    counter++;
                }
                if(mp[4]=="" && in[i][j].size()==4){
                    mp[4]=in[i][j];
                    counter++;
                }
                if(mp[8]=="" && in[i][j].size()==7){
                    mp[8]=in[i][j];
                    counter++;
                }
                if(mp[8]!="" && mp[1]!="" && mp[4]!="" && in[i][j].size()==6){
                    char missing='m';
                    for(int k=0;k<6;k++){
                        if(mp[8][k]!=in[i][j][k]){
                            missing=mp[8][k];
                            break;
                        }
                    }
                    if(missing=='m'){
                        missing=mp[8][6];
                    }
                    if(missing == mp[1][0] || missing==mp[1][1]){
                        if(mp[6]==""){
                            mp[6]=in[i][j];
                            counter++;
                        }
                    }else{
                        if(missing == mp[4][0] || missing==mp[4][1] || missing==mp[4][2] || missing==mp[4][3]){
                            if(mp[0]==""){
                                mp[0]=in[i][j];
                                counter++;
                            }
                        }else{
                            if(mp[9]==""){
                                mp[9]=in[i][j];
                                counter++;
                            }
                        }
                    }
                }
                if( mp[1]!="" &&  in[i][j].size()==5){
                    int count=countPairs(mp[1],2,in[i][j],5);
                    if(count==2){
                        if(mp[3]==""){
                            mp[3]=in[i][j];
                            counter++;
                        }
                    }
                }
                if( mp[6]!="" &&  in[i][j].size()==5){
                    int count=countPairs(mp[6],6,in[i][j],5);
                    if(count==5){
                        if(mp[5]==""){
                            mp[5]=in[i][j];
                            counter++;
                        }
                       
                    }
                }
                if( mp[9]!="" &&  in[i][j].size()==5){
                    int count=countPairs(mp[9],6,in[i][j],5);
                    if(count==4){
                        if(mp[2]==""){
                            mp[2]=in[i][j];
                            counter++;
                        }
                       
                    }
                }
            }
        }
        ll curr=0;
        for(int j=0;j<4;j++){
            curr*=10;
            int k=0;
            for(;k<10;k++){
                if(out[i][j]==mp[k]){
                    break;
                }
            }
            curr+=k;
        }
        ans+=curr;
    }
    cout<<ans;
	return 0;
}