#ifndef _MESSAGE_AND_FOLDER_
#define _MESSAGE_AND_FOLDER_
#include <set>
#include <string>
class Message;

class Folder
{
	friend class Message;
public:
	Folder():
		folderNo(folderNoSerial++){	}
	int getNo()const
	{
		return folderNo;
	}
	void printAllMsg()const;
	
	
private:
	static int folderNoSerial;
	std::set<Message*>messages;	
	int folderNo;
};

void swap(Message& msg1, Message& msg2);

class Message
{
	friend class Folder;
	friend void swap(Message& msg1, Message& msg2);
public:
	Message(const std::string& s = ""):
		mes(s)	{	}
	Message(const Message& m);
	Message& operator=(const Message& m); 
	~Message();
	void save(Folder& f);
	void remove(Folder& f);
	
private:
	std::string mes;
	std::set<Folder*>folders;
	void add_to_folders(const Message& );
	void remove_from_folders();
};


#endif
