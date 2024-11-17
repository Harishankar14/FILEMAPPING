#include <bits/stdc++.h>
using namespace std;
/*

 Deadlock condition 
  resouce =process8(need-1)+1;

  
*/
int min(int process,int need){
	int resource=process*(need-1)+1;
	return resource;
}

int main(){
	cout<<min(5,3);
}