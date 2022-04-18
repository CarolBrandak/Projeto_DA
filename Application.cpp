
#include "Application.h"

Application::Application() = default;

void Application::test() {

    for(auto x: estafetas){
        cout<<x.getId()<<"-->"<<x.getVolumeMax()<<"--"<<x.getWeightMax()<<endl;
        cout<<x.getId()<<"-->"<<x.getfreeVolume()<<"--"<<x.getfreeWeight()<<endl<<endl;
        for(auto i : x.getEstafetaOrders()){
            cout<<x.getId()<<"-->"<<i.getVolume()<<"--"<<i.getWeight()<<endl;
        }
        cout<<endl;
    }
}

void Application::initialMenu() {
    int choose;
    cout<< "----------------------------------------------------" <<endl;
    cout << "Choose an option:" << endl;
    cout<<"1. Create new Estafeta"<<endl;
    cout<<"2. Create new Order"<<endl;
    cout<<"3. Storage"<<endl;
    cout<<"4. Estafetas"<<endl;
    cout<<"5. Choose Opmization method"<< endl;
    cout<<"6. Search for estafeta ID"<<endl; // apresentar as encomendas que esse estafeta tem para esse dia
    cout<<"0. Exit"<<endl;
    std::cin>>choose;

    while(stateApplication){

        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout<<"Invalid option, enter again!\n\n";
            initialMenu();
            break;
        }

        switch (choose) {
            case 0:
                stateApplication=false;
                break;
            case 1:
                createNewEstafeta();
                break;
            case 2:
                createNewOrder();
                break;
            case 3:
                seeStorage();
                break;
            case 4:
                seeEstafetas();
                break;
            case 5:
                optimizationMenu();
                break;
            case 6:
                searchEstafeta();
            default:
                cout<<"Invalid option, enter again!\n\n";
                initialMenu();
                break;
        }
    }
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
        updateOrders(words);
    }
    if(type == "carrinhas.txt"){
        updateEstafetas(words);
    }
}

void Application::updateOrders(vector<string> words) { // word (volume / peso / recompensa /duração(s))
    Order order = Order(orderID, std::stoi(words[0]), std::stoi(words[1]), std::stoi(words[2]), std::stoi(words[3]));
    storage.push_back(order);
    orderID++;
}

void Application::updateEstafetas(vector<string> words) { // word (volMax / pesoMax / custo)
    Estafeta estafeta = Estafeta(estafetaId, std::stoi(words[0]), std::stoi(words[1]), std::stoi(words[2]));
    estafetas.push_back(estafeta);
    estafetaId++;
}

void Application::sortOrdersDesc(vector<Order> & storage) {
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
                if(storage[j].getWeight() < storage[j+1].getWeight()){
                    std::swap(storage[j],storage[j+1]);
                    swapped=true;
                }
            }
        }
        if(swapped==false)
            break;
    }
}

/*void Application::sortEstafetasDesc(vector<Estafeta> &estafetas) {
    int size = estafetas.size();
    bool swapped;

    for(int i = 0; i<size-1; i++){
        swapped=false;
        for(int j = 0; j< size-i-1; j++){
            if(estafetas[j].getfreeVolume() < estafetas[j+1].getfreeVolume()){
                std::swap(estafetas[j],estafetas[j+1]);
                swapped=true;
            }
            else if(estafetas[j].getfreeVolume() == estafetas[j+1].getfreeVolume()){
                if(estafetas[j].getfreeWeight() < estafetas[j+1].getfreeWeight()){
                    std::swap(estafetas[j],estafetas[j+1]);
                    swapped=true;
                }
            }
        }
        if(swapped==false){
            break;
        }
    }
}*/

void Application::sortEstafetas(vector<Estafeta> &estafetas) {
    int size = estafetas.size();
    bool swapped;
    for(int i = 0; i<size-1; i++){
        swapped=false;
        for(int j = 0; j< size-i-1; j++){
            if(!estafetas[j].isOccupied() && estafetas[j+1].isOccupied()){
                std::swap(estafetas[j],estafetas[j+1]);
                swapped=true;
            }
            else if(estafetas[j].isOccupied() && estafetas[j+1].isOccupied()){
                if(estafetas[j].getfreeVolume() > estafetas[j+1].getfreeVolume()){
                    std::swap(estafetas[j],estafetas[j+1]);
                    swapped=true;
                }
                else if(estafetas[j].getfreeVolume() == estafetas[j+1].getfreeVolume()) {
                    if (estafetas[j].getfreeWeight() > estafetas[j + 1].getfreeWeight()) {
                        std::swap(estafetas[j], estafetas[j + 1]);
                        swapped = true;
                    }
                }
            }
            else if(!estafetas[j].isOccupied() && !estafetas[j+1].isOccupied()){
                if(estafetas[j].getfreeVolume() < estafetas[j+1].getfreeVolume()){
                    std::swap(estafetas[j],estafetas[j+1]);
                    swapped=true;
                }
                else if(estafetas[j].getfreeVolume() == estafetas[j+1].getfreeVolume()) {
                    if (estafetas[j].getfreeWeight() < estafetas[j + 1].getfreeWeight()) {
                        std::swap(estafetas[j], estafetas[j + 1]);
                        swapped = true;
                    }
                }
            }
        }
        if(swapped==false){
            break;
        }
    }

    /*for(auto x : estafetas){
        cout<<"ID:"<<x.getId()<<"  Ocupado:"<<x.isOccupied()<<"  volume max:"<<x.getVolumeMax()<<" peso max:"<<x.getWeightMax()<<"  volume livre:"<<x.getfreeVolume()<<" peso livre:"<<x.getfreeWeight()<<endl;
        for(auto i: x.getEstafetaOrders()) {
            cout << "encomendas:" << endl;
            cout << "ID:" << i.getId() << "  volume:" << i.getVolume() << " peso:" << i.getWeight()<<endl;
        }
        cout<<endl;
    }*/
    //cout<<endl;

}

