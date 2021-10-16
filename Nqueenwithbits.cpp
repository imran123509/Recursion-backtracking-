#include<bits/stdc++.h>
using namespace std;
//void display()

bitset<100> col ,ld, rd;
int ans=0;
void Nqueen(int n, int cr){
	if(cr==n){ ans++; return;}
	for(int c=0; c<n; c++){
		if(!col[c] && !ld[cr-c+n-1] && !rd[cr+c]){
			col[c]=ld[cr-c+n-1]=rd[cr+c]=1;
			Nqueen(n, cr+1);
					col[c]=ld[cr-c+n-1]=rd[cr+c]=0;
		}
	}
}
int main(){
int n;
cin>>n;
Nqueen(n,0);
cout<<ans;
    
    return 0;

}
