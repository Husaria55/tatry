#include "Graph.h"

int main() {
    Graph tatry;

    std::cout << "Wczytywanie szlakow Tatrzanskich...\n";
    if (!tatry.loadFromJson("szlaki.json")) {
        return 1;
    }

    int choice = 0;
    while (choice != 3) {
        std::cout << "\n--- NAWIGACJA TATRZANSKA ---\n";
        std::cout << "1. Pokaz wszystkie trasy i czasy z bazy\n";
        std::cout << "2. Znajdz najszybsza trase (w budowie)\n";
        std::cout << "3. Wyjscie\n";
        std::cout << "Wybierz opcje: ";

        std::cin >> choice;

        if (choice == 1) {
            tatry.printGraph();
        } else if (choice == 2) {
            std::cout << "\nAlgorytm szukania sciezki pojawi sie tutaj!\n";
        } else if (choice != 3) {
            std::cout << "\nNieznana opcja. Sprobuj ponownie.\n";
        }
    }

    std::cout << "Do zobaczenia na szlaku!\n";
    return 0;
}