//
// Created by Chanuka Abeysinghe on 2021-10-05.
//

#ifndef POKERCARDGAME_DEALER_H
#define POKERCARDGAME_DEALER_H

#include <iostream>
#include <stdlib.h>
#include "Card.h"
#include "Player.h"

using namespace std;

class Dealer {
private:
    Card cardsAfterRemoving[50];
    int id;
    Card  cards[5];
    int score;
public:
    Dealer(){}

    Dealer(int i){
        id = i;
        score=0;
    }

    void setCards(Card c[5]){
        for(int i=0;i<5;i++){
            Card card = c[i];
            cards[i] = card;
        }
    }

    void setScore(int s){score = s;}
    Card*  getCards(){return cards;}
    int getScore(){return score;}
    int getId(){return id;}

    // This function is to get the card set at the beginning
    Card* initiateCardSet(){
        static int arr[10] = {5,4,6,223,44,55,64,444,55,5};
        static Card cards[52];
        int counter=0;
        for(int i=2;i<11;i++){
            // Put all the cards from 1 -to 10
            Card card1("Spade", to_string(i),i);
            Card card2("Diamond", to_string(i),i);
            Card card3("Heart", to_string(i),i);
            Card card4("Club", to_string(i),i);
            cards[counter++] = card1;
            cards[counter++] = card2;
            cards[counter++] = card3;
            cards[counter++] = card4;
        }

        Card card1("Spade","J",11),card2("Spade","Q",12), card3("Spade","K",13),card4("Spade","A",14);
        Card card5("Diamond","J",11),card6("Diamond","Q",12),card7("Diamond","K",13),card8("Diamond","A",14);
        Card card9("Heart","J",11),card10("Heart","Q",12),card11("Heart","K",13),card12("Heart","A",14);
        Card card13("Club","J",11),card14("Club","Q",12),card15("Club","K",13),card16("Club","A",14);

        cards[counter++] = card1;cards[counter++] = card2;cards[counter++] = card3;cards[counter++] = card4;
        cards[counter++] = card5;cards[counter++] = card6;cards[counter++] = card7;cards[counter++] = card8;
        cards[counter++] = card9;cards[counter++] = card10;cards[counter++] = card11;cards[counter++] = card12;
        cards[counter++] = card13;cards[counter++] = card14;cards[counter++] = card15;cards[counter++] = card16;

        return cards;
    }

    // This function is to shuffle and remove two cards  from the cards set
    void shuffleCards(){
        Card *cardSet;
        Card cards[52];

        cardSet = initiateCardSet();

        int count=0,i=0;
        int isBlank[52] = {0};

        for(int i=0;i<52;i++){
            isBlank[i]=0;
        }

        srand(std::time(0));

        while(count<52){
            int randomNumber = rand()%52;
            if(isBlank[randomNumber]==0){
                Card card = cardSet[count];
                cards[randomNumber] =card;
                isBlank[randomNumber]=1;
                count++;
            }
        }

        // Remove first two cards
        int j =0;
        for(int i=2;i<52;i++){
            Card card = cards[i];
            cardsAfterRemoving[j] = card;
            j++;
        }
    }

    void distributeCards(Player players[9]){
        int count=0;
        for(int i=0;i<9;i++){
            Card *cardsPtr;
            Card cards[5];
            cout<<endl<<"=========================================="<<endl;
            cout<<"Delivering Cards To Player "<<players[i].getId()<<endl;
            cout<<"=========================================="<<endl;
            for(int j=0;j<5;j++){
                Card card = cardsAfterRemoving[count];
                cards[j] = card;
                count++;
            }
            print(cards,5);
            cardsPtr = cards;
            players[i].setCards(cardsPtr);
            cout<<endl<<"=========================================="<<endl;
        }

        cout<<endl<<"=========================================="<<endl;
        cout<<"Delivering Cards To Dealer "<<getId()<<endl;
        cout<<"=========================================="<<endl;
        Card *cardsPtr;
        Card cards[5];
        for(int j=0;j<5;j++){
            Card card = cardsAfterRemoving[count];
            cards[j] = card;
            count++;
        }
        print(cards,5);
        cardsPtr = cards;
        setCards(cardsPtr);
        cout<<endl<<"=========================================="<<endl;
    }

    // This function is to print the card set
    void print(Card *cards,int size){
        for(int i=0;i<size;i++){
            cout<<i<<" : ";
            cards[i].printCard();
        }
    }

};


#endif //POKERCARDGAME_DEALER_H
