//
// Created by Oana Lupean on 26.05.2022.
//

#include "Domain.h"


Domain::Domain() = default;

Domain::Domain(const std::string& name, std::vector<std::string> keywords, const std::string &content) {
    this->name = name;
    this->keywords = keywords;
    this->content = content;
}

std::string Domain::get_name() const {
    return name;
}

std::vector<std::string> Domain::get_keywords() const{
    return keywords;
}

std::string Domain::file_output() const {
    std::string ans;
    ans = this->name + " | " ;
    for (auto each : this->keywords)
        ans = ans + each + ", ";
    ans = ans + " | ";
    for (auto each: this->content)
        ans = ans + each ;
    return ans;
}

std::string Domain::output() const {
    std::string ans;
    ans = this->name + " | " ;
    for (auto each : this->keywords)
        ans = ans + each + ", ";
    ans = ans + " | ";
    for (auto each: this->content)
        ans = ans + each ;
    return ans;
}
