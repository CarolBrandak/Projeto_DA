#include <iostream>
#include "Application.h"

int main() {
    Application app;
    app.readFile("encomendas.txt");
    app.readFile("carrinhas.txt");
    app.initialMenu();

    return 0;
}
