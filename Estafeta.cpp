//
// Created by Luís  Paiva on 14/04/2022.
//

#include "Estafeta.h"


Estafeta::Estafeta(int id,int volMax,int weightMax, int cost) : id(id), volumeMax(volMax), weightMax(weightMax), cost(cost), freeVolume(volMax), freeWeight(weightMax)  {}

int Estafeta::getId() const {
    return id;
}

int Estafeta::getfreeVolume() const {
    return freeVolume;
}

int Estafeta::getCost() const {
    return cost;
}

void Estafeta::setfreeVolume(int freeVolume) {
    Estafeta::freeVolume = freeVolume;
}

int Estafeta::getfreeWeight() const {
    return freeWeight;
}

void Estafeta::setfreeWeight(int freeWeight) {
    Estafeta::freeWeight = freeWeight;
}

int Estafeta::getVolumeMax() const {
    return volumeMax;
}

int Estafeta::getWeightMax() const {
    return weightMax;
}

void Estafeta::addEstafetaOrder(Order order) {
    estafetaOrders.push_back(order);
}

const std::vector<Order> &Estafeta::getEstafetaOrders() const {
    return estafetaOrders;
}


