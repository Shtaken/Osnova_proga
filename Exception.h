#pragma once
#include <string>

class Exception {
private:
    std::string message;
public:
    Exception(const std::string& msg) : message(msg) {}
    std::string getMessage() const { return message; }
};