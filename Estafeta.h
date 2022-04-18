#ifndef UNTITLED_ESTAFETA_H
#define UNTITLED_ESTAFETA_H
#include "vector"
#include "Order.h"

class Estafeta {
public:

    Estafeta(int id,int volMax,int weightMax, int cost);

    int getId() const;

    int getfreeVolume() const;

    void setfreeVolume(int freeVolume);

    int getfreeWeight() const;

    void setfreeWeight(int freeWeight);

    int getVolumeMax() const;

    int getWeightMax() const;

    void addEstafetaOrder(Order order);

    int getCost() const;

    const std::vector<Order> &getEstafetaOrders() const;

    bool isOccupied() const;

    void setOccupied(bool occupied);

    int getFreetime() const;

    void setFreetime(int freetime);

private:
    int id;
    int volumeMax;
    int freeVolume;
    int weightMax;
    int freeWeight;
    int cost;
    bool occupied = false;
    int freetime = 8*3600;  // Assuming the Estafeta works 8 hours a day
    std::vector<Order> estafetaOrders;

};

#endif //UNTITLED_ESTAFETA_H
