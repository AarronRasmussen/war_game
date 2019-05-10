// #include <iostream>
// #include <sstream>
// #include <time.h>
// #include <vector>
// #include "Player.h"
// 
// 
// // std::vector<int> OURDECK = {1,1,1,1,1,1,2,2,2,3,3,3,3,3,3,3,4,4,4,4,4,5,5,
// // 5,5,5,5,6,6,6,6,6,6,6,6,7,7,7,7,7,7,
// // 8,8,8,8,8,8,9,9,9,9,9,10,10,10,10};
// // std::vector<int> OURDECK={1,1,1,2,2,3,3,3,4,4,5,5,5,5,6,6};
// std::vector<int> DECK = {1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,
// 11,11,11,11,12,12,12,12,13,13,13,13};
// 
// 
// 
// void printCards(std::vector<int>& cards){
//   for(int i=0;i<cards.size();i++){
//     std::cout<<cards[i]<<"\n";
//   }
// }
// 
// void shuffle(std::vector<int>& cards){
//   std::srand(time(NULL));
//   for(int i=0;i<100;i++){
//     int indexOne=rand()%cards.size();
//     int indexTwo=rand()%cards.size();
//     std::swap(cards[indexOne],cards[indexTwo]);
//   }
//   // printCards(OURDECK);
//   // std::cout<<"\n"<<OURDECK.size()<<" "<<OURDECK[55];
// }
// 
// void makeHands(std::vector<int>& handOne, std::vector<int>& handTwo, std::vector<int>& dealerDeck){
//   handOne.clear();
//   handTwo.clear();
//   for(int i=0;i<dealerDeck.size();i++){
//     if(i%2){//ODD NUMBERS
//       handTwo.push_back(dealerDeck[i]);
//     }else{//EVEN NUMBERS
//       handOne.push_back(dealerDeck[i]);
//     }
//   }
//   // printCards(handOne);
//   // std::cout<<"\n\n\n";
//   // printCards(dealerDeck);
//   // std::cout<<"\n\n\n";
//   // printCards(handTwo);
//   // std::cout<<"\n\n\n";
//   // printCards(dealerDeck);
//   
// }
// 
// int war(Player& p1, Player& p2, int winner){
//   // std::cout<<"\n\nwarwarwarwarwarwarwarwarwarwarwarwarwarwarwarwarwarwarwarwarwarwarwarwarwarwarwarwarwarwarwarwar\n\n";
//   std::vector<int> warWinnings;
//   // std::cout<<"\n\n-----------------------53------------------------\n\n";
//   if(p1.getHand().size()<5 ){
//     p1.setHandWithWinPile();
//     if(p1.getHand().size()<5){
//       winner=1;//p2 won
//     }
//   }
//   // std::cout<<"\n\n-----------------------60------------------------\n\n";
//   if(p2.getHand().size()<5){
//     p2.setHandWithWinPile();
//     p2.setCardToPlay(p2.getHand().size()-1);
//     if(p2.getHand().size()<5){
//       winner=0;//p1 won
//     }
//   }
//   // std::cout<<"\n\n-----------------------67------------------------\n\n";
//   if(winner==-1){
//     warWinnings.push_back(p1.getHand().at(p1.getCardToPlay()));//put p1 card in war winnings
//     warWinnings.push_back(p2.getHand().at(p2.getCardToPlay()));//put p2 car in war winnings
//     warWinnings.insert(warWinnings.end(),{p1.getHand().at(p1.getCardToPlay()+1),p1.getHand().at(p1.getCardToPlay()+2),p1.getHand().at(p1.getCardToPlay()+3)});//put three cards from p1 in war winnings
//     warWinnings.insert(warWinnings.end(),{p2.getHand().at(p2.getCardToPlay()-1),p2.getHand().at(p2.getCardToPlay()-2),p2.getHand().at(p2.getCardToPlay()-3)});//put three cards from p2 in war winnings
//     // std::cout<<"\n\n-----------------------72------------------------\n\n";
//     p1.getHand().erase(p1.getHand().begin(),p1.getHand().begin()+4);//erase four cards from beginning of p1
//     p2.getHand().erase(p2.getHand().begin()+p2.getHand().size()-4,p2.getHand().end());//erase four cards from end of p2
//     p2.setCardToPlay(p2.getHand().size()-1);
//     // std::cout<<"\n\n-----------------------76------------------------\n\n";
//     if(p1.getHand().at(p1.getCardToPlay())>p2.getHand().at(p2.getCardToPlay())){
//       //add winnings to p1 pile
//       p1.addToPile(warWinnings);
//     }else if(p1.getHand().at(p1.getCardToPlay())<p2.getHand().at(p2.getCardToPlay())){
//       //add winnings to p2 pile
//       p2.addToPile(warWinnings);
//     }else{
//       war(p1,p2,winner);
//     }
// }
// 
//   return winner;
// }
// 
// int compareOurCards(Player& p1, Player& p2,int winner){
//   int p1Card=p1.getHand().at(p1.getCardToPlay());
//   int p2Card=p2.getHand().at(p2.getCardToPlay());
//   std::vector<int> cards={p1Card,p2Card};
//   // std::cout<<"CARDS\n";
//   // printCards(cards);
//   
//   // std::cout<<"\nHANDS\nHANDONE";
//   // printCards(p1.getHand());
//   // std::cout<<"\n\n\n\nHANDTWO";
//   // printCards(p2.getHand());
//   // std::cout<<"\n\n\n\n";
//   
//   if(p1Card>p2Card){
//     //remove lost cards from p2 and put them into p1's pile
//     p1.getHand().erase(p1.getHand().begin());
//     p2.getHand().pop_back();
//     p2.setCardToPlay(p2.getHand().size()-1);
//     p1.addToPile(cards);
//     // printCards(p1.getHand());
//     // std::cout<<"\n\n\n\n";
//     // printCards(p2.getHand());
//   }
//   else if(p1Card<p2Card){
//     //remove lost cards from p1 and put them into p2's pile 
//     p1.getHand().erase(p1.getHand().begin());
//     p2.getHand().pop_back();
//     p2.setCardToPlay(p2.getHand().size()-1);
//     p2.addToPile(cards);
//     // printCards(p1.getHand());
//     // std::cout<<"\n\n\n\n";
//     // printCards(p2.getHand());
//     
//   }
//   else{
//     // std::cout<<"\n\nCARDS\n\n";
//     // printCards(cards);
//     winner=war(p1,p2,winner);
//     
//     //write war method here
//     // p1.getHand().erase(p1.getHand().begin());
//     // p2.getHand().pop_back();
//     // p2.setCardToPlay(p2.getHand().size()-1);
//   }
//   return winner;
// }
// 
// int startOurGame(Player& playerOne,Player& playerTwo){//player two play from bottom of hand and player one play from top of hand
//   int winner=-1;
//   // std::cout<<"---------------------------WINNER"<<winner<<"\n\n";
//   while (winner==-1) {
//     // std::cout<<"HANDONE\n\n";
//     // printCards(playerOne.getHand());
//     // std::cout<<"\n\n\n\n\nHANDTWO\n";
//     // printCards(playerTwo.getHand());
//     // std::cout<<"\n\n\n\n\n";
//     
//     winner=compareOurCards(playerOne,playerTwo,winner);
//     if(winner==-1){
//       if(playerOne.getHand().size()==0){
//         if(playerOne.getPile().size()==0){
//           winner=1;//if winner == 1 p2 won
//           // std::cout<<"WINNERP2 "<<winner<<"\n\n";
//         }else{
//           // std::cout<<"P1PILE\n\n";
//           // printCards(playerOne.getPile());
//           playerOne.setHandWithWinPile();
//           // std::cout<<"P1NEWHAND\n\n";
//           // printCards(playerOne.getHand());
//           playerOne.setCardToPlay(0);
//         }
//       }
//       if(playerTwo.getHand().size()==0){
//         if(playerTwo.getPile().size()==0){
//           winner=0;//if winner ==0 p1 won
//           // std::cout<<"WINNERP1 "<<winner<<"\n\n";
//         }else{
//           // std::cout<<"P2PILE\n\n";
//           // printCards(playerTwo.getPile());
//           playerTwo.setHandWithWinPile();
//           // std::cout<<"P2NEWHAND\n\n";
//           // printCards(playerTwo.getHand());
//           playerTwo.setCardToPlay(playerTwo.getHand().size()-1);
//         }
//       } 
//     } 
//   }
//   return winner;
// }
// 
// int ourGame(Player& p1, Player& p2){
//   shuffle(DECK);
//   makeHands(p1.getHand(),p2.getHand(),DECK);
//   // std::cout<<"HANDONE\n";
//   // printCards(p1.getHand());
//   // std::cout<<"HANDTWO\n";
//   // printCards(p2.getHand());
//   p1.setCardToPlay(0);
//   p2.setCardToPlay(p2.getHand().size()-1);
//   
//   int winner=startOurGame(p1,p2);;
//   // std::cout<<"\n\n\n\n\n\n\n\n\n\n"<<startOurGame(p1,p2)<<"\n\n";
//   return winner;
// }
// 
// int main(int argc, char const *argv[]) {
//   std::cout<<"RINS STAT LAB\n";
//   Player playerOne;
//   Player playerTwo;
//   int p1Victories=0;
//   int p2Victories=0;
//   // std::cout<<argv[0]<<" "<<argv[1];
//   std::stringstream strValue;
//   strValue << argv[1];
//   int intValue;
//   strValue >> intValue;
//   
//   while (intValue>0) {
//     // std::cout<<"-------------------------------------GAME "<<intValue<<" -----------------------------------\n\n";
//     try{
//       int whoWon=ourGame(playerOne,playerTwo);
//       if(whoWon==0){
//         // std::cout<<"WINNER IS PLAYERONE\n";
//         p1Victories++;
//       }else if(whoWon==1){
//         // std::cout<<"WINNER IS PLAYERTWO\n";
//         p2Victories++;
//       }
//     }catch(int e){
//       std::cout<<e;
//     }
//     intValue--;
//   }
//   
//   
//   std::cout<<"PLAYER ONE VICTORIES: "<<p1Victories<<"\n\nPLAYER TWO VICTORIES: "<<p2Victories<<"\n\n";
//   return 0;
// }
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 









