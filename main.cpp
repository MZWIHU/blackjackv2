#include <iostream>
#include "cards.h"
#include "deck.h"
int main() {


    int input = 0;
    char decide;
    int hand = 0;
    int dealerHand = 0;
    int loss = 0;
    int win = 0;
    int draw = 0;
    bool turn = true;
    int begin = 0;


    std::cout << "How many Decks? Default = 2" << std::endl;
    std::cin >> input;
    if (input == 0) {
        input = 2;
    }


    Deck d;

    //Deck erstellen -------------------------------------------------------------------------------------------------*/
    for (int k = 0; k < input - 1; k++) {

        Deck temp;
        d.stack.insert(d.stack.end(), temp.stack.begin(), temp.stack.end());

    }
    d.printDeck();
    std::cout << std::endl << std::endl;
    d.shuffle();


    //spielen---------------------------------------------------------------------------------------------------------*/


    for (int i = 0; i < d.stack.size(); i++) {

        if (begin < 2) {
            std::cout << "You have drawn: " << d.stack.at(i).toString(d.stack.at(i).c, d.stack.at(i).n) << std::endl;
            hand += d.checkValue(i, hand);
            begin++;
            continue;
        }

        if (begin == 2) {
            std::cout << "Dealer has drawn: " << d.stack.at(i).toString(d.stack.at(i).c, d.stack.at(i).n) << std::endl;
            dealerHand += d.checkValue(i, dealerHand);
            begin++;
            continue;
        }



        if (hand > 21) {
            loss++;
            std::cout << "You lost with: " << hand << std::endl << std::endl << std::endl;
            hand = 0;
            begin = 0;
            if (i > d.stack.size() - 6) {
                break;
            }
            continue;
        }

        if (turn) {


            std::cout << "Your Hand is: " << hand << std::endl;
            std::cout << "You want to draw a card Y or N" << std::endl;
            std::cin >> decide;

            switch (decide) {
                case 'y':
                    std::cout << "You have drawn: " << d.stack.at(i).toString(d.stack.at(i).c, d.stack.at(i).n)
                              << std::endl;
                    hand += d.checkValue(i, hand);
                    break;
                case 'n':
                    turn = false;
                    break;
                default:
                    std::cout << "Please enter valid option" << std::endl;
                    turn = false;
            }

        }else {
            if (dealerHand < 17) {
                std::cout << "Dealer has drawn: " << d.stack.at(i).toString(d.stack.at(i).c, d.stack.at(i).n)
                          << std::endl;
                dealerHand += d.checkValue(i, dealerHand);
                continue;
            }

            if (dealerHand > 21 && hand <= 21) {
                std::cout << "You won with: " << hand << " against " << dealerHand << std::endl << std::endl
                          << std::endl;
                win++;
                begin = 0;
                dealerHand = 0;
                hand = 0;
                turn = true;
                if (i > d.stack.size() - 6) {
                    break;
                }
                continue;
            }
            if (hand < dealerHand) {
                std::cout << "You lost with: " << hand << " against " << dealerHand << std::endl << std::endl
                          << std::endl;
                loss++;
                begin = 0;
                dealerHand = 0;
                hand = 0;
                turn = true;
                if (i > d.stack.size() - 6) {
                    break;
                }
                continue;
            }

            if (hand > dealerHand) {
                std::cout << "You won with: " << hand << " against " << dealerHand << std::endl << std::endl
                          << std::endl;
                win++;
                begin = 0;
                dealerHand = 0;
                hand = 0;
                turn = true;
                if (i > d.stack.size() - 6) {
                    break;
                }
                continue;
            }
            if (hand == dealerHand) {
                std::cout << "Draw! Your hand: " << hand << " Dealer: " << dealerHand << std::endl << std::endl
                          << std::endl;
                begin = 0;
                dealerHand = 0;
                hand = 0;
                turn = true;
                draw++;
                if (i > d.stack.size() - 6) {
                    break;
                }
                continue;
            }

        }
    }
    std::cout << "You won " << win << " times :)" << std::endl;
    std::cout << "You lost " << loss << " times :(" << std::endl;
    std::cout << "Draw: " << draw << " times :|" << std::endl;


    return 0;

}