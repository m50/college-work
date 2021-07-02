#ifndef ENTRY_H
#define ENTRY_H

#include <string>
#include <ostream>

namespace rec09 {
	class Position;

	class Entry {
	public: 
		Entry(const Entry& ent);
		Entry(const std::string& aName, unsigned aRoom, unsigned aPhone, Position& aPosition);
		std::string get_name() const;
		unsigned get_phone() const;
		Entry& operator=(const Entry& rhs);
		friend std::ostream& operator<<(std::ostream& os, const Entry& e);
	private:
		std::string name;
		unsigned room;
		unsigned phone;
		Position* pos;
	};
}

#endif