#include <iostream>
//#include <unordered_set>
#include <utility>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
	pair<unordered_map<int,int>::iterator, bool> check;
	
	int x;
	unordered_map<int,int> myM;
	//unordered_set<int> ms;
	vector<int> v;
	while(cin>>x){
		check=myM.insert(pair<int,int>(x,1));
		if(!check.second){
			++myM[x];
		}
		if(check.second){
			v.push_back(x);
		}
		
	}
	
	
	for(auto it: v){
		auto i = myM.find(it); 
		//cout<<it<<endl;
		cout<<i->first<<" "<< i->second<<endl;
	}
	return 0;
}