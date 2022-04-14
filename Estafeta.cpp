//
// Created by Luís  Paiva on 14/04/2022.
//

#include "Estafeta.h"

Estafeta::Estafeta(int id,int volMax,int weightMax, int cost) : id(id), volumeMax(volMax), weightMax(weightMax), cost(cost)  {}

int Estafeta::getId() const {
    return id;
}

int Estafeta::getEngagedVolume() const {
    return engagedVolume;
}

void Estafeta::setEngagedVolume(int engagedVolume) {
    Estafeta::engagedVolume = engagedVolume;
}

int Estafeta::getEngagedWeight() const {
    return engagedWeight;
}

void Estafeta::setEngagedWeight(int engagedWeight) {
    Estafeta::engagedWeight = engagedWeight;
}

int Estafeta::getVolumeMax() const {
    return volumeMax;
}

int Estafeta::getWeightMax() const {
    return weightMax;
}

