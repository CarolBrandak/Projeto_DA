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
#include <algorithm>
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
     * Create new order and push that word to expressOrders vector
     * @param words Order arguments
     */
    void updateExpress(vector<string> words);

    /**
     * Create new Estafeta and push that Estafeta to estafetas vector
     * @param words Estafetas arguments
     */
    void updateEstafetas(vector<string> words);

    /**
     * Sort the vector storage in descendent way using Bubble Sort Technique (Formula Weight*Volume)
     * @param storage vector with orders
     */
    void sortOrdersDesc(vector<Order> & storage);

    /**
     * Sort the vector storage in ascent way using Bubble Sort Technique
     * Criterio -> Duration
     */
    void sortOrdersTime();

    /**
     * Sort the vector storage using Bubble Sort Technique
     * First criterio -> Occupied
     * Second criterio -> Occupied in ascendent way (using criteria weight*volume)
     * Third crirterio -> Not Occupied in descendent way (using criteria weight*volume)
     * @param estafetas  vector with estafetas
     */
    void sortEstafetas(vector<Estafeta> & estafetas);

    /**
     * minimize the number of Estafetas to deliver all orders or the largest number of orders in one day
     */
    void optimizationEstafeta(int choose);

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
     * print every Estafeta in vector estafetas
     */
    void seeExpressOrders();

    /**
     * Count the number of Estafetas Ocuppied and print that
     * @return
     */
    void numberEstafetasOccupied();

    /**
     * Erases orders from expressOrders vector with duration optimized
     */
    void setExpressOrders();

    /**
     * Search for the Estafeta in estafetas by estafeta id and print the Estafeta orders
     */
    void searchEstafeta();

    /**
     * Tell user if want to choose another Estafeta
     */
    void auxSearchEstafeta();

    /**
     * Sort orders using the formula ((Weight*Volume)/Reward)
     * @param order1
     * @param order2
     * @return
     */
    static bool sortOrdersProfit(const Order &order1, const Order &order2);

    /**
     * Order the Estafetas by
     * 1st the using the Estafeta parameter Occupied
     * if Estafetas are not ocuppied (descending order using the formula ((FreeWeight*FreeVolume)/Cost))
     * if Estafetas are ocuppied (ascending order using the formula ((FreeWeight*FreeVolume)/Cost))
     * @param estafeta1
     * @param estafeta2
     * @return
     */
    static bool sortEstafetasProfit( Estafeta &estafeta1,  Estafeta &estafeta2);
    /**
     * Calculate the profit in these day
     */
    void profit();


private:
    vector<Order> storage;
    vector<Order> originalstorage;
    vector<Order> expressOrders;
    Estafeta express = Estafeta(0, 5000, 5000, 1000);
    vector<Estafeta> estafetas;
    vector<Estafeta> originalestafetas;
    int estafetaId = 1;
    int orderID = 1;
    bool stateApplication=true;
};


#endif //UNTITLED_APPLICATION_H
