//
// Created by Luís  Paiva on 14/04/2022.
//

#ifndef UNTITLED_ORDER_H
#define UNTITLED_ORDER_H


class Order {
public:
    /**
     *
     * @param Id Order ID
     * @param volume Order Volume
     * @param weight Order weight
     * @param reward Order reward
     * @param duration Order duration
     */
    Order(int Id, int volume, int weight, int reward, int duration);

    /**
     *
     * @return Order Id
     */
    int getId() const {
        return Id;
    }

    /**
     *
     * @return Order weight
     */
    int getWeight() const {
        return weight;
    }

    /**
     *
     * @return Order Volume
     */
    int getVolume() const {
        return volume;
    }

    /**
     *
     * @return Order reward
     */
    int getReward() const {
        return reward;
    }

    /**
     *
     * @return Order Duration
     */
    int getDuration() const;



private:
    int Id;
    int volume;
    int weight;
    int reward;
    int duration;

};


#endif //UNTITLED_ORDER_H
