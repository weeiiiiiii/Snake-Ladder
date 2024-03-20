#include<iostream>
#include<cstring>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
template<typename T>
#define pb push_back
class graph{
	//unordered_map<string,list<string> >h;
	unordered_map<T,list<T> >h;
	public:
		void addedge(T u,T v,bool bidir=false){
			h[u].pb(v);
			if(bidir==true){
				h[v].pb(u);
			}
		}
		void print(){
			for(auto node:h){
				cout<<node.first<<" : ";
				for(auto x:node.second){
					cout<<x<<" ";
				}
				cout<<endl;
			}
			cout<<endl;
		}
		int sssp(T start,T des){
			queue<T> q;
			unordered_map<T, bool> visited;
			q.push(start);
			visited[start]=true;
			unordered_map<T, int> distance;
			unordered_map<T, T> parent;
			distance[start]=0;
			parent[start]=start; 
			while(!q.empty()){
				T node=q.front();
				q.pop();
				for(auto x:h[node]){
					if(!visited[x]){
						q.push(x);
						visited[x]=true;
						distance[x]=distance[node]+1;
						parent[x]=node;
					}
				}
			}
			T temp=des;
			while(temp!=parent[temp]){
				cout<<temp<<"<--";
				temp=parent[temp];
			}
			cout<<temp<<endl;
			return distance[des];
		}
};
int main(){
	graph<int> g;
	int board[50]={0};
	board[2]=13;
	board[5]=2;
	board[9]=18;
	board[18]=11;
	board[17]=-13;
	board[20]=-14;
	board[24]=-8;
	board[25]=-10;
	board[32]=-2;
	board[34]=-22;
	for(int u=0;u<36;u++){
		for(int dice=1;dice<=6;dice++){
			int v=u+dice+board[u+dice];
			g.addedge(u,v);
		}
	}
	cout<<g.sssp(0,36);
}