#include <iostream>
#include <sstream>
#include <time.h>
#include <vector>
#include "Player.h"


// std::vector<int> REGDECK = {1,1,1,1,1,1,2,2,2,3,3,3,3,3,3,3,4,4,4,4,4,5,5,
// 5,5,5,5,6,6,6,6,6,6,6,6,7,7,7,7,7,7,
// 8,8,8,8,8,8,9,9,9,9,9,10,10,10,10};
// std::vector<int> REGDECK={1,1,1,2,2,3,3,3,4,4,5,5,5,5,6,6};
std::vector<int> REGDECK = {1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,
8,8,8,8,9,9,9,9,10,10,10,10,11,11,11,11,12,12,12,12,13,13,13,13};



void printCards(std::vector<int>& cards){
  for(int i=0;i<cards.size();i++){
    std::cout<<cards[i]<<"\n";
  }
}

void shuffle(std::vector<int>& cards){
  std::srand(time(NULL));
  for(int i=0;i<250;i++){
    int indexOne=rand()%cards.size();
    int indexTwo=rand()%cards.size();
    std::swap(cards[indexOne],cards[indexTwo]);
  }
  // printCards(OURDECK);
  // std::cout<<"\n"<<OURDECK.size()<<" "<<OURDECK[55];
}

void makeHands(std::vector<int>& handOne, std::vector<int>& handTwo, std::vector<int>& dealerDeck){
  handOne.clear();
  handTwo.clear();
  for(int i=0;i<dealerDeck.size();i++){
    if(i%2){//ODD NUMBERS
      handTwo.push_back(dealerDeck[i]);
    }else{//0 and EVEN NUMBERS
      handOne.push_back(dealerDeck[i]);
    }
  }
  // printCards(handOne);
  // std::cout<<"\n\n\n";
  // printCards(dealerDeck);
  // std::cout<<"\n\n\n";
  // printCards(handTwo);
  // std::cout<<"\n\n\n";
  // printCards(dealerDeck);
  
}

