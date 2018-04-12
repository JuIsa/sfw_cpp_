#include <iostream>
#include <set>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	int x;
	multiset<int> ms;
	int count=0;
	while(cin>>x and x!=0){
		
		long long count=0;
		for(int out=0;out<x;out++){
			int n;
			cin>>n;
			
			for(int i=0;i<n;i++){
				int sc; cin>>sc;
				ms.insert(sc);
			}
				auto itb = ms.begin();
				auto ite = ms.end();
				ite--;
				//cout<<*itb<< "  " << *ite<<endl;;
				
				count+=*ite-*itb;
				ms.erase(ite);
				ms.erase(itb);
				
			}
			cout<<count<<endl;
		
			ms.clear();
	}
		
		
		
	
	
	return 0;
}