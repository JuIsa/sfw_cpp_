#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
	int x;
	cin>>x;
	for(int ii=0;ii<x;ii++){
		int n;
		cin>>n;
		unordered_map<string, int> mm;
		for(int p=0;p<n;p++){
			string word;cin>>word;
			int time;cin>>time;
			mm.insert(pair<string, int>(word, time));
			//cout<<"check"<<endl;
		}
		int d;cin>>d;
		string subj;cin>>subj;
		auto it = mm.find(subj);
		//cout<<"check"<<endl;
		if(it==mm.end()){
			printf("Case %d: Do your own homework!\n", ii+1);
		}else{
			//cout<<"lol"<<endl;
			if(d >= (it->second)){
				printf("Case %d: Yesss\n", ii+1);
			}else if(d+5>=(it->second)){
				printf("Case %d: Late\n", ii+1);
			}else{
				printf("Case %d: Do your own homework!\n", ii+1);
			}
			
		}
		
		
		
	}
	return 0;
}