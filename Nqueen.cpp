#include<bits/stdc++.h>
using namespace std;
//Nqueen problem

bool issafe(vector<vector<bool>> &grid, int row,int col, int n){
	//check column
	for(int i=row-1; i>=0; i--){
		if(grid[i][col]) return false;
	}
	// left upper diagnol
	for(int i=row-1, j=col-1; i>=0 && j>=0; i--,j--){
		if(grid[i][j]) return false;
	}
	// right upper diagnol
	for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++){
		if(grid[i][j]) return false;
	}
	return true;
}

void display(vector<vector<bool>>&grid, int n){
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			if(grid[i][j]){
				cout<<"Q ";
			}else{
				cout<<". ";
			}
		}
		cout<<endl;
	}
}
int countw=0;
void countNqueen(vector<vector<bool>> &grid, int curr_row, int n){
	if(curr_row==n){
		
	
		countw++;
		display(grid,n);
		cout<<endl<<endl;
		return;
	}
	for(int i=0; i<n; i++){
		// i will go each spot column
		if(issafe(grid,curr_row, i, n)){
			grid[curr_row][i]=true;
			countNqueen(grid, curr_row+1, n);
			grid[curr_row][i]=false;
		}
		
	}
}
int main(){
	int n;
	cin>>n;
	vector<vector<bool>>grid(n, vector<bool>(n,0));
	countNqueen(grid, 0, n);
	cout<<countw<<endl;
}