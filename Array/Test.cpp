#include <iostream>

using namespace std;
#include<iostream>
#include<vector>

#define NMAX 55
static int rowNbr[] = {-1, 1, 0, 0}; 
static int colNbr[] = {0, 0, 1, -1};
int main(){
	int n;
	cin>>n;
	char cake[5][6];
	for(int i=0;i<n;i++){
		scanf("%s",cake[i]);
		cout<<"\""<<i<<"\""<<endl;
		cout<<"\""<<cake[i]<<"\""<<endl;
		cout<<"\""<<cake[i][3]<<"\""<<endl;
	}



}