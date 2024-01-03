#include "HT.h"

using namespace std;

int main()
{
	ht::HtHandle* ht = nullptr;
	try
	{
		ht = ht::create(1000, 3, 10, 256, L"./files/HTspace.ht");
		if (ht)
			cout << "-- create: success" << endl;
		else
			throw "-- create: error";
	
		if (ht::insert(ht, new ht::Element("abc", 4, "payload", 8)))
			cout << "-- insert: success" << endl;
		else
			throw "-- insert: error";

		if (ht::insert(ht, new ht::Element("cab", 4, "payload", 8)))
			cout << "-- insert: success" << endl;
		else
			throw "-- insert: error";

		
		
		if (ht::remove(ht, new ht::Element("abc", 4, "payload", 8)))
			cout << "-- remove: success" << endl;
		else
			throw "-- remove: error";

		ht::Element* hte = ht::get(ht, new ht::Element("cab", 4));
		if (hte)
			cout << "-- get: success" << endl;
		else
			throw "-- get: error";
		ht::print(hte);
		
		if (ht::insert(ht, new ht::Element("cab", 4, "payload", 8)))
			cout << "-- insert: success" << endl;
		else
			throw "-- insert: error";

		

	}
	catch (const char* msg)
	{
		cout << msg << endl;
	
		if (ht != nullptr)
			cout << ht::getLastError(ht) << endl;
	}

	try
	{
		if (ht != nullptr)
			if (ht::close(ht))
				cout << "-- close: success" << endl;
			else
				throw "-- close: error";
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
}