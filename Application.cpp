
#include "Application.h"

Application::Application() = default;

void Application::test() {
    cout<<"Profit:"<< profit <<endl;
    for(auto x: estafetas){
        cout << "Volume maximo e peso maximo estafeta: " << endl;
        cout<<x.getId()<<"-->"<<x.getVolumeMax()<<"--"<<x.getWeightMax()<<endl;
        cout << "Volume restante e peso restante estafeta: " << endl;
        cout<<x.getId()<<"-->"<<x.getfreeVolume()<<"--"<<x.getfreeWeight()<<endl;
        cout << "Orders: " << endl;
        for(auto i : x.getEstafetaOrders()){
            cout<<x.getId()<<"-->"<<i.getVolume()<<"--"<<i.getWeight()<<endl;
        }
        cout<<endl;
    }

    cout<<"Encomendas restantes:" <<endl;
    for (auto j: storage) {
        cout<<j.getId()<<"-->"<<j.getVolume()<<"--"<<j.getWeight()<<endl;
    }
}

void Application::initialMenu() {
    readFile("encomendas.txt");
    readFile("carrinhas.txt");
    //Ordenar por estafetas
    sortOrders(storage);
    sortEstafetas(estafetas);
    /*//Ordenar por profit(não otimizado)
    sortOrdersReward(storage);
    sortEstafetasCost(estafetas);*/
    orderstoEstafetas();
    setProfit();
    test();
}

void Application::readFile(const string& fileName) {
    ifstream file(fileName);
    string line;
    if(!file.is_open()){
        cerr<<"ERROR: file could not be open"<<endl;
        return;
    }
    getline(file, line);
    while(getline(file,line)){
        splitWord(line,fileName);
    }
}


void Application::splitWord(const string& line, const string& type) {
    char del = ' ';
    string word;
    vector<string> words;
    for(auto i: line){
        if(i == del){
            words.push_back(word);
            word="";
        }
        else word+=i;
    }
    words.push_back(word);
    if(type == "encomendas.txt"){
        createNewOrder(words);
    }
    if(type == "carrinhas.txt"){
        createNewEstafeta(words);
    }
}

void Application::createNewOrder(vector<string> words) { // word (volume / peso / recompensa /duração(s))
    Order order = Order(orderID, std::stoi(words[0]), std::stoi(words[1]), std::stoi(words[2]), std::stoi(words[3]));
    storage.push_back(order);
    orderID++;
}

void Application::createNewEstafeta(vector<string> words) { // word (volMax / pesoMax / custo)
    Estafeta estafeta = Estafeta(estafetaId, std::stoi(words[0]), std::stoi(words[1]), std::stoi(words[2]));
    estafetas.push_back(estafeta);
    estafetaId++;
}

void Application::sortOrders(vector<Order> & storage) {
    int size = storage.size();
    bool swapped;
    for(int i = 0; i<size-1;i++){
        swapped=false;
        for(int j = 0; j < size-i-1; j++)
        {
            if(storage[j].getVolume() < storage[j+1].getVolume()){
                std::swap(storage[j],storage[j+1]);
                swapped=true;
            }
            else if(storage[j].getVolume() == storage[j+1].getVolume()){
                if(storage[j].getWeight()< storage[j+1].getWeight()){
                    std::swap(storage[j],storage[j+1]);
                    swapped=true;
                }
            }
        }
        if(swapped==false)
            break;
    }
}

void Application::sortOrdersReward(vector<Order> &storage) {
    int size = storage.size();
    bool swapped;
    for(int i = 0; i<size-1;i++){
        swapped=false;
        for(int j = 0; j < size-i-1; j++)
        {
            if(storage[j].getReward() > storage[j+1].getReward()){
                std::swap(storage[j],storage[j+1]);
                swapped=true;
            }
        }
        if(swapped==false)
            break;
    }
}

void Application::sortEstafetas(vector<Estafeta> &estafetas) {
    int size = estafetas.size();
    bool swapped;

    for(int i = 0; i<size-1; i++){
        swapped=false;
        for(int j = 0; j< size-i-1; j++){
            if(estafetas[j].getfreeVolume() > estafetas[j+1].getfreeVolume()){
                std::swap(estafetas[j],estafetas[j+1]);
                swapped=true;
            }
            else if(estafetas[j].getfreeVolume() == estafetas[j+1].getfreeVolume()){
                if(estafetas[j].getfreeWeight() > estafetas[j+1].getfreeWeight()){
                    std::swap(estafetas[j],estafetas[j+1]);
                    swapped=true;
                }
            }
        }
        if(swapped==false){
            break;
        }
    }
}

void Application::sortEstafetasCost(vector<Estafeta> &estafetas) {
    int size = estafetas.size();
    bool swapped;

    for(int i = 0; i<size-1; i++){
        swapped=false;
        for(int j = 0; j< size-i-1; j++){
            if(estafetas[j].getCost() > estafetas[j+1].getCost()){
                std::swap(estafetas[j],estafetas[j+1]);
                swapped=true;
            }
        }
        if(swapped==false){
            break;
        }
    }
}

void Application::orderstoEstafetas() {
    int j=0;
    int newVolume,newWeight;

    //while(!storage.empty()){
        for(int i = 0; i< storage.size();i++){
            while( j!=estafetas.size()){
                if(estafetas[j].getfreeVolume()>=storage[i].getVolume() && estafetas[j].getfreeWeight()>=storage[i].getWeight()){
                    newVolume=estafetas[j].getfreeVolume()-storage[i].getVolume();
                    estafetas[j].setfreeVolume(newVolume);

                    newWeight=estafetas[j].getfreeWeight()-storage[i].getWeight();
                    estafetas[j].setfreeWeight(newWeight);

                    estafetas[j].addEstafetaOrder(storage[i]);

                    storage.erase(storage.begin()+i);

                    sortEstafetas(estafetas);

                    j=0;
                    i--;
                    break;
                }
            j++;
            }
            j=0;
        }
    //}
}

void Application::setProfit(){
    profit=0;
    for (auto x: estafetas) {
        if(x.getEstafetaOrders().size()!=0){
            profit-=x.getCost();
            for(auto i: x.getEstafetaOrders()){
                profit+=i.getReward();
            }
        }
    }
}
