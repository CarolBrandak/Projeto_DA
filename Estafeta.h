#ifndef UNTITLED_ESTAFETA_H
#define UNTITLED_ESTAFETA_H


class Estafeta {
public:
    Estafeta(int id,int volMax,int weightMax, int cost);

    int getId() const;

    int getEngagedVolume() const;

    void setEngagedVolume(int engagedVolume);

    int getEngagedWeight() const;

    void setEngagedWeight(int engagedWeight);

    int getVolumeMax() const;

    int getWeightMax() const;

private:
    int id;
    int volumeMax;
    int engagedVolume=0;
    int weightMax;
    int engagedWeight=0;
    int cost;
};

#endif //UNTITLED_ESTAFETA_H
