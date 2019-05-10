#include "Player.h"

void Player::setHandWithWinPile(){
  // hand=winPile;
  for(int i=0;i<winPile.size();i++){
    hand.push_back(winPile.at(i));
  }
  winPile.clear();
}

void Player::addToPile(const std::vector<int>& pileIn){
  for(int i=0;i<pileIn.size();i++){
    winPile.push_back(pileIn.at(i));
  }
  // winPile=pileIn;
}

void Player::setHand(const std::vector<int>& handIn){
  hand=handIn;
}

void Player::setCardToPlay(int index){
  cardToPlay=index;
}

std::vector<int>& Player::getHand(){
  return hand;
}

std::vector<int>& Player::getPile(){
  return winPile;
}

int Player::getCardToPlay(){
  return cardToPlay;
}