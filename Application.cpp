
#include "Application.h"

Application::Application() = default;

//void Application::initialMenu() {
//}

void Application::readOrders() {
    ifstream file("encomendas.txt");
    string line;
    if(!file.is_open()){
        cerr<<"ERROR: file could not be open"<<endl;
        return;
    }
    getline(file, line);
    while(getline(file,line)){
        splitWord(line,"Order");
    }

    for(auto x : storage){
        cout<<x.wheight<<endl;
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
    if(type == "Order"){
        createNewOrder(words);
    }
}

void Application::createNewOrder(vector<string> words) { // word (volume / peso / recompensa /duração(s))
    Order order{};
    order.volume=std::stoi(words[0]);
    order.wheight= std::stoi(words[1]);
    order.reward= std::stoi(words[2]);
    order.duration= std::stoi(words[3]);

    storage.push_back(order);
}