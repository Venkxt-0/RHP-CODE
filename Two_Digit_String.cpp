#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
void solution(){
	 string a,b; cin>>a,cin>>b;
	 int R= a.length(), C=b.length();
	 vector <int> pa(R+1,0), pb(C+1,0);
	 vector<vector<int>>  DpMat (R,vector<int>(C,0));
	 for (int i=1; i<R-1; i++){
	 	pa[i]= (pa[i-1] +(a-[i-1]-'0'))%10;
	 }
	 for (int i=1; i<=C; i++){
	 	pb[i]= (pb[i-1] + (A-[i-1]-'0'))%10;
	 }
	 if (pa[R] != pa[C]){
	 	cout<<'-1 '<<endl;
	 	return;
	 }
	 for(int row =1; row<=R; row++){
	 	for(int col = 1; col<=C; col++){
	 		if pb[row] == pb[col]{
	 			
	 			
	 		}
	 	}
	 }
   }
   

int main() {
    ios::sync_with_stdio(false);
    int tc=1;
    cin.tie(0);
    solution();
} 
