#include "Entry.h"
#include "Position.h"

using namespace std;

namespace rec09 {
	Entry::Entry(const string& aName, unsigned aRoom, unsigned aPhone, Position& aPosition) : name(aName), room(aRoom), phone(aPhone), pos(&aPosition) { }

	Entry::Entry(const Entry& ent) : name(ent.name), room(ent.room), phone(ent.phone), pos(new Position(*ent.pos)) { }

	string Entry::get_name() const { return name; }
	unsigned Entry::get_phone() const { return phone; }

	Entry& Entry::operator=(const Entry& rhs) {
		if(this != &rhs) {
			delete pos;

			name = rhs.name;
			room = rhs.room;
			phone = rhs.phone;
			pos = new Position(*rhs.pos);
		}
		return *this;
	}

	ostream& operator<<( ostream& os, const Entry& e ) {
		os << e.name << '\n'
		<< e.room << '\n' 
		<< e.phone;
		return os;
	}
}