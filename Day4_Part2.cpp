#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int n=100;
    string str;
    cin>>str;
	vector<int> v;
    stringstream ss(str);
    for (int i; ss >> i;) {
        v.push_back(i);
        if (ss.peek() == ',')
            ss.ignore();
    }
    vector<vector<vector<int> > >arr(n);
    for(int i=0;i<n;i++){
        vector<vector<int> >temp(5, vector<int>(5));
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++)
            {
                string h;
                cin>>h;
                temp[j][k]=stoi(h);
            }
        }
        arr[i]=temp;
    }
    ll ans=0;
    int count=n;
    vector<bool>win(100,false);
    for(int i=0;i<v.size();i++){
        for(int j=0;j<n;j++){
            if(win[j]==false)
                for(int k=0;k<5;k++){
                    for(int l=0;l<5;l++){
                        if(arr[j][k][l]==v[i]){
                            arr[j][k][l]=-1;
                            bool flag1=true;
                            bool flag2=true;
                            for(int x=0;x<5;x++){
                                if(arr[j][x][l]!=-1){
                                    flag1=false;
                                    break;
                                }
                            }
                            for(int x=0;x<5;x++){
                                if(arr[j][k][x]!=-1){
                                    flag2=false;
                                    break;
                                }
                            }
                            if(flag1 || flag2){
                                count--;
                                win[j]=true;
                                if(count==0){
                                    for(int x=0;x<5;x++){
                                        for(int y=0;y<5;y++){
                                            if(arr[j][x][y]!=-1){
                                                ans+=arr[j][x][y];
                                            }
                                        }
                                    }
                                    cout<<ans<<" "<<v[i]<<" "<<ans*v[i];
                                    return 0;
                                }
                            }
                        }
                    }
                }
        }
    }
	return 0;
}
