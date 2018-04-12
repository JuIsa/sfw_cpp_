#include <iostream>
#include <unordered_map>
#include <utility>
using namespace std;

int main()
{
	int f,s;
	cin>>f>>s;
	
	unordered_map<string, double> mym;
	for(int i=0; i<f;i++){
		string st;
		double d;
		cin>>st;
		cin>>d;
		mym.insert(pair<string,double>(st,d));
	}
	
	for(int i=0; i<s;i++){
		string s;
		vector<string> v;
		getline(cin, s);
		string word;
		istringstream sinp(s);
		bool plus = false;
		int point =0;
		double res =0;
		while(sinp>>word){
			if(plus){
				res=v[point]+v[point-1];
				plus=false;
			}
			if(word=="+"){
				plus=true;
			}
			if(word=="<="){
				
			}
			v.push_back(word);
			point++;
			
		}
		
		
	}
	
	return 0;
}