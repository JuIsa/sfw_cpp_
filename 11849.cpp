#include <iostream>
#include <unordered_set>
#include <utility>

using namespace std;

int main()
{
	pair<unordered_set<int>::iterator,bool> check;
	
	int x,y;
	
	while(true){
		cin>>x;
		cin>>y;
		if(x==0 and y==0)break;
		int count=0;
		//cout<<count<<endl;
		unordered_set<int> ints;
		int xy=x+y;
		//cout<<count<<endl;
		for(int i=0; i<xy;i++){
			int a;
			cin>>a;
			check=ints.insert(a);
			if(!check.second){
				count++;
			}
			
		}
	/*
		for(int i=0; i<5;i++){
			check=ints.insert(i);
			if(check.second)
			cout<<*check.first<<endl;
		}
		
		*/
		cout<<count<<endl;
		
	}
	return 0;
}