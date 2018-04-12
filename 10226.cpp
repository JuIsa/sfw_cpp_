#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <utility>
#include <iomanip>

using namespace std;

int main()
{
	int x;
	string line;
	cin>>x;
	x++;
	
	getline(cin,line);
	map<string,int> myMap;
	while(x--){
		string input;
		double count=0;
		int bs=0;
		pair<map<string,int>::iterator, bool> ret;
		while(getline(cin, input) and input!=""){
			ret = myMap.insert(pair<string,int>(input,1));
			if(!ret.second){
				++myMap[input];
			}
			count++;	
		}
		count = 100/count;
		for(auto it = myMap.begin(); it!=myMap.end(); it++){
			cout<<fixed;
			cout<<it->first<<" "<<setprecision(4)<<it->second*count<<endl;
		}
		
		printf("\n");
			myMap.clear();
		if(x>0){
			
		}	
	}
	return 0;
}
