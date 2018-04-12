#include <iostream>
#include <unordered_map>
#include <utility>

using namespace std;

int main()
{
	int q;
	while(cin>>q){
		while(q--){
			int n;
			cin>>n;
			int max=0;
			int count=0;
			unordered_map<int, int> mym;
			pair<unordered_map<int, int>::iterator, bool> ret;	
			for(int i=0; i<n;i++){
				int x;
				cin>>x;
				
				ret = mym.insert(pair<int,int>(x,1));
				if(ret.second){
					count++;
					if(max<count){
						max=count;
					}
				}if(!ret.second){
					auto found = mym.find(x);
					++found;
					unordered_map<int,int> temp;
					while(found!=mym.end()){
						temp.insert(pair<int,int>(found->first, found->second));
						++found;
						count++;
					}
					
					mym.clear();
					mym=temp;
					//mym.insert(pair<int,int>(x,1));
				}
				
			}
			mym.clear();
			count--;
			cout<<count<<endl;
		}
	}
	return 0;
}