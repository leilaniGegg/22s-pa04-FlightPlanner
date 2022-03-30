//Resources
//(helped me figure out how to use maps with DSString) https://stackoverflow.com/questions/1102392/how-can-i-use-stdmaps-with-user-defined-types-as-key
#ifndef INC_22S_FLIGHT_PLANNER_DSSTRING_H
#define INC_22S_FLIGHT_PLANNER_DSSTRING_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include "DSVector.h"
#include <map>
#include <iterator>

using namespace std;

class DSString{

private:
    /**
     *  You will need to add some private data members here.
     *  This is up to your discretion.  However, we **strongly**
     *  encourage you to implement your string class as a wrapper
     *  for typical null-terminated c-strings.  In doing this, you
     *  may use c-sting functions in the methods in this class such
     *  as:
     *    * strlen(...)
     *    * strcpy(...)
     *    * strcmp(...)
     *    * strncpy(...)
     *    * strcat(...)
     *    * strncat(...)
     *
     *    A quick google search will return plenty of references on
     *    the c-string functions.
     **/
    char *word;
    friend struct DSStringCompare;


public:

    /**
     * Constructors and destructor
     *
     * Make sure you do proper memory management.
     **/
    static const size_t npos = -1; //not sure about this?? maybe for oleander to work

    DSString();
    DSString(const char*);
    DSString(const DSString&);
    ~DSString();

    /**
     * Overloaded Assignment Operators
     */
    DSString& operator= (const char*);
    DSString& operator= (const DSString&);

    /**
     * Overloaded non-modifying string concat
     * @return
     */
    DSString operator+ (const DSString&);
    /**
     * Overloaded modifying string concat
     * @return
     */
    DSString& operator+= (const DSString&);

    /**
     * Standard relational operators.  Feel free to add additional.
     *
     * Note that for each operator, there are two overloaded versions:
     *    one that takes a DSString object
     *    one that takes a null-terminated c-string
     *
     **/

    bool operator== (const char*);
    bool operator== (const DSString&);
    bool operator!= (const DSString&);
    bool operator> (const DSString&) const;
    bool operator> (const char*);
    bool operator<(const DSString&)const;
    bool operator< (const char*);

    /**
     * Subscript operator to access a particular character of a DSString object
     * @return the character requested by reference
     */
    char& operator[] (const int)const;

    /**
     * getLength() returns the number (count) of characters in the string.
     **/
    int getLength()const;

    /**
     * The substring method returns a string object that contains a
     * sequence of characters from this string object.
     *
     * param start - the index of where to start
     * param numChars - the number (count) of characters to copy into
     *    the substring
     * @return a DSString object containing the requested substring
     **/
    DSString substring(int start, int numChars);
    DSString substringIndex(int start, int end); //substring from start to end index-1
    DSVector<DSString> parseLine(const char*)const;

    /**
     * the c_str function returns a null-terminated c-string holding the
     * contents of this object.
     **/
    char * c_str() const;  //may need to get rid of const

    /**
     * Overloaded stream insertion operator to print the contents of this
     * string to the output stream in the first argument.
     **/
    friend ostream& operator<< (ostream&, const DSString&);

    friend istream& operator>>(istream& is,DSString& obj);
    bool find(const DSString&);
    DSString& toLower();
    DSString toUpper()const;


    //You are free to add more functionality to the class.  For example,
    //you may want to add a find(...) function that will search for a
    //string within a string.  (just an example)
    //
    //Further - you will be able to update and modify this class as the
    //semester progresses.


};

struct DSStringCompare{
    bool operator() (const DSString& left, const DSString& right) const {
        if (strcmp(left.c_str(), right.c_str()) < 0) {
            return true;
        }
        return false;
    }
};

#endif //INC_22S_FLIGHT_PLANNER_DSSTRING_H