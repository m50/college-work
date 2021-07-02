#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Complex {
   double real;
   double img;
};

class PlainOldClass {  
public:
   PlainOldClass() : x(-72) {}
   int getX() const { return x; }   
   void setX( int x )  { this->x = x; } // No confusion!
private:
   int x;
};

class SpeakerSystem {
   public:
   void vibrateSpeakerCones( unsigned signal ) const {

      cout << "Playing: " << signal << "Hz sound..." << endl;
      cout << "Buzz, buzzy, buzzer, bzap!!!\n";
   }
};

class Amplifier {
public:
   Amplifier( ) : attachedSpeakers( NULL ) {}
   void attachSpeakers( const SpeakerSystem& spkrs )
   {
      if( attachedSpeakers )
         cout << "already have speakers attached!\n";
      else
         attachedSpeakers = &spkrs;
   }
   void detachSpeakers() 
   { attachedSpeakers = NULL; }
     // should there be an "error" message if not attached?
   void playMusic( ) const {
      if( attachedSpeakers )
         attachedSpeakers -> vibrateSpeakerCones( 440 ); 
      else
         cout << "No speakers attached\n"; 
   }
private:
   const SpeakerSystem* attachedSpeakers;
};

int main() {
	// int x;  
	// x = 10;  
	// cout << "x = " << x << endl;

	// int* p;  
	// p = &x;  
	// cout << "p = " << p << endl;
	// cout << "p points to where " << *p << " is stored\n";  
	// cout << "*p contains " << *p << endl;   
	
	// *p = -2763;  
	// cout << "p points to where " << *p << " is      stored\n";  
	// cout << "*p now contains " << *p << endl;  
	// cout << "x now contains " << x << endl;
	// int y(13);      

	// cout << "y contains " << y << endl;      
	// p = &y;      
	// cout << "p now points to where " << *p << " is stored\n";      
	// cout << "*p now contains " << *p << endl;      
	// *p = 980;      
	// cout << "p points to where " << *p << " is stored\n";      
	// cout << "*p now contains " << *p << endl;      
	// cout << "y now contains " << y << endl;

	// int* q;      
	// q = p;      
	// cout << "q points to where " << *q << " is stored\n";      
	// cout << "*q contains " << *q << endl;

	// int joe( 24 );  
	// const int sal( 19 );    
	// int*  pI;  
	 
	// Complex c = {11.23,45.67};
	// Complex* pC(&c);
	// //cout << "real: " << *pC.real << "\nimaginary: " << *pC.img << endl;
	// cout << "real: " << (*pC).real << "\nimaginary: " << (*pC).img << endl;

	// PlainOldClass poc;
	// PlainOldClass* ppoc( &poc );
	// cout << ppoc->getX() << endl;
	// ppoc->setX( 2837 );
	// cout << ppoc->getX() << endl;

	// int* pDyn = new int(3); // p points to an int initialized to 3 on the heap      
	// *pDyn = 17;
	// cout << "The " << *pDyn << " is stored at address " << pDyn<< " which is in the heap\n";

	// cout << pDyn << endl;  
	// delete pDyn;  
	// cout << pDyn << endl;

	// cout << "The 17 might STILL stored at address " << pDyn<< " even though we deleted pDyn\n";  
	// cout << "But can we dereference pDyn?  We can try.  This might crash... " << *pDyn << ".  Still here?\n";
	// pDyn = NULL;
 //    double* pTest = new double( 12 );      
	// delete pTest;      
	// pTest = NULL;      
	// delete pTest; // safe
	// short* pShrt = new short( 5 );      
	// // delete pShrt;      
	// // delete pShrt;

	// long jumper( 12238743 );      
	// long* ptrTolong( &jumper );      
	// delete ptrTolong;        
	// vector<Complex*> compli;
	// Complex* tmpPCmplx;      // grab heap space for 3 Complex objects and "store" them
	//                          // in the vector. We are really storing the Complex objects
	//                          // we think of this as "storing" them
	// for ( size_t ndx = 0 ; ndx < 3 ; ++ndx ) {
	//    tmpPCmplx = new Complex;
	//    tmpPCmplx->real = ndx;
	//    tmpPCmplx->img  = ndx;
	//    compli.push_back( tmpPCmplx );
	// }      
	// // display them      
	// for ( size_t ndx = 0 ; ndx < 3 ; ++ndx ) {         
	//     cout << compli[ ndx ]->real << endl;         
	//     cout << compli[ ndx ]->img  << endl;      
	// }      
	// // release them      
	// for ( size_t ndx = 0 ; ndx < 3 ; ++ndx ) {         
	//     delete compli[ ndx ];      
	// }      
	// // clear the vector      
	// compli.clear();    

	class Colour {  
	public:       
	    Colour( const string& name, unsigned r, unsigned g, unsigned b )       
	        : name(name), r(r), g(g), b(b) {}       
	    void display() const { 
	        cout << name << " (RBG: " << r << "," << g<< "," << b << ")"; 
	    }   
	private:       
	    string   name;    // what we call this color       
	    unsigned r, g, b; // red/green/blue values for displaying  
	};         

	vector< Colour* > colours;         
	string inputName;       
	unsigned inputR, inputG, inputB;   // fill vector with Colours from the file       
	                                   // this could be from a file but we are using the keyboard for now       
	                                   // (do you remember the keystrokes to indicate "end of file" at the keyboard?)       
	while ( cin >> inputName >> inputR >> inputG >> inputB ) {            
	    colours.push_back( new Colour(inputName, inputR, inputG, inputB) );       
	}         

	// display all the Colours in the vector:       
	for ( size_t ndx = 0; ndx < colours.size(); ++ndx ) {            
	    colours[ndx]->display();            
	    cout << endl;       
	}

	class Person {  
	public:       
	    Person( const string& name ) : name(name) {}
	    void movesInWith( Person& newRoomate ) {
	        roomie = &newRoomate;        // now I have a new roomie            
	        newRoomate.roomie = this;    // and now they do too       
	    }       
	    string getName() const { return name; }       
	    string getRoomiesName() const { return roomie->getName(); }  
	private:
	    Person* roomie;       
	    string name;  
	};           

	// write code to model two people in this world       
	Person joeBob("Joe Bob"), billyJane("Billy Jane");         
	// now model these two becoming roommates       
	joeBob.movesInWith( billyJane );         
	// did this work out?       
	cout << joeBob.getName() << " lives with " << joeBob.getRoomiesName() << endl;
	cout << billyJane.getName() << " lives with " << billyJane.getRoomiesName() << endl;
}