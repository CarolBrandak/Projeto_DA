
#include "Application.h"
#include "Estafeta.h"

Application::Application() = default;

void Application::test() {
    for(auto x: estafetas){
        cout<<x.getVolumeMax()<<"--"<<x.getWeightMax()<<endl;
    }
}

void Application::initialMenu() {
    readFile("encomendas.txt");
    readFile("carrinhas.txt");
    sortOrders(storage);
    sortEstafetas(estafetas);
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
    Order order{};
    order.volume= std::stoi(words[0]);
    order.weight= std::stoi(words[1]);
    order.reward= std::stoi(words[2]);
    order.duration= std::stoi(words[3]);

    storage.push_back(order);
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
            if(storage[j].volume < storage[j+1].volume){
                std::swap(storage[j],storage[j+1]);
                swapped=true;
            }
            else if(storage[j].volume == storage[j+1].volume){
                if(storage[j].weight< storage[j+1].weight){
                    std::swap(storage[j],storage[j+1]);
                    swapped=true;
                }
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
            if(estafetas[j].getVolumeMax() > estafetas[j+1].getVolumeMax()){
                std::swap(estafetas[j],estafetas[j+1]);
                swapped=true;
            }
            else if(estafetas[j].getVolumeMax() == estafetas[j+1].getVolumeMax()){
                if(estafetas[j].getWeightMax() > estafetas[j+1].getWeightMax()){
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