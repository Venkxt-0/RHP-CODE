#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <set> 
using namespace std;
void solution() {
	int R; cin>>R;
	map <int, vector<pair<int,int>>> g;
	priority_queue<pair <int, int>, vector<pair<int,int>>, greater <pair<int,int>>> pq;
	set<int> vis;
	while(R--){
		int ori,dest,dis;
		cin>>ori>>dest>>dis;
		g[ori].push_back(make_pair(dest,dis));
		g[dest].push_back(make_pair(ori,dis));
		
	}
	int src, target;
	cin >> src >> target;
	pq.push(make_pair(0, src));
	while(!pq.empty()){
		auto [CurrDist , CurrCity]= pq.top(); pq.pop();
		if (!vis.count(CurrCity)){
			if (CurrCity == target){
				cout<<CurrDist<<endl;return;
			}
		vis.insert(CurrCity);
		for(auto [ocity, odist] : g[CurrCity]){
			if (!vis.count(ocity)){
				pq.push(make_pair(odist+CurrDist, ocity));
			}
		}
	}		
    }
    cout<<"City "<<target<<" cannot be reached";
    }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
