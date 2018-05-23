#pragma once

#include <exception>

class StackException : public std::exception {
    const char* message;
public:
    StackException(const char *);
    virtual const char* what() const throw();
private:

};
 


