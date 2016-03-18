#include <iostream>
#include "MessageAndFolder.h"
#include <string>
using namespace std;

int main()
{
	Folder folderArray[5];
	Message msg1("Hello");
	for(auto& f :folderArray)
		f.printAllMsg();
	for(Folder &f : folderArray)
		msg1.save(f);
	for(auto& f :folderArray)
		f.printAllMsg();
	for(int i = 0; i < 0; ++i)
		msg1.remove(folderArray[i]);
	for(auto& f :folderArray)
		f.printAllMsg();
}
