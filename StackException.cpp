

#include "StackException.h"

//
StackException::StackException(const char * message) {
    this->message = message;
}


//
const char* StackException::what() const throw() {
    return this->message;
} 

