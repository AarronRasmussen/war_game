#include <vector>


class Player{
private:
  std::vector<int> hand;
  std::vector<int> winPile;
  int cardToPlay;
  
public:
  // std::vector<int> hand;
  // std::vector<int> winPile;
  
  void setHandWithWinPile();
  void setHand(const std::vector<int>& handIn); 
  void addToPile(const std::vector<int>& pileIn); 
  void setCardToPlay(int index);
  std::vector<int>& getHand();
  std::vector<int>& getPile();
  int getCardToPlay();
  
  
};