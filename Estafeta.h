#ifndef UNTITLED_ESTAFETA_H
#define UNTITLED_ESTAFETA_H
#include "vector"
#include "Order.h"

class Estafeta {
public:
    /**
     *
     * @param id Estafeta ID
     * @param volMax Max volume that the Estafeta can curry
     * @param weightMax  Max weight that the Estafeta can curry
     * @param cost the price the Estafeta charges to place the order
     */
    Estafeta(int id,int volMax,int weightMax, int cost);
    /**
     *
     * @return Estafeta ID
     */
    int getId() const;

    /**
     *
     * @return Free Volume
     */
    int getfreeVolume() const;

    /**
     * Set free Volume
     * @param freeVolume
     */
    void setfreeVolume(int freeVolume);

    /**
     *
     * @return  free Weight
     */
    int getfreeWeight() const;

    /**
     * Set free weight
     * @param freeWeight
     */
    void setfreeWeight(int freeWeight);

    /**
     *
     * @return Volume Max
     */
    int getVolumeMax() const;

    /**
     *
     * @return Weight Max
     */
    int getWeightMax() const;
    /**
     * Add new order to esatefetas orders
     * @param order New order
     */
    void addEstafetaOrder(Order order);
    /**
     *
     * @return Estafeta Cost
     */
    int getCost() const;

    /**
     *
     * @return The vector with Estafetas Orders
     */
    const std::vector<Order> &getEstafetaOrders() const;

    /**
     *
     * @return Esfeta is occupied
     */
    bool isOccupied() const;

    /**
     * Change the status of estafeta (is or not occupied)
     * @param occupied
     */
    void setOccupied(bool occupied);

    /**
     *
     * @return Estafeta Free Time
     */
    int getFreetime() const;

    /**
     * Set estafeta Free time
     * @param freetime
     */
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
    std::vector<Order> estafetaOrders; // Vector with Estafeta Orders

};

#endif //UNTITLED_ESTAFETA_H
