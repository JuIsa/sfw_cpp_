#include <iostream>

#include <map>
#include <set>
#include <string>
#include <utility>

using namespace std;

int main()
{
	int x;
	while(cin>>x and x!=0){
		int count=1;
		map<string,int> mm;
		int max=0;
		for(int i=0;i<x;i++){
			pair<map<string,int>::iterator,bool> ret;
			
			set<int> a;
			
			for(int i=0; i<5; i++){
				int n;
				cin>>n;
				a.insert(n);
			}
			string s="";
			for(auto it=a.begin(); it!=a.end(); it++){
				s+=to_string(*it);
			}
			//cout<<s<<endl;			
			
			ret = mm.insert(pair<string,int>(s,1));
			if(!ret.second){
				++mm[s];
			}
			
		}
		int maxn=0;
		for(auto it = mm.begin(); it!=mm.end(); it++){
			if(maxn<(it->second)){
				maxn=it->second;
				max=0;
			}if(maxn==it->second){
				max+=maxn;
			}
		}
		cout<<max<<endl;
		
	}
	
	return 0;
}