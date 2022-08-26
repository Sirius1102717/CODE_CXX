// parts.h

#ifndef _PARTS_H_
#define _PARTS_H_

#include <vector>
#include <map>
#include <string>

using namespace std;

//**************** Part ****************
class Part {
	
public:
	string name;

	// TODO: Finish declaration
	
	Part(string const &n) : name(n) {};
	void describe(void);
	int count_howmany(Part const *p);
};


//**************** NameContainer ****************
class NameContainer  {

private:
	map<string,Part*> name_map;

public:

	NameContainer(void) {};

	Part* lookup(string const &name) {
    
        // TODO: Finish implementation
	}
};

NameContainer partContainer;  

//**************** Part Member Functions ****************
void Part::describe(void) {
	
    // TODO: Finish implementation

}

int Part::count_howmany(Part const *p) {
		
    // TODO: Finish implementation

}

//**************** Miscellaneous Functions ****************
void add_part(string const &x, int q, string const &y) {

    // TODO: Finish implementation
    
}

#endif