int war(Player& p1, Player& p2, int winner){
  // std::cout<<"\n\nwarwarwarwarwarwarwarwarwarwarwarwarwarwarwarwarwarwarwarwarwarwarwarwarwarwarwarwarwarwarwarwar\n\n";
  std::vector<int> warWinnings;
  // std::cout<<"\n\n-----------------------53------------------------\n\n";
  if(p1.getHand().size()<5 ){
    p1.setHandWithWinPile();
    if(p1.getHand().size()<5){
      winner=1;//p2 won
    }
  }
  // std::cout<<"\n\n-----------------------60------------------------\n\n";
  if(p2.getHand().size()<5){
    p2.setHandWithWinPile();
    // p2.setCardToPlay(0);
    // p2.setCardToPlay(p2.getHand().size()-1);
    if(p2.getHand().size()<5){
      winner=0;//p1 won
    }
  }
  // std::cout<<"\n\n-----------------------67------------------------\n\n";
  if(winner==-1){
    warWinnings.push_back(p1.getHand().at(p1.getCardToPlay()));//put p1 card in war winnings
    warWinnings.push_back(p2.getHand().at(p2.getCardToPlay()));//put p2 card in war winnings
    warWinnings.insert(warWinnings.end(),{p1.getHand().at(p1.getCardToPlay()+1),p1.getHand().at(p1.getCardToPlay()+2),p1.getHand().at(p1.getCardToPlay()+3)});//put three cards from p1 in war winnings
    warWinnings.insert(warWinnings.end(),{p2.getHand().at(p2.getCardToPlay()+1),p2.getHand().at(p2.getCardToPlay()+2),p2.getHand().at(p2.getCardToPlay()+3)});//put three cards from p2 in war winnings

    // warWinnings.insert(warWinnings.end(),{p2.getHand().at(p2.getCardToPlay()-1),p2.getHand().at(p2.getCardToPlay()-2),p2.getHand().at(p2.getCardToPlay()-3)});//put three cards from p2 in war winnings
    
    // std::cout<<"\n\n-----------------------72------------------------\n\n";
    p1.getHand().erase(p1.getHand().begin(),p1.getHand().begin()+4);//erase four cards from beginning of p1
    p2.getHand().erase(p2.getHand().begin(),p2.getHand().begin()+4);//erase four cards from beginning of p2
    // p2.setCardToPlay(0);

    // p2.getHand().erase(p2.getHand().begin()+p2.getHand().size()-4,p2.getHand().end());//erase four cards from end of p2
    // p2.setCardToPlay(p2.getHand().size()-1);
    
    // std::cout<<"\n\n-----------------------76------------------------\n\n";
    if(p1.getHand().at(p1.getCardToPlay())>p2.getHand().at(p2.getCardToPlay())){
      //add winnings to p1 pile
      p1.addToPile(warWinnings);
    }else if(p1.getHand().at(p1.getCardToPlay())<p2.getHand().at(p2.getCardToPlay())){
      //add winnings to p2 pile
      p2.addToPile(warWinnings);
    }else{
      war(p1,p2,winner);
    }
}

  return winner;
}

