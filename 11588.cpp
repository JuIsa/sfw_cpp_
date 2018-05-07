#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main(){
	int test;cin>>test;
	
	for(int i=0;i<test;i++){
		map<char, int> freq;
		int r,c,maxV,minV;
		
		cin>>r>>c>>maxV>>minV;
		
		for(int row=0;row<r;row++){
			for(int col=0;col<c;col++){
				char ch;
				cin>>ch;
				++freq[ch];
			}
		}
		
		int max=0;
		for(auto it=freq.begin();it!=freq.end();it++){
			if(it->second>max)
				max=it->second;  //нахожу самую частую букву
		}
		int sum=0;
		int altSum=0;
		for(auto it=freq.begin();it!=freq.end();it++){
			if(it->second==max){
				sum+=max*maxV; //если равен самой частой то * на первое число из инпута
			}
			else if(it->second<max){
				altSum+=it->second;//если меньще самой частой то * на второе число из инпута
			}
		}
		//sum+=(.size() - minus)*minV;
		
		printf("Case %d: %d\n", i+1,sum+altSum*minV);
		
	}
	return 0;
}