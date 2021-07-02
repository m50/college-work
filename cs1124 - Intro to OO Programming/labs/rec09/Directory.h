#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <string>
#include <ostream>

namespace rec09 {
	class Entry;
	class Position;

	class Directory {
	public:
		Directory();
		Directory(const Directory& rhs);
		~Directory();
		void add(const std::string& name, unsigned room, unsigned ph, Position& pos);
		Directory& operator=(const Directory& rhs);
		unsigned operator[](const std::string& indexer);
		friend std::ostream& operator<<(std::ostream& out, const Directory& dir);
	private:	
		size_t capacity;
		size_t size;
		Entry** entries;
	};
}

#endif