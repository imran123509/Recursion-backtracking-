#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
void subsequences(int ind, vector<int> &a){
	int n=a.size();
	if(ind>=n){
		for(int ele : ans) cout<<ele<<" ";
		cout<<endl;
		return;
	}
	ans.push_back(a[ind]);
	subsequences(ind+1, a);
	ans.pop_back();
	subsequences(ind+1, a);
}
int main(){

    vector<int> vec={1,2,3};
	subsequences(0, vec);
    return 0;

}
