//
// Created by Chanuka Abeysinghe on 2021-10-05.
//

#ifndef POKERCARDGAME_CARD_H
#define POKERCARDGAME_CARD_H

#include <iostream>
#include <stdlib.h>

using namespace std;

class Card {
private:
    string shape;
    string value;
    int valueOfCard;
public:
    Card(){}
    Card(string s, string v,int vOfCard){
        shape=s;
        value=v;
        valueOfCard = vOfCard;
    }

    string getShape(){return shape;}
    string getValue(){return value;}
    int getValueOfCard(){return valueOfCard;}

    void printCard(){
        cout<<shape<<" "<<value<<endl;
    }
};


#endif //POKERCARDGAME_CARD_H
