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
    /**
     * Application constructor
     */
    Application();

    /**
     * Read the file name
     * @param fileName File Name
     */
    void readFile(const string& fileName);

    /**
     * print Initial Menu and choose initial menu options
     */
    void initialMenu();

    /**
     * Split the line in words
     * @param line line get from the file
     * @param type type (encomendas or carrinhas)
     */
    void splitWord(const string& line, const string& type);

    /**
     * Create new order and push that word to storage vector
     * @param words Order arguments
     */
    void updateOrders(vector<string> words);

    /**
     * Create new Estafeta and push that Estafeta to estafetas vector
     * @param words Estafetas arguments
     */
    void updateEstafetas(vector<string> words);

    /**
     * Sort the vector storage in descendent way using Bubble Sort Technique
     * First criterio -> Volume
     * Second criterio -> Weight
     * @param storage vector with orders
     */
    void sortOrdersDesc(vector<Order> & storage);

    void sortEstafetasDesc(vector<Estafeta> & estafetas);

    /**
     * Sort the vector storage using Bubble Sort Technique
     * First criterio -> Occupied
     * Second criterio -> Occupied in ascendent way (first criterio->volume, second criterio ->weight)
     * Third crirterio -> Not Occupied in descendent way (first criterio->volume, second criterio ->weight)
     * @param estafetas  vector with estafetas
     */
    void sortEstafetas(vector<Estafeta> & estafetas);

    /**
     * minimize the number of Estafetas to deliver all orders or the largest number of orders in one day
     */
    void optimizationEstafeta();

    /**
     * print optmization menu and choose the option
     */
    void optimizationMenu();

    /**
     * create new Estafeta and push that to estafetas vector
     */
    void createNewEstafeta();

    /**
     * create new Order and push that to storage vector
     */
    void createNewOrder();

    /**
     *print every Order in vector storage
     */
    void seeStorage();

    /**
     * print every Estafeta in vector estafetas
     */
    void seeEstafetas();

    /**
     * Count the number of Estafetas Ocuppied and print that
     * @return
     */
    int numberEstafetasOccupied();

    /**
     * Search for the Estafeta in estafetas by estafeta id and print the Estafeta orders
     */
    void searchEstafeta();

    /**
     * Tell user if want to choose another Estafeta
     */
    void auxSearchEstafeta();

    void sortOrdersReward(vector<Order> & storage);//Ordena as orders por reward de maior para menor

    void sortEstafetasCost(vector<Estafeta> & estafetas);//Orderna os estafetas de menor para maior cost

    void setProfit();//Calcula o lucro e mete na variavel profit

    void test();


private:
    vector<Order> storage;
    vector<Estafeta> estafetas;
    int estafetaId = 1;
    int orderID = 1;
    int profit;
    bool stateApplication=true;
};


#endif //UNTITLED_APPLICATION_H
