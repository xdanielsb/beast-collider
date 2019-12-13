#ifndef _CKamikaze
#define _CKamikaze
#include"./IBehaviour.hpp"
#define debug(x) cout << #x << " = " << x <<endl;
class KamikazeB:public Behaviour{
private:
  ii getNewDirection( Animal *src, Animal *aim){
    ii res;
    res.X = (aim->getPosX() - src->getPosX());
    res.Y = (aim->getPosY() - src->getPosY());
    if( fabs(res.X) > 1e-6 ) res.X /= src->getDistance(aim->getPosition());
    if( fabs(res.Y) > 1e-6 ) res.Y /= src->getDistance( aim->getPosition());
    return res;
  }
public:
  void move(Animal* a, vector<Animal*> list){
    double minDistance = 1e9;
    Animal *nearestAnimal;
    for(Animal* b:list){
      if( b->getId() == a->getId() )continue;
      double aux =  a->getDistance( b->getPosition());
      if( aux < minDistance){
        minDistance = aux;
        nearestAnimal = b;
      }
    }
    a->setDirX(getNewDirection( a, nearestAnimal).X);
    a->setDirY(getNewDirection( a, nearestAnimal).Y);
    if(isOutOfBoundaries(a)){
  		a->setDirX(a->getDirX()*-1);
  		a->setDirY(a->getDirY()*-1);
	  }
    a->setPosX(a->getPosX()+a->getDirX());
    a->setPosY(a->getPosY()+a->getDirY());
    printf("->K{%.2f, %.2f}\n", a->getPosX(), a->getPosY());
  }
};
#endif
