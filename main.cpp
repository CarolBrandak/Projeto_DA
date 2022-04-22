#include <iostream>
#include "Application.h"

int main() {
    Application app;
    app.readFile("encomendas1.txt");
    app.readFile("carrinhas1.txt");
    app.readFile("encomendasexpress1.txt");
    app.initialMenu();

    return 0;
}
