#include "Directory.h"
#include "Entry.h"

using namespace std;

namespace rec09 {
	void Directory::add(const string& name, unsigned room, unsigned ph, Position& pos) {
		if( size == capacity )	{
			Entry** temp = new Entry*[size];
			for(size_t i = 0; i < size; ++i)    // Copy the pointer values to a temp
				temp[i] = entries[i];			//

			entries = new Entry*[capacity *= 2];

			for(size_t i = 0; i < size; ++i) 		// Add entries to new sized entries
				entries[i] = new Entry(*temp[i]);	//

			for(size_t i = 0; i < size; ++i)		//
				delete temp[i];						// delete temp
			delete [] temp;							//
		}
		entries[size++] = new Entry(name, room, ph, pos);
	}

	Directory::Directory() : capacity(2), size(0), entries(new Entry*[2])
	{
		for (size_t i = 0; i < capacity; i++) {
			entries[i] = NULL;
		}
	}

	Directory::Directory(const Directory& rhs) : capacity (rhs.capacity), size(rhs.size) {
		entries = new Entry*[capacity];
		for(size_t i = 0; i < rhs.size; ++i) {
			entries[i] = new Entry(*rhs.entries[i]);
		}
	}

	Directory::~Directory() {
		for(size_t i = 0; i < size; ++i) {
			delete entries[i];
		}
		delete [] entries;
	}

	Directory& Directory::operator=(const Directory& rhs) {
		if(this != &rhs) {
			for(size_t i = 0; i < size; ++i) {
				delete entries[i];
			}
			delete [] entries;

			size = rhs.size;
			capacity = rhs.capacity;
			entries = new Entry*[capacity];
			for(size_t i = 0; i < size; ++i) {
				entries[i] = new Entry(*rhs.entries[i]);
			}
		}
		return *this;
	}

	unsigned Directory::operator[](const string& indexer) {
		for(size_t i = 0; i < size; ++i) {
			if(entries[i]->get_name() == indexer) {
				return entries[i]->get_phone();
			}
		}
		return 0;
	}

	ostream& operator<<(ostream& out, const Directory& dir) {
		out << "Directory:";
		for(size_t i = 0; i < dir.size; ++i) {
			out << "\n\t" << *dir.entries[i];
		}
		return out;
	}
}