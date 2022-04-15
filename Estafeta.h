#ifndef UNTITLED_ESTAFETA_H
#define UNTITLED_ESTAFETA_H
#include "vector"
#include "Order.h"

class Estafeta {
public:

    Estafeta(int id,int volMax,int weightMax, int cost);

    int getId() const;

    int getfreeVolume() const;

    int getCost() const;

    void setfreeVolume(int freeVolume);

    int getfreeWeight() const;

    void setfreeWeight(int freeWeight);

    int getVolumeMax() const;

    int getWeightMax() const;

    void addEstafetaOrder(Order order);

    const std::vector<Order> &getEstafetaOrders() const;

private:
    int id;
    int volumeMax;
    int freeVolume;
    int weightMax;
    int freeWeight;
    int cost;
    std::vector<Order> estafetaOrders;

};

#endif //UNTITLED_ESTAFETA_H
