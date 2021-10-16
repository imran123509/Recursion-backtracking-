#include<bits/stdc++.h>
using namespace std;

int totalpaths=0;

bool issafe(int i, int j, int n, vector<vector<bool>>&visited){
	return i>=0 && j>=0 && i<n && j<n && visited[i][j]==false;
}
void helper(int i, int j, int n, vector<vector<int>> &grid,vector<vector<bool>>&visited){
	if(i==n-1 && j==n-1){
		totalpaths++;
		return;
	}
	if(not issafe(i,j,n,visited)){
		//pruning
	
		return;
	}
   visited[i][j]=true;
   if(i+1<n && grid[i+1][j]==0){ //down
   	helper(i+1, j, n, grid, visited);
   }
	if(i-1>=0 && grid[i-1][j]==0){ // up
   	helper(i-1, j, n, grid, visited);
   }
   if(j+1<n && grid[i][j+1]==0){ //right
   	helper(i, j+1, n, grid, visited);
   }
   if(j-1>=0&& grid[i][j-1]==0){ //left
   	helper(i, j-1, n, grid, visited);
   }
   visited[i][j]=false;
   return;
}
int mazepath(vector<vector<int>>&grid){
	int n=grid.size();

	vector<vector<bool>> visited(n, vector<bool>(n, false));
	helper(0,0,n,grid, visited);
	return totalpaths;
}
int main(){
	int n;
	cin>>n;
	vector<vector<int>> grid(n, vector<int>(n, 0));
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>grid[i][j];
		}
	}
	cout<<mazepath(grid)<<endl;
}