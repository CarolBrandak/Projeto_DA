
#include "Application.h"

Application::Application() = default;

void Application::test() {
    cout<<storage[2].volume<<endl;
    cout<<vans[5].cost<<endl;
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
        createNewVan(words);
    }
}

void Application::createNewOrder(vector<string> words) { // word (volume / peso / recompensa /duração(s))
    Order order{};
    order.volume= std::stoi(words[0]);
    order.wheight= std::stoi(words[1]);
    order.reward= std::stoi(words[2]);
    order.duration= std::stoi(words[3]);

    storage.push_back(order);
}

void Application::createNewVan(vector<string> words) { // word (volMax / pesoMax / custo)
    Van van{};
    van.volMax= std::stoi(words[0]);
    van.weightMax= std::stoi(words[1]);
    van.cost= std::stoi(words[2]);

    vans.push_back(van);
}