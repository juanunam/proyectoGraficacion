#include <iostream>
#include <map>
using namespace std;
map<string,int> mapa;

int main(){
	string hola="hola";
	mapa[hola]=2;
	cout<<mapa[hola]<<endl;
	hola="nohola";
	cout<<mapa[hola]<<endl;
}
