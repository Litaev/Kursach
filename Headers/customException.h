#ifndef CUSTOMEXCEPTION_H
#define CUSTOMEXCEPTION_H
#include <QString>



class CustomException : public std::exception{
    std::string exceptionMessage;
public:

    explicit CustomException(const std::string& msg) : exceptionMessage(msg) {}

    CustomException() : exceptionMessage("Произошла ошибка!") {}

    const char* what() const noexcept override {
        return exceptionMessage.c_str();
    }
};

#endif // CUSTOMEXCEPTION_H
