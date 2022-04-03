//
//
//Resources used:
//  https://www-geeksforgeeks-org.cdn.ampproject.org/v/s/www.geeksforgeeks.org/overloading-stream-insertion-operators-c/amp/?amp_gsa=1&amp_js_v=a8&usqp=mq331AQKKAFQArABIIACAw%3D%3D#amp_ct=1643261252202&amp_tf=From%20%251%24s&aoh=16432612505518&referrer=https%3A%2F%2Fwww.google.com&ampshare=https%3A%2F%2Fwww.geeksforgeeks.org%2Foverloading-stream-insertion-operators-c%2F
//  https://stackoverflow.com/questions/54526582/implementing-getline-for-my-custom-string-class (used for reference for implementing getline
//
#include "DSString.h"

//
//   Constructors and Destructor
//
DSString::DSString(){
    word = nullptr;
}
DSString::DSString(const char* input){
    if(input == nullptr){
        word = nullptr;
    }
    else {
        word = new char[strlen(input) + 1];
        strcpy(word, input);
        word[strlen(word)] = '\0';
    }
}
DSString::DSString(const DSString& input){
    word = new char[strlen(input.word) + 1];
    strcpy(word, input.word);
}
DSString::~DSString(){
    if(word != nullptr){
        delete[] word; //is this bracket or no?
    }
}

//
//  Overloaded Operators
//

DSString& DSString::operator= (const char* temp){
    if(word != nullptr){
        delete[] word;
    }
    word = new char[strlen(temp) + 1];
    strcpy(word, temp);
    word[strlen(word)] = '\0';
    return *this;
}

DSString& DSString::operator= (const DSString& temp){
    if(this == &temp){
        return *this;
    }
    if(this != nullptr){
        delete[] word;
    }
    word = new char[strlen(temp.word) + 1];
    strcpy(this->word, temp.word);
    word[strlen(word)] = '\0';
    return *this;
}

DSString DSString::operator+ (const DSString& temp){
    DSString newWord(*this);
    strcat(newWord.word, temp.word);
    return newWord;
}

DSString& DSString::operator+= (const DSString& temp){
    strcat(this->word, temp.word);
    return *this;
}

bool DSString::operator== (const char* temp){
    if(strcmp(word, temp) == 0){
        return true;
    }
    return false;
}

bool DSString::operator== (const DSString& temp){
    if (strcmp(this->word, temp.word) == 0){
        return true;
    }
    return false;
}

bool DSString::operator!= (const DSString& temp){
    if (strcmp(this->word, temp.word) == 0){
        return false;
    }
    return true;
}

bool DSString::operator> (const DSString& temp) const{
    if (strcasecmp(this->c_str(), temp.c_str()) > 0){
        return true;
    }
    return false;
}

bool DSString::operator> (const char* temp){
    if (strcasecmp(this->c_str(), temp) > 0){
        return true;
    }
    return false;
}

bool DSString::operator< (const DSString& temp) const{
    if (strcasecmp(this->c_str(), temp.c_str()) < 0){
        return true;
    }
    return false;
}

bool DSString::operator< (const char* temp){
    if (strcasecmp(this->c_str(), temp) < 0){
        return true;
    }
    return false;
}

char& DSString::operator[] (const int index)const{
    return word[index];
}

//
// Other functions
//
int DSString::getLength()const{
    return strlen(word);
}

DSString DSString::substring(int start, int numChars){
    char tempWord[numChars + 1];
    int i = 0;
    while(i < numChars) {
        tempWord[i] = word[start + i];
        i++;
    }
    return DSString(tempWord);
}

//returns substring from start to end-1 (not needed for project 1)
/*DSString DSString::substringIndex(int start, int end){
    if(start == end){
        return DSString("");
    }
    char tempWord[end - start];
    int i = start;
    int x = 0;
    while(i < end) {
        tempWord[x] = word[i];
        i++;
        x++;
    }
    return DSString(tempWord);
} */

char * DSString::c_str() const {
    return word;
}

ostream& operator<< (ostream& output, const DSString& temp){
    output << temp.word;
    return output;
}

istream& operator>>(istream& inSS, DSString& word){
    char* temp;
    inSS >> temp;
    word = temp;
    return inSS;
}


bool DSString::find(const DSString& temp){
    if(strstr(this->c_str(), temp.c_str()) == nullptr){
        return false;
    }
    return true;
}

DSString& DSString::toLower(){
    for(int i = 0; i < strlen(word); i++){
        word[i] = tolower(word[i]);
    }
    return *this;
}

DSString DSString::toUpper()const{
    DSString temp = word;
    for(int i = 0; i < strlen(word); i++){
        temp[i] = toupper(word[i]);
    }
    return temp;
}

DSVector<DSString> DSString::parseLine(const char* delim)const{
    DSVector<DSString> wordsFromLine;
    char* tempWord = strtok(this->c_str(), delim);
    while(tempWord != NULL){
        DSString newWord(tempWord);
        wordsFromLine.push_back(newWord);//will this work?
        tempWord = strtok(NULL, delim);
    }
    return wordsFromLine;
}