#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int stimulate(int i,int j,int xmin,int xmax,int ymin,int ymax){
    int corrX=0;
    int corrY=0;
    while(corrX<xmax && corrY>ymin){
        corrX+=i;
        corrY+=j;
        if(corrX>=xmin && corrX<=xmax && corrY>=ymin && corrY<=ymax){
            return true;
        }
        i=max(0,i-1);
        j--;
    }
    return false;
}
int main() {
	int xmin=88;
	int xmax=125;
	int ymin=-157;
	int ymax=-103;
	int ans=0;
	for(int i=0;i<=xmax;i++){
	    for(int j=ymin;j<=250;j++){
	        if(stimulate(i,j,xmin,xmax,ymin,ymax))
	            ans++;
	    }
	}
	cout<<ans;
	return 0;
}
