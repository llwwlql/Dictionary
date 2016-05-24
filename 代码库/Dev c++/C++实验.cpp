#include <iostream>
#include <string>
using namespace std;
class Name{
	string name1;
	string ID;
	public:
		Name(const string n,const string i)
		{
			name1=n;
			ID=i;
		}
		friend 
		Name operator+(const string &n,const string &i)
		{
			return Name(name1+n,ID+i);
		}
};
int main()
{
	Name name;
	return 0;
}
