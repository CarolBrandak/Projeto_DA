//
// Created by Luís  Paiva on 14/04/2022.
//

#ifndef UNTITLED_ORDER_H
#define UNTITLED_ORDER_H


class Order {
public:
    Order(int Id, int volume, int weight, int reward, int duration);

    int getId() const {
        return Id;
    }

    int getWeight() const {
        return weight;
    }

    int getVolume() const {
        return volume;
    }

    int getReward() const {
        return reward;
    }

    int getDuration() const;

private:
    int Id;
    int volume;
    int weight;
    int reward;
    int duration;

};


#endif //UNTITLED_ORDER_H
