#include <iostream>
#include "Application.h"

int main() {
    Application app;
    app.readFile("encomendas.txt");
    app.readFile("carrinhas1.txt");
    app.initialMenu();

    return 0;
}
