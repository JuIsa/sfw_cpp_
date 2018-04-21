#include <iostream>
#include <vector>

using namespace std;

class Board{
	private:
	int sz;
	vector<vector<int>> v;
	
	public:
	Board()
	:sz(2)
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
	:sz(x)
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
	
	const void put_1(Board& b, int ox, int oy);
	const void erase_1(Board& b, int ox, int oy);
	
	void change_to_1(int& x, int& y){
		v[x-1][y-1]=1;
	}
	void change_to_0(int& x, int& y){
		v[x-1][y-1]=0;
	}
	
};

const void put_1(Board& b, int ox, int oy){
	b.change_to_1(ox, oy);
}
const void erase_1(Board& b, int ox, int oy){
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

int main()
{
	int x;
	cin>>x;
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
	}
	print(b);
	//b.init(b);
	return 0;
}