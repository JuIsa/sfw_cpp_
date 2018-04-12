#include <iostream>
#include <set>
#include <string>
#include <sstream>



using namespace std;

int main()
{
	set<string> ss;
	string word;
	while(cin>>word){
		ss.insert(word);
	}
	string a,s;
	for(auto it = ss.begin(); it!=ss.end(); it++){
		word=*it;
		for(int i=1; i<word.length();i++){
			a=word.substr(0,i);
			s=word.substr(i);
			if(ss.find(a)!=ss.end() and ss.find(s)!= ss.end()){
				cout<<word<<endl;
				break;
			}			
		}	
	}
		
	
	
	return 0;
}
		