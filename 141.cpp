#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Board{
	private:
	int sz;
	vector<vector<int>> v;
	
	
	public:
	Board()
	:sz(2),v()
	{
		for(int i=0; i<sz; i++){
			vector<int> vin;
			for(int i2=0;i2<sz;i2++){
				vin.push_back(0);
			}
			v.push_back(vin);
		}
	}
	Board(const int& x)
	:sz(x),v()
	{
		vector<vector<int>> vnew;
		for(int i=0; i<x;i++){
			vector<int> vnewin;
			for(int i=0; i<x;i++){
				vnewin.push_back(0);
			}
			vnew.push_back(vnewin);
		}
		v.clear();
		v=vnew;
	}
	int size()const{
		return sz;
	}
	
	//Board rotated90(Board b);
	
	void print(const Board& b);
	int positionOf(int& i, int& j) const{
		return v[i][j];
	}
	
	bool operator < (const Board& a) const{
		for(int i=0;i <v.size();i++){
			for(int j=0; j<v[i].size(); j++){
				int t = a.v[i][j];
				int loc = v[i][j]; 
				//cout<< t<<" "<<loc<<endl;
					if(loc!=t)
						return true;
					
			}
		}
		return false;
	}
	
	 void put_1(Board& b, const int ox,const int oy);
	 void erase_1(Board& b, const int ox, const int oy);
	
	 void change_to_1(const int& x,const int& y){
		v[x-1][y-1]=1;
	}
	 void change_to_0(const int& x,const int& y){
		v[x-1][y-1]=0;
	}
	
};

 void put_1(Board& b, const int ox, const int oy){
	b.change_to_1(ox, oy);
}
 void erase_1(Board& b, const int ox, const int oy){
	b.change_to_0(ox, oy);
}
Board rotated90(Board& b){
		Board t=b;
		
		return t;
		
}
void print(const Board& b){
	for(int i=0; i<b.size();i++){
		for(int u=0; u<b.size();u++){
			cout<<b.positionOf(i, u)<< " ";
		}
		cout<<endl;
	}
}

int main()
{
	int x;
	cin>>x;
	set<Board> sb;
	Board b(x);
	for(int i=0;i<x*2;i++){
		int oy,ox;
		char ch;
		cin>>ox>>oy>>ch;
		if(ch=='+'){
			put_1(b, ox, oy);
		}else if(ch=='-'){
			erase_1(b,ox,oy);
		}
		sb.insert(b);
		Board rot90 = rotated90(b);
		//Board rot180 = rotated180(b);
		//Board rot270 = rotated270(b);
		
	}
	
	//Board a(x);
	//cout<< a<b<<endl	
	for(auto  it = sb.begin(); it!=sb.end(); ++it){
		print(*it);
		cout<<endl;
	}
	//b.init(b);
	return 0;
}