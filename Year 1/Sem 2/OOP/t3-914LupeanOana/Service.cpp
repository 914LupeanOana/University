//
// Created by Oana Lupean on 26.05.2022.
//

#include "Service.h"


Service::Service(const string& path) {
    this->path = path;
}

void Service::save(vector<Domain> all) {
    ofstream fout(this->path);
    for(const auto &elem : all)
        fout << elem.file_output();
    fout.close();
}

vector<Domain> Service::load_content() {
    ifstream fin(this->path);
    vector<Domain>store;
    string name, keyword, content;

    string all;
    while (getline(fin, all)) {
        vector<string> mines;

        string turn = "";
        for(auto x : all){
            if(x == '|'){
                mines.push_back(turn);
                turn = "";
            }
            else
                turn += x;
        }
        mines.push_back(turn);
        name = mines[0];
        keyword = mines[1];
        content = mines[2];
        //cout << category << " " << name << " " << symp << "\n";


        vector<string>keywords;
        string now = "";

        for(auto x : keyword){
            if(x == ','){
                keywords.push_back(now);
                now = "";
            }
            else
                now += x;
        }
        keywords.push_back(now);

        store.push_back(Domain(name, keywords, content));

    }
    fin.close();
    return store;
}