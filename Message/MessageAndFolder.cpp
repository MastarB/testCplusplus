#include "MessageAndFolder.h"
#include <iostream>
#include <set>

//Implement for class 'Folder'
using namespace std;

void Folder::printAllMsg()const
{
	if(!messages.empty())
		cout<<"Messages in the folder "<<folderNo<<" are listed as follow :"<<endl;
	else
			cout<<"There is no message in the folder "<<folderNo<<endl;
	for(Message *m : messages)
	{
		cout<<m->mes<<endl;
	}
}

int Folder::folderNoSerial = 0;
//end the Implement for class 'Folder'

//Implement for class 'Message'
Message::Message(const Message& m)
	:mes(m.mes),folders(m.folders)
{
	add_to_folders(m);	
}
	
Message& Message::operator=(const Message& m)
{
  //if(this != &m)
  //{
		mes = m.mes;
		remove_from_folders();
		folders = m.folders;
		add_to_folders(m);
		return *this;
  //}
}
Message::~Message()
{
	remove_from_folders();
}
void Message::save(Folder &f)
{
	set<Message*>::iterator rst = f.messages.find(this);
	if(rst != f.messages.end())
	{
		cout<<"Message: "<<"\""<<mes<<"\" "<<"is already in the Folder "<<f.folderNo<<"."<<endl;
		return;
	}
	f.messages.insert(this);
	folders.insert(&f);
}
	
void Message::remove(Folder& f)
{
	set<Message*>::iterator rst = f.messages.find(this);
	if(rst == f.messages.end())
	{
		cout<<"Message:"<<"\""<<mes<<"\" "<<"is not in th Folder"<<f.folderNo<<"."<<endl;
		return;
	}
	f.messages.erase(this);
	folders.erase(&f);//it will invalidate the iterator for the set, and foreach loop will get into disaster!!!!
}

void Message::remove_from_folders()
{
	for(Folder *i : folders)
		i->messages.erase(this);
}

void Message::add_to_folders(const Message& m)
{
	for(Folder *i : m.folders)
		i->messages.insert(this);
}

void swap(Message& msg1, Message& msg2)
{
	//exchange the content
	using std::swap;
	swap(msg1.mes,msg2.mes);
	//save msg's folders in 'tmp', and replace the folders with ones in msg2, update these folders;
	Message tmp = msg1;
	msg1.remove_from_folders();
	msg1.add_to_folders(msg2);
	msg1.folders = msg2.folders;
	//remove the folders in msg2, and replace them with ones in tmp;
	msg2.remove_from_folders();
	msg2.add_to_folders(tmp);
	msg2.folders = tmp.folders;
}

//end the Implement for class 'Message'



