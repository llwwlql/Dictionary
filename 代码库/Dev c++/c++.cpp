#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Name{
	string name1;
	char *ID;
	public:
		Name(const string &n="Luqilu",const char *i="20142203713")
		{
			name1=n;
			ID=new char[strlen(i)+1];
			strcpy(ID,i);
		}
		
		
		friend
		Name operator+(const Name &n1,const Name &n2);
		void display()
		{
			cout<<name1<<"	"<<ID<<endl;
		}
		~Name()
		{
			delete []ID;
		}
};
Name operator+(const Name &n1,const Name &n2)
{
	Name temp;
	temp.name1=n1.name1+n2.name1;
	temp.ID=new char[strlen(n1.ID)+strlen(n2.ID)+1];
	strcpy(temp.ID,n1.ID);
	strcat(temp.ID,n2.ID);
	delete []n1.ID;
	n1.ID=new char[strlen(n1.ID)+strlen(n2.ID)+1];
	return temp;
}
int main()
{
	Name n1("åÖÆäÂ³","20142203713"),n2("²ÜºãÑô","20142203612");
	n1.display();
	n2.display();
	n1=n1+n2;
	n1.display();
	return 0;
}
