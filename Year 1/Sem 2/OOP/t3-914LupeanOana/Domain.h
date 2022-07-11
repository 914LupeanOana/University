//
// Created by Oana Lupean on 26.05.2022.
//

#ifndef UNTITLED6_DOMAIN_H
#define UNTITLED6_DOMAIN_H

#include <fstream>
#include <vector>
#include <string>


class Domain{
private:
    std::string name;
    std::vector<std::string> keywords;
    std::string content;

public:
    Domain();

    Domain(const std::string &name, std::vector<std::string>keywords, const std::string &content);

    std::string get_name() const;

    std::string output() const;

    std::string file_output() const;

    std::vector<std::string> get_keywords() const;
};

#endif //UNTITLED6_DOMAIN_H