void Application::optimizationMenu() {
    int choose;
    cout<< "Choose a way to optimize:"<<endl;
    cout<< "1. Optimization by estafetas"<<endl;
    cout<< "2. Optimization by reward"<<endl;
    cout<<"0. Initial Menu"<<endl;
    std::cin>>choose;

    switch (choose) {
        case 1:
            sortOrdersDesc(storage);
            sortEstafetas(estafetas);
            optimizationEstafeta();
            numberEstafetasOccupied();
            //test();
        case 0:
            initialMenu();
            break;
        default:
            cout<<"Invalid option, enter aaagain!\n\n";
            optimizationMenu();
            break;
    }
}

void Application::optimizationEstafeta() {
    int j=0;
    int newVolume,newWeight,newFreeTime;
    for(int i = 0; i< storage.size();i++){
        while( j!=estafetas.size()){
            newFreeTime=estafetas[j].getFreetime()-storage[i].getDuration();
            if(estafetas[j].getfreeVolume()>=storage[i].getVolume() && estafetas[j].getfreeWeight()>=storage[i].getWeight() && newFreeTime>=0){
                if(!estafetas[j].isOccupied())
                    estafetas[j].setOccupied(true);

                estafetas[j].setFreetime(newFreeTime);

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
}

void Application::seeStorage() {
    for(auto x: storage){
        cout<<"ID:"<<x.getId()<<"  Volume:"<<x.getVolume()<<"  Weight:"<<x.getWeight()<<"  Reward:"<<x.getReward()<<"  Duration(seg):"<<x.getDuration()<<endl;
    }
    cout<<endl;
    initialMenu();
}

void Application::seeEstafetas(){
    for(auto x: estafetas){
        cout<<"ID:"<<x.getId()<<"  Volume MAX:"<<x.getVolumeMax()<<"  Weight MAX:"<<x.getWeightMax()<<endl;
    }
    cout<<endl;
    initialMenu();
}

void Application::createNewEstafeta() {
    //Estafeta(int id,int volMax,int weightMax, int cost);
    int volMax,weightMax,cost;
    cout<<"Enter your Van max volume:";
    std::cin>>volMax;
    cout<<"\nEnter your Van max Weight:";
    std::cin>>weightMax;
    cout<<"\nEnter your cost:";
    std::cin>>cost;

    Estafeta estafeta = Estafeta(estafetaId,volMax,weightMax,cost);
    estafetaId++;
    estafetas.push_back(estafeta);
    initialMenu();
}

void Application::createNewOrder() {
    //Estafeta(int id,int volMax,int weightMax, int cost);
    int volume,weight,reward,duration;
    cout<<"Enter your Order volume:";
    std::cin>>volume;
    cout<<"\nEnter your Order Weight:";
    std::cin>>weight;
    cout<<"\nEnter your Order reward:";
    std::cin>>reward;
    cout<<"\nEnter your Order duration:";
    std::cin>>duration;

    Order order = Order(orderID,volume,weight,reward,duration);
    orderID++;
    storage.push_back(order);
    initialMenu();
}

int Application::numberEstafetasOccupied() {
    int count=0;
    for(auto x: estafetas){
        if(x.isOccupied())
            count++;
    }
    cout<<"Will be used "<<count<<" Estafetas"<<endl;
    return count;
}

void Application::searchEstafeta() {
    int id; char choose;
    cout <<"Estafeta ID:";
    std::cin>>id;
    cout<<"Encomendas --> Estafeta ID:"<<id<<endl;
    for(auto x: estafetas){
        if(x.getId()==id){
            if(x.getEstafetaOrders().empty()){
                cout<<"No orders to deliver."<<endl;
                break;
            }
            else{
                for(auto i: x.getEstafetaOrders())
                    cout << "ID:" << i.getId() << "  volume:" << i.getVolume() << " peso:" << i.getWeight()<<endl;
            }
        }
    }
    auxSearchEstafeta();
}

void Application::auxSearchEstafeta() {
    char choose;
    cout<<"Search for another Estafeta?(y/n)";
    std::cin>>choose;
    if (choose == 'y'){
        searchEstafeta();
    }
    else{
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        initialMenu();
    }
}

/*
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
}*/

