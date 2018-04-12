#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

int main()
{
	string line;
	while(getline(cin,line))
	{
		
		vector<char> ch(line.begin(), line.end());
		
		list<char> result;
		bool start = false;
		bool end = false;
		list<char>::iterator it;
		for(auto c: ch)
		{
			if(c == '[')
			{
				start = true;
				it=result.begin();
				continue;
			}
			if(c == ']')
			{
				start = false;
				it=result.end();
				continue;
				
			}
			if(start)
			{
				result.insert(it,c);
				//it++;
				continue;
			}
			result.push_back(c);
			
		}
		for(auto e: result)
		{
			cout << e;
		}
		cout<<endl;
		
	}
	
	
	return 0;
}