int compareOurCards(Player& p1, Player& p2,int winner){
  int p1Card=p1.getHand().at(p1.getCardToPlay());
  int p2Card=p2.getHand().at(p2.getCardToPlay());
  std::vector<int> cards={p1Card,p2Card};
  std::cout<<"CARDS\n";
  printCards(cards);
  
  std::cout<<"\nHANDS\nHANDONE\n";
  printCards(p1.getHand());
  std::cout<<"\n\n\n\nHANDTWO\n";
  printCards(p2.getHand());
  std::cout<<"\n\n\n\n";
  
  
  if(p1Card>p2Card){
    p1.getHand().erase(p1.getHand().begin());
    p2.getHand().erase(p2.getHand().begin());
    //remove cards from and put them into p1's pile
    
    // p1.getHand().erase(p1.getHand().begin());
    // p2.getHand().pop_back();
    // p2.setCardToPlay(p2.getHand().size()-1);
    
    p1.addToPile(cards);
    // printCards(p1.getHand());
    // std::cout<<"\n\n\n\n";
    // printCards(p2.getHand());
  }
  else if(p1Card<p2Card){
    p1.getHand().erase(p1.getHand().begin());
    p2.getHand().erase(p2.getHand().begin());
    //remove cards and put them into p2's pile 
    
    // p1.getHand().erase(p1.getHand().begin());
    // p2.getHand().pop_back();
    // p2.setCardToPlay(p2.getHand().size()-1);
    
    p2.addToPile(cards);
    // printCards(p1.getHand());
    // std::cout<<"\n\n\n\n";
    // printCards(p2.getHand());
    
  }
  else{
    // std::cout<<"\n\nCARDS\n\n";
    // printCards(cards);
    winner=war(p1,p2,winner);
    
    //write war method here
    // p1.getHand().erase(p1.getHand().begin());
    // p2.getHand().pop_back();
    // p2.setCardToPlay(p2.getHand().size()-1);
  }
  return winner;
}

