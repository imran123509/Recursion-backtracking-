#include<bits/stdc++.h>
using namespace std;
bool search(vector<int> &arr, int target, int idx){
	if(idx==arr.size()) return false;
	return (arr[idx]==target) ||search(arr,target, idx+1);
}


// find the first index
int firstidx(vector<int>&arr, int target, int idx){
	if(idx==arr.size()) return -1;
	if(arr[idx]==target) return idx;
	else{
	return firstidx(arr, target, idx+1);
	}
}


//find the last index of the array
int lastidx(vector<int>&arr, int target, int idx){
	if(idx==-1) return -1;
	if(arr[idx]==target) return idx;
	else return lastidx(arr, target,idx-1);
}
int main(){
vector<int> arr={1,2,3,4,4};
int target=4;
//cout<<search(arr, target, 0);
cout<<firstidx(arr, target, 0);
cout<<lastidx(arr, target, arr.size()-1);
    return 0;

}
