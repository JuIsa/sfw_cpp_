#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
		int n;
		cin>>n;
		
		
		unordered_map<string, string> mym;
		string v1="";
		string v2="";
		for(int i=0;i<n*2+1;i++){
			string in;
			getline(cin, in);
			istringstream sinp(in);
			string word;
			
			
			if(i%2!=0){
				while(sinp>>word){
					v1+=word;
					v1+=".";
				}
			}else{
				
				while(sinp>>word){
					v2+=word;
					v2+=".";
				}
				mym.insert(pair<string,string>(v1,v2));
				//cout<<v1<<"    "<<v2<<endl;
				v1="";
				v2="";
			  //mym.insert(pair<string,double>(st,a*10+b));
			}
		}
		//cout<<"....line...."<<endl;
		int p;
		cin>>p;
		for(int i=0;i<p+1;i++){
			
			string out;
			getline(cin,out);
			istringstream sinp(out);
			string ss;
			string v3;
			while(sinp>>ss){
				v3+=ss;
				v3+=".";
			}
			
			auto it = mym.find(v3);
			string pr = it->second;
			vector<char> ch(pr.begin(), pr.end());
			for(int c=0;c<ch.size();c++){
				if(c==ch.size() or c==ch.size()-1){
					cout<<endl;
				}else if(ch[c]=='.'){
					cout<<" ";
				}else{
					cout<<ch[c];
				}
				
			}
		}
	
	return 0;
}
