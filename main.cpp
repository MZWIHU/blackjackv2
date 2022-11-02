#include <iostream>
#include "cards.h"
#include "deck.h"
int main() {




    int input = 0;

    std::cout << "Mit wie vielen Decks wollen Sie spielen? Default = 2" << std::endl;
    std::cin >> input;



    Deck d;


    for (int k = 0; k < input - 1; k++) {

        Deck temp;
        d.stack.insert(d.stack.end(), temp.stack.begin(), temp.stack.end());

    }
    d.printDeck();
    d.shuffle();

    return 0;
}
