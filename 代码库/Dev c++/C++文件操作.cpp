#include <fstream>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output");

int main()
{
	int a,b;
	while (fin>>a>>b)
		fout<<a+b<<endl;
	return 0;
}