int startOurGame(Player& playerOne,Player& playerTwo){//player two play from bottom of hand and player one play from top of hand
  int winner=-1;
  // std::cout<<"---------------------------WINNER"<<winner<<"\n\n";
  while (winner==-1) {
    // std::cout<<"HANDONE\n\n";
    // printCards(playerOne.getHand());
    // std::cout<<"\n\n\n\n\nHANDTWO\n";
    // printCards(playerTwo.getHand());
    // std::cout<<"\n\n\n\n\n";
    
    winner=compareOurCards(playerOne,playerTwo,winner);
    if(winner==-1){
      if(playerOne.getHand().size()==0){
        if(playerOne.getPile().size()==0){
          winner=1;//if winner == 1 p2 won
          // std::cout<<"WINNERP2 "<<winner<<"\n\n";
        }else{
          std::cout<<"\nP1PILE\n\n";
          printCards(playerOne.getPile());
          playerOne.setHandWithWinPile();
          std::cout<<"\nP2PILE\n\n";
          printCards(playerTwo.getPile());
          playerTwo.setHandWithWinPile();
          
          // playerOne.setCardToPlay(0);
        }
      }
      if(playerTwo.getHand().size()==0){
        if(playerTwo.getPile().size()==0){
          winner=0;//if winner ==0 p1 won
          // std::cout<<"WINNERP1 "<<winner<<"\n\n";
        }else{
          std::cout<<"\nP1PILE\n\n";
          printCards(playerOne.getPile());
          playerOne.setHandWithWinPile();
          std::cout<<"\nP2PILE\n\n";
          printCards(playerTwo.getPile());
          playerTwo.setHandWithWinPile();
          
          // playerTwo.setCardToPlay(0);

        }
      } 
    } 
  }
  return winner;
}

int ourGame(Player& p1, Player& p2){
  shuffle(REGDECK);
  makeHands(p1.getHand(),p2.getHand(),REGDECK);
  // std::cout<<"HANDONE\n";
  // printCards(p1.getHand());
  // std::cout<<"HANDTWO\n";
  // printCards(p2.getHand());
  p1.setCardToPlay(0);
  // p2.setCardToPlay(p2.getHand().size()-1);
  p2.setCardToPlay(0);

  
  int winner=startOurGame(p1,p2);;
  // std::cout<<"\n\n\n\n\n\n\n\n\n\n"<<startOurGame(p1,p2)<<"\n\n";
  return winner;
}

int main(int argc, char const *argv[]) {
  Player playerOne;
  Player playerTwo;
  int p1Victories=0;
  int p2Victories=0;
  // std::cout<<argv[0]<<" "<<argv[1];
  std::stringstream strValue;
  strValue << argv[1];
  int intValue;
  strValue >> intValue;
  
  while (intValue>0) {
    // std::cout<<"-------------------------------------GAME "<<intValue<<" -----------------------------------\n\n";
    try{
      int whoWon=ourGame(playerOne,playerTwo);
      if(whoWon==0){
        // std::cout<<"WINNER IS PLAYERONE\n";
        p1Victories++;
      }else if(whoWon==1){
        // std::cout<<"WINNER IS PLAYERTWO\n";
        p2Victories++;
      }
    }catch(int e){
      std::cout<<e;
    }
    intValue--;
  }
  
  
  std::cout<<"PLAYER ONE VICTORIES: "<<p1Victories<<"\n\nPLAYER TWO VICTORIES: "<<p2Victories<<"\n\n";
  return 0;
}

