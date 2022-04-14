//
// Created by Luís  Paiva on 11/04/2022.
//

#ifndef UNTITLED_APPLICATION_H
#define UNTITLED_APPLICATION_H

#include <iostream>
using std::cout;
using std::endl;
using std::cerr;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <fstream>
using std::ifstream;
#include "Estafeta.h"
#include "Order.h"

class Application {
public:

    Application();
    void readFile(const string& fileName);
    void initialMenu();
    void splitWord(const string& line, const string& type);
    void createNewOrder(vector<string> words);
    void createNewEstafeta(vector<string> words);
    void sortOrders(vector<Order> & storage);
    void sortEstafetas(vector<Estafeta> & estafetas);
    void orderstoEstafetas();
    void test();


private:
    vector<Order> storage;
    vector<Estafeta> estafetas;
    int estafetaId = 1;
    int orderID = 1;
};


#endif //UNTITLED_APPLICATION_H
