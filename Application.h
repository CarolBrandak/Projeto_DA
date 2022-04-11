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

class Application {
public:
    Application();
    void readFile(const string& fileName);
    void splitWord(const string& line, const string& type);
    void createNewOrder(vector<string> words);
    void createNewVan(vector<string> words);

    void test();

private:
    struct Order{
        int volume;
        int wheight;
        int reward;
        int duration;
    };

    struct Van{
        int volMax;
        int weightMax;
        int cost;
    };

    vector<Order> storage;
    vector<Van> vans;
};


#endif //UNTITLED_APPLICATION_H
