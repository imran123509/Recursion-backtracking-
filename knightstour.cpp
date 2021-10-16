#include<bits/stdc++.h>
using namespace std;
//knights tour problem
//int counth;
bool issafe(vector<vector<int>> &grid, int n, int i, int j, vector<vector<bool>>&visited){
	return i>=0 && j>=0 && i<n && j<n && visited[i][j]==false;
}
void display(vector<vector<int>>&grid,int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}
}
void knightstour(vector<vector<int>> &grid, int n,int i, int j, int counth, vector<vector<bool>> &visited){
	if(counth==n*n-1){
		grid[i][j]=counth;
		display(grid, n);
		cout<<endl<<endl;
		return;
	}
	if(counth>n*n){
		return;
	}
	int xdr[8]={-2,-2,-1,-1,2,2,1,1};
	int ydr[8]={1,-1,2,-2,1,-1,2,-2};
	visited[i][j]=true;
	grid[i][j]=counth;
	for(int k=0; k<8; k++){
		if(issafe(grid, n, i+xdr[k], j+ydr[k], visited)){
			knightstour(grid, n, i+xdr[k], j+ydr[k], counth+1, visited);
			
		}
	}
	grid[i][j]=-1;
	visited[i][j]=false;
}
int main(){
	int n;
	cin>>n;
	vector<vector<int>>grid(n, vector<int>(n,0));
		vector<vector<bool>>visited(n, vector<bool>(n,false));
	
	knightstour(grid,n,0, 0, 0, visited);
}