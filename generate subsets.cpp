#include<bits/stdc++.h>
using namespace std;
// generate subset
vector<vector<int>> allsubsets;
void generate(vector<int> &subset, int i, vector<int> &nums){
	cout<<nums[i]<<endl;

	if(i==nums.size()){
		allsubsets.push_back(subset);
		return;
	}
	generate(subset, i+1, nums);
	subset.push_back(nums[i]);
	generate(subset, i+1, nums);
	subset.pop_back();
}

int main(){
	int n;
	cin>>n;
	vector<int>a(n);
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	vector<int> empty;
	generate(empty, 0, a);
	for(auto &subset : allsubsets){
		for(auto &ele : subset){
			cout<<ele<<" ";
		}
		cout<<endl;
	}
