//
// Created by Luís  Paiva on 14/04/2022.
//

#include "Order.h"

Order::Order(int Id, int volume, int weight, int reward, int duration) : Id(Id), volume(volume), weight(weight), reward(reward), duration(duration){}

int Order::getDuration() const {
    return duration;
}
