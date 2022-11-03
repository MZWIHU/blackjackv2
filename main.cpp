#include <iostream>
#include "cards.h"
#include "deck.h"
int main() {


    int input = 0;
    int hand = 0;
    int loss = 0;
    int win = 0;

    std::cout << "Mit wie vielen Decks wollen Sie spielen? Default = 2" << std::endl;
    std::cin >> input;
    if (input == 0) {
        input = 2;
    }


    Deck d;


    for (int k = 0; k < input - 1; k++) {

        Deck temp;
        d.stack.insert(d.stack.end(), temp.stack.begin(), temp.stack.end());

    }
    d.printDeck();
    std::cout << std::endl << std::endl;
    d.shuffle();

    for (int i = 0; i < d.stack.size(); i++) {
        std::cout << "You have drawn: " << d.stack.at(i).toString(d.stack.at(i).c, d.stack.at(i).n) << std::endl;

        switch (d.stack.at(i).n) {

            case Card::ace:
                if (hand > 10) {
                    hand +=1;
                } else {
                    hand +=11;
                }
                break;
            case Card::two:
                hand+=2;
                break;
            case Card::three:
                hand+=3;
                break;
            case Card::four:
                hand+=4;
                break;
            case Card::five:
                hand+=5;
                break;
            case Card::six:
                hand+=6;
                break;
            case Card::seven:
                hand+=7;
                break;
            case Card::eight:
                hand+=8;
                break;
            case Card::nine:
                hand+=9;
                break;
            case Card::ten:
                hand+=10;
                break;
            case Card::jack:
                hand+=10;
                break;
            case Card::queen:
                hand+=10;
                break;
            case Card::king:
                hand+=10;
                break;
        }

        if (hand <= 21 & hand >= 18) {
            win++;
            std::cout << "You won with: " << hand << std::endl << std::endl;
            hand = 0;

            if (i > d.stack.size() - 6) {
                break;
            }

        }
        if (hand > 21) {
            loss++;
            std::cout << "You lost with: " << hand << std::endl << std::endl;
            hand = 0;
        }


    }

    std::cout << "You won " << win << " times :)" << std::endl;
    std::cout << "You lost " << loss << " times :(" << std::endl;


    return 0;

}