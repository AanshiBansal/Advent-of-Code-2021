#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int stimulate(int i,int j,int xmin,int xmax,int ymin,int ymax){
    int corrX=0;
    int corrY=0;
    int curr=0;
    while(corrX<xmax && corrY>ymin){
        corrX+=i;
        corrY+=j;
        curr=max(curr,corrY);
        if(corrX>=xmin && corrX<=xmax && corrY>=ymin && corrY<=ymax){
            return curr;
        }
        i=max(0,i-1);
        j--;
    }
    return 0;
}
int main() {
	int xmin=88;
	int xmax=125;
	int ymin=-157;
	int ymax=-103;
	int ans=0;
	for(int i=0;i<=xmax;i++){
	    for(int j=0;j<250;j++){
	        ans=max(ans,stimulate(i,j,xmin,xmax,ymin,ymax));
	    }
	}
	cout<<ans;
	return 0;
}
