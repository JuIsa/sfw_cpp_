#include <iostream>
#include <unordered_map>
#include <utility>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	int f,s;
	cin>>f>>s;
	
	unordered_map<string, int> mym;
	for(int i=0; i<f;i++){
		string st;
		int a;
		char ch;
		int b;
		cin>>st;
		cin>>a;
		cin>>ch;
		cin>>b;
		mym.insert(pair<string,double>(st,a*10+b));
	}
	
	for(int i=0; i<s+1;i++){
		string s;
		
		getline(cin, s);
		string word;
		istringstream sinp(s);
		
		int sum =0;
		int compare=0;
		
		while(sinp>>word){
			if(word==">"){
				sinp>>compare;
				
				if(sum>compare*10)
					printf("Guess #%d was correct.\n", i);
				else
					printf("Guess #%d was incorrect.\n", i);
				break;
			}else if(word==">="){
				sinp>>compare;
				
				if(sum>=compare*10)
					printf("Guess #%d was correct.\n", i);
				else
					printf("Guess #%d was incorrect.\n", i);
			}else if(word=="<"){
				sinp>>compare;
				
				if(sum<compare*10)
					printf("Guess #%d was correct.\n", i);
				else
					printf("Guess #%d was incorrect.\n", i);
			}else if(word=="<="){
				sinp>>compare;
				
				if(sum<=compare*10)
					printf("Guess #%d was correct.\n", i);
				else
					printf("Guess #%d was incorrect.\n", i);
			}else if(word=="="){
				sinp>>compare;
				
				if(sum==compare*10)
					printf("Guess #%d was correct.\n", i);
				else
					printf("Guess #%d was incorrect.\n", i);
			}else if(word=="+"){
				int aaa=5;
			}else{
				auto it= mym.find(word);
				sum+=it->second;
				//cout<< sum<<endl;
			}
			
		}
		
		
	}
	
	return 0;
}