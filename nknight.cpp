#include<bits/stdc++.h>
using namespace std;
void display(vector<vector<bool>> &grid, int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(grid[i][j]){
				cout<<"k ";
			}else{
				cout<<". ";
			}
		}
		cout<<endl;
	}
}
bool issafe(int r, int c, vector<vector<bool>>&grid, int n){
	if(r-2>=0 && c-1>=0 && grid[r-2][c-1]) return false;
	if(r-1>=0 && c-2>=0 && grid[r-1][c-2]) return false;
	if(r-2>=0 && c+1<n && grid[r-2][c+1]) return false;
	if(r-1>=0 && c+2<n && grid[r-1][c+2]) return false;
	return true;
}
int ans=0;
void nKnight(int n, vector<vector<bool>>&grid, int cr, int cc, int cnt){
	if(cnt==n){
		ans++;
		display(grid,n);
		cout<<endl<<endl;
		return;
	}
	for(int i=cr; i<n; i++){
		for(int j=(i==cr)?cc :0; j<n; j++){
			if(issafe(i,j,grid,n)){
				grid[i][j]=true;
				nKnight(n, grid, i,j+1, cnt+1);
				grid[i][j]=false;
			}
		}
	}
}
int main(){
	int n;
	cin>>n;
	vector<vector<bool>>grid(n, vector<bool>(n, false));
	nKnight(n, grid, 0, 0, 0);
	cout<<ans<<endl;
}