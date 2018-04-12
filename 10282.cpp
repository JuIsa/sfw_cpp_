#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
	string input;
	unordered_map<string, string> mm;
	vector<string> ay;
	bool ok = false;
	while(getline(cin, input)){
		string word;
		istringstream sinp(input);
		if(input.size()==0){
			ok=true;
		}
		
		if(ok){
			while(sinp>>word){
				ay.push_back(word);
			}
		}else{
			while(sinp>>word){
				string f=word;
				string s; sinp>>s;
				//cout<<s<<" "<<f;
				mm.insert(pair<string,string>(s,f));
				
			}
		}
	}
	
	for(int i=0;i<ay.size();i++){
		auto it = mm.find(ay[i]);
		if(it==mm.end()){
			cout<<"eh"<<endl;
		}else{
			cout<<it->second<<endl;
		}
	}
	
	
	return 0;
}