//
// Created by Oana Lupean on 07.04.2022.
//

#include "exception.h"

RepoException::RepoException(const std::string& message) :std::exception(), message{ message }
{}

const std::string& RepoException::getMessage() const
{
    return this->message;
}

ValidatorException::ValidatorException(const std::string& message) : RepoException(message)
{}
