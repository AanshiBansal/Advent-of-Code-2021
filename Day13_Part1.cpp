#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	int n=787;
	vector<vector<int>>v(n);
	vector<vector<char>>result(1000,vector<char>(1000,'.'));
	for(int j=0;j<n;j++){
	    string str;
	    cin>>str;
        stringstream ss(str);
        for (int i; ss >> i;) {
            v[j].push_back(i);
            if (ss.peek() == ',')
                ss.ignore();
        }
	}
	for(int i=0;i<n;i++){
	    if(v[i][0]>655){
	        int diff=v[i][0]-655;
	        diff*=2;
	        v[i][0]-=diff;
	    }
	    result[v[i][0]][v[i][1]]='#';
	}
	int count=0;
	for(int i=0;i<1000;i++){
	    for(int j=0;j<1000;j++){
	        if(result[i][j]=='#')
	            count++;
	    }
	}
	cout<<count<<endl;
	return 0;
}
