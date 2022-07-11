//
// Created by Oana Lupean on 05.05.2022.
//





#include "UI.h"
#include <iostream>
#include "ElectricEngine.h"
#include "TurboEngine.h"

using namespace std;
UI::UI(Service service) {
    this->service = service;
}

UI::UI() {

}

UI::~UI() {

}

void UI::run_command() {
    this->initial_list();
    int command;
    while(true){
        this->print_menu();
        cin >> command;
        if(command == 1)
            this->add_a_new_car();
        if(command == 2)
            this->show_all_cars();
        if(command == 3)
            break;
    }
}

void UI::print_menu() {
    cout << "1. Add a new car" << endl;
    cout << "2. Show all cars" << endl;
    cout << "3. exit" << endl;
}

void UI::add_a_new_car() {
    string type;
    cout << "What type? Sedan or Convertible? ";
    cin >> type;
    if(type == "Sedan"){
        int price = 8000, autonomy;
        double final_price;
        string type2, fuel;
        cout << "What type of engine? Electric or Turbo? ";
        cin>>type2;
        cout<< "What type of fuel? gasoline or diesel?";
        cin>>fuel;
        if(type2 == "electric"){
            cout<<"What autonomy?";
            cin>>autonomy;

            Engine* a;
            auto b = new ElectricEngine(fuel, 3000, autonomy);
            a = b;
            final_price = price + 3000 + 0.01 * autonomy;
            cout<<"The final price is " + std::to_string(final_price) +'\n';

            this->service.add_a_car(a);}
        else{
            Engine* a;
            auto b = new TurboEngine(fuel, 3000);
            a = b;
            if (fuel == "gasoline"){
                final_price = price + 3000 + 0.01*100;
                cout<<"The final price is " + std::to_string(final_price) +'\n';}
            else {
                final_price = price + 3000 + 0.01*150;
                cout<<"The final price is " + std::to_string(final_price) +'\n';}
            this->service.add_a_car(a);
        }
    }
    else  if(type == "Convertible"){
        int price = 9000, autonomy;
        double final_price;
        string type2, fuel;
        cout << "What type of engine? Electric or Turbo? ";
        cin>>type2;
        cout<< "What type of fuel? gasoline or diesel?";
        cin>>fuel;
        if(type2 == "electric"){
            cout<<"What autonomy?";
            cin>>autonomy;

            Engine* a;
            auto b = new ElectricEngine(fuel, 3000, autonomy);
            a = b;

            final_price = price + 3000 + 0.01 * autonomy;
            cout<<"The final price is " + std::to_string(final_price) +'\n';
            this->service.add_a_car(a);
            }
        else{
            Engine* a;
            auto b = new TurboEngine(fuel, 3000);
            a = b;

            if (fuel == "gasoline"){
                final_price = price + 3000 + 0.01*100;
                cout<<"The final price is " + std::to_string(final_price) +'\n';}
            else {
                final_price = price + 3000 + 0.01*150;
                cout<<"The final price is " + std::to_string(final_price) +'\n';}
            this->service.add_a_car(a);
            }

    }
}

void UI::show_all_cars() {
    auto a = this->service.get_all_cars();
    for(auto &i : a){
        cout << i->to_string();
    }
}


void UI::initial_list() {
    Engine* a;
    auto b = new ElectricEngine("gasoline", 3000, 987);
    a = b;
    this->service.add_a_car(a);
    auto c = new TurboEngine("diesel", 3000);
    a = c;
    this->service.add_a_car(a);
    auto d = new ElectricEngine("gasoline", 3000, 97654);
    a = d;
    this->service.add_a_car(a);


}