// Implementation file for Unsorted List ADT.
#include "dynamicList.h"

dynamicList::dynamicList()		// Class constructor
{
	length = 0;
	size = defmaxlistsize;
	element = new int[defmaxlistsize];
	for (int i = 0; i < defmaxlistsize; i++)
		element[i] = 0;
}

dynamicList::dynamicList(int maxnumber )		// Class constructor
{
	length = 0;
	size = maxnumber;
	element = new int[maxnumber];
	for (int i = 0; i < maxnumber; i++)
		element[i] = 0;
}

dynamicList::~dynamicList()
// Post: List is empty; all items have been deallocated.
{
	delete[] element;
	length = 0;
}

void dynamicList::Print() const
{
	for (int i = 0; i < length; i++)
	{
		cout << "\tLocation " << i << " = " << element[i] << endl;

	}
}

bool dynamicList::Full() const
// Returns true if there is no room for another int on the free store;
// false otherwise.
{
	if (length == size){
		return true;
	}
	else
		return false;
}


bool dynamicList::Empty() const
// Post: List is empty; all items have been deallocated.
{
	if (length == 0)
		return true;
	else
		return false;
}

bool dynamicList::Search(int item)
// Pre:  Key member(s) of item is initialized.
// Post: If found, item's key matches an element's key in the list and 
//       a copy of that element has been stored in item; otherwise, item is
//       unchanged. 
{
	bool moreToSearch;
	int location = 0;


	moreToSearch = true;

	while ((moreToSearch) && (location < size))
	{
		if (item == element[location])
		{
			return true;
		}
		else
		{
			location++;
		}
	}
	return false;
}

bool dynamicList::Search(int item, int &location)
// Pre:  Key member(s) of item is initialized.
// Post: If found, item's key matches an element's key in the list and 
//       a copy of that element has been stored in item; otherwise, item is
//       unchanged. 
{
	bool moreToSearch;
	location = 0;

	moreToSearch = true;

	while ((moreToSearch) && (location < size))
	{
		if (item == element[location])
		{
			return true;
		}
		else
		{
			location++;
		}
	}
	return false;
}

bool dynamicList::Insert(int item)
// item is in the list; length has been incremented.
{

	if (!Full())
	{
		element[length] = item;
		length++;
		return true;
	}
	else
	{
		cout << "Error: Cannot Insert.  List is Full.\n";
		return false;
	}

}

bool dynamicList::Insert(int item, int location)
// item is in the list; length has been incremented.
{

	if (!Full())
	{
		if (location >= 0 && location < size && !Full())
		{
			if (location > length)
			{
				for (int i = length; i < location; i++)
					element[i] = -1;
				length = location + 1;
			}
			else
				length++;
			for (int i = length; i > location; i--){
				element[i] = element[i-1];
			}
			element[location] = item;
			return true;
		}
		cout << "Error: Cannot Insert at " << location << " that is out of bounds\n";
	}
	else
	{
		cout << "Error: Cannot Insert "<<item<<" List is Full.\n";
		return false;
	}
}

void dynamicList::Remove(int &item, bool &found, int location)
// Pre: item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
	// Locate node to be deleted.
	if (!Empty())
	{
		if (location > 0 && location < length)
		{
			item = element[location];
			for (int i = location; i < length; i++)
			{
				element[i] = element[i + 1];
			}
			length--;
			found = true;
			return ;
		}else{
			cout << "Error: Location "<<location<<" is not a valid location at this time.\n";
			found = false;
			return;
		}
	}
	else
	{
		cout << "Error: List is Empty.  Cannot Delete.\n";
		found = false;
	}
}

void dynamicList::Remove(int &item, bool &found)
// Pre: item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
	// Locate node to be deleted.
	if (!Empty())
	{
		int location = -1;
		if (Search(item, location))
		{
			item = element[location];
			for (int i = location; i < length; i++)
			{
				element[i] = element[i + 1];
			}
			length--;
			found = true;
			return;
		} else {
			cout << "Error: "<<item<<" Not Found\n";
			found = false;
			return;
		}
	}
	else
	{
		cout << "Error: List is Empty.  Cannot Delete.\n";
		found = false;
	}

}

int dynamicList::currentSize() const
// Post: Current position has been initialized.
{
	return length;
}

void dynamicList::Clear()
// Post: Current position has been initialized.
{
	length = 0;
}

void dynamicList::Getlast(int& item, bool &found)
// Post:  Current position has been updated; item is current item.
{
	if (!Empty())
	{
		item = element[length - 1];
		found = true;
	}
	else
	{
		cout << "Error: List is Empty.  Cannot Get Top Element.\n";
		found = false;
	}
}
