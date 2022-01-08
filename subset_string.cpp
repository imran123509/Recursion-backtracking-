#include<bits/stdc++.h>
using namespace std;
void subset(string str, string st){
	if(st.empty()){
		cout<<str<<endl;
		return;
	}
	char ch=st[0];
	subset(str+ch, st.substr(1));
	subset(str, st.substr(1));
}
int main(){

    string s="acb";
	subset("", s);
    return 0;

}
