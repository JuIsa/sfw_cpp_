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
	void print(const Board& b);
	
	int positionOf(int& i, int& j) const{
		return v[i][j];
	}
	
	bool operator < (const Board& a) const{
		//for(auto it
		for(int i=0;i <sz;i++){
			for(int j=0; j<sz; j++){
				int t = a.v[i][j];
				int loc = v[i][j]; 
					if(loc>t or loc<t){
						return true;
					}
			}
		}
		return false;
	}
	
	Board& operator= (const Board& b){
		for(int i=0;i<b.v.size();i++){
			for(int j=0; j<b.v[0].size(); j++){
				v[i][j]=b.v[i][j];
			}
		}
	}
	Board rotateB(Board& b){
		Board temp = b;
		for(int i=0; i<sz; i++){
			for(int j=0; j<sz;j++){
				temp.v[i][j] = b.v[sz-j-1][i];
			}
		}
		
		return temp;
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
void print(const Board& b){
	for(int i=0; i<b.size();i++){
		for(int u=0; u<b.size();u++){
			cout<<b.positionOf(i, u)<< " ";
		}
		cout<<endl;
	}
}
void rotated90(set<Board>& sb, Board b, int& count){
	if(count<3){
		Board t = b.rotateB(b);
		//print(t);
		//cout<<endl;
		count++;
		sb.insert(t);
		rotated90(sb,t, count);
	}
		count=0;	
}


int main()
{
	int x;
	cin>>x;
	set<Board> sb;
	Board b(x);
	int count=0;
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
		rotated90(sb,b,count);
	}	
	for(auto  it = sb.begin(); it!=sb.end(); ++it){
		print(*it);
		cout<<endl;
	}
	return 0;
}