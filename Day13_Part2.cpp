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
	int a=1000;
	int b=1000;
	char d[] = {'x','y','x','y','x','y','x','y','x','y','y','y'};
	int num[] = {655, 447, 327, 223, 163, 111, 81, 55, 40, 27, 13, 6};
	for(int z=0;z<12;z++){
	    if(d[z]=='x'){
	        for(int i=0;i<n;i++){
        	    if(v[i][0]>num[z] && v[i][0]<a){
        	        int diff=v[i][0]-num[z];
        	        diff*=2;
        	        v[i][0]-=diff;
        	    }
        	}
        	a=num[z];
	    }else{
	        for(int i=0;i<n;i++){
        	    if(v[i][1]>num[z] && v[i][1]<b){
        	        int diff=v[i][1]-num[z];
        	        diff*=2;
        	        v[i][1]-=diff;
        	    }
        	}
        	b=num[z];
	    }
	}
	for(int i=0;i<n;i++){
	    if(v[i][0]<a && v[i][1]<b){
	        result[v[i][0]][v[i][1]]='#';
	    }
	}
	for(int i=0;i<b;i++){
	    for(int j=0;j<a;j++){
	        cout<<result[j][i];
	    }
	    cout<<endl;
	}
	return 0;
}