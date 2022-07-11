//
// Created by Oana Lupean on 07.04.2022.
//

#ifndef T1_914LUPEANOANA_1_EXCEPTION_H
#define T1_914LUPEANOANA_1_EXCEPTION_H
#include <exception>
#include <string>

class RepoException :public std::exception {
private:
    std::string message;
public:
    RepoException(const std::string&);
    const std::string& getMessage() const;

};

class ValidatorException : public RepoException {
public:
    ValidatorException(const std::string&);
};

#endif //T1_914LUPEANOANA_1_EXCEPTION_H
