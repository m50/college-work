#include <iostream>
#include <vector>
using namespace std;

class Instrument {
public:
	Instrument () {}
	virtual void makeSound() const = 0;
	virtual void play() const = 0;
private:
};
void Instrument::makeSound () const { cout << "To make a sound... "; }

class Brass : public Instrument {
public:
	Brass (unsigned si) : size(si) {}
	void makeSound() const { Instrument::makeSound(); cout << "blow on a mouthpiece of size " << size << endl; }
	void play() const { makeSound(); }
private:
	const unsigned size;
};

class String : public Instrument {
public:
	String (unsigned pi) : pitch(pi) {}
	void makeSound() const { Instrument::makeSound(); cout << "bow a string with pitch " << pitch << endl; }
	void play() const { makeSound(); }
private:
	const unsigned pitch;
};

class Percussion : public Instrument {
public:
	Percussion () {}
	void makeSound() const { Instrument::makeSound(); cout << "hit me!" << endl; }
	void play() const { makeSound(); }
private:
};

class Drum : public Percussion {
public:
	void play() const { cout << "Boom"; }
};
class Cymbal : public Percussion {
public:
	void play() const { cout << "Crash"; }
};
class Cello : public String {
public:
	Cello (unsigned pi) : String(pi) {}
	void play() const { cout << "Squawk"; }
};
class Violin : public String {
public:
	Violin (unsigned pi) : String(pi) {}
	void play() const { cout << "Screech"; }
};
class Trumpet : public Brass {
public:
	Trumpet (unsigned si) : Brass(si) {}
	void play() const { cout << "Toot"; }
};
class Trombone : public Brass {
public:
	Trombone (unsigned si) : Brass(si) {}
	void play() const { cout << "Blat"; }
};

class MILL {
public:
	MILL () {}
	void receiveInstr(Instrument& instr) {
		for(size_t i = 0; i < instruments.size(); ++i) {
			if(!instruments[i])
			{
				instruments[i] = &instr;
				return;
			}
		}
		instruments.push_back(&instr);
	}
	void dailyTestPlay() const {
		for(Instrument* instr : instruments) if(instr) instr->makeSound();
	}
	Instrument* loanOut() {
		for (size_t i = 0; i < instruments.size(); ++i)
		{
			if(instruments[i]) {
				Instrument* instr = instruments[i];
				instruments[i] = nullptr;
				return instr;
			}
		}	
		return nullptr;
	}
private:
	vector<Instrument*> instruments;
};

class Musician {
public:
	Musician() : instr(nullptr) {}
	void acceptInstr(Instrument& i) { instr = &i; }
	Instrument* giveBackInstr() { 
		Instrument* tmp(instr); 
		instr = nullptr;
		return tmp;
	}
	void testPlay() const {
		if( instr )
			instr->makeSound(); 
		else
			cerr << "have no instr\n";
	}
	void play() const {
		if( instr )
			instr->play();
	}
private:
	Instrument* instr;
};

class Orch {
public:
	Orch() {}
	void addPlayer(Musician& musc) {
		if(musicians.size() < 25)
			musicians.push_back(&musc);
		else cerr << "This orchestra is full!" << endl;
	}

	void play () const {
		for(Musician* musc : musicians) musc->play();
		cout << endl;
	}
private:
	vector<Musician*> musicians;
};

// PART ONE
int main()
{
	// The initialization phase

	Drum drum;
	Cello cello(673);
	Cymbal cymbal;
	Trombone tbone( 4 );
	Trumpet trpt( 12 ) ;
	Violin violin( 567 ) ;

	MILL mill;
	mill.receiveInstr( trpt );
	mill.receiveInstr( violin );
	mill.receiveInstr( tbone );
	mill.receiveInstr( drum );
	mill.receiveInstr( cello );
	mill.receiveInstr( cymbal );

	Musician bob;
	Musician sue;
	Musician mary;
	Musician ralph;
	Musician jody;
	Musician morgan;

	Orch orch;



	// THE SCENARIO

	//Bob joins the orchestra without an instrument.
	orch.addPlayer(bob);

	//The orchestra performs
	cout << "orch performs\n";
	orch.play();

	//Sue gets an instrument from the MIL2 and joins the orchestra.
	sue.acceptInstr( *mill.loanOut() );
	orch.addPlayer(sue);

	//Ralph gets an instrument from the MIL2.
	ralph.acceptInstr( *mill.loanOut() );

	//Mary gets an instrument from the MIL2 and joins the orchestra.
	mary.acceptInstr( *mill.loanOut() );
	orch.addPlayer(mary);

	//Ralph returns his instrument to the MIL2.
	mill.receiveInstr( *ralph.giveBackInstr() );

	//Jody gets an instrument from the MIL2 and joins the orchestra.
	jody.acceptInstr( *mill.loanOut() );
	orch.addPlayer(jody);

	// morgan gets an instrument from the MIL2
	morgan.acceptInstr( *mill.loanOut() );

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Ralph joins the orchestra.
	orch.addPlayer(ralph);

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();
	
	// bob gets an instrument from the MIL2
	bob.acceptInstr( *mill.loanOut() );

	// ralph gets an instrument from the MIL2
	ralph.acceptInstr( *mill.loanOut() );

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Morgan joins the orchestra.
	orch.addPlayer(morgan);

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();
}
