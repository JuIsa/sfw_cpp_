#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;


int main()
{
	string input;
	set<string> ss;
	while(getline(cin,input))
	{
		
		istringstream sinp(input);
		string word;
		while(sinp>>word)
		{
			transform(word.begin(), word.end(),word.begin(), ::tolower);
			
			vector<char> ch(word.begin(), word.end());
			
			string s;
			
			for(char c: ch)
			{
				if(isalpha(c))
				{
					s.push_back(c);
				}else{
					if(s.size()>0){
						ss.insert(s);
						s = "";
					}
				}
			}
			if(s!=""){
			ss.insert(s);
			}
		}		
	}
	for(auto it = ss.begin(); it!=ss.end(); it++)
	{
		cout<< *it << "\n";
	}
	
	return 0;
}