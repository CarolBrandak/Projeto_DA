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
    void sortOrdersReward(vector<Order> & storage);//Ordena as orders por reward de maior para menor
    void sortEstafetas(vector<Estafeta> & estafetas);
    void sortEstafetasCost(vector<Estafeta> & estafetas);//Orderna os estafetas de menor para maior cost
    void orderstoEstafetas();
    void test();
    void setProfit();//Calcula o lucro e mete na variavel profit

private:
    vector<Order> storage;
    vector<Estafeta> estafetas;
    int estafetaId = 1;
    int orderID = 1;
    int profit;
};


#endif //UNTITLED_APPLICATION_H
