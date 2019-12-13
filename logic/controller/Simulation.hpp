#ifndef _CSimulation
#define _CSimulation
#include"../include.hpp"
#include"./Environment.hpp"
#include"../factory/BeastFactory.hpp"
#include"../factory/BehaviourFactory.hpp"
#include"../../view/Aquarium.hpp"
#include"../../model/beast/Animal.hpp"
#include <thread>
#include <chrono>

BeastFactory *BeastFactory::instance=0;
BehaviourFactory *BehaviourFactory::instance=0;

class Simulation{
private:
  Aquarium *q;
  BeastFactory *fac;
  BehaviourFactory *behaviourFactory;
  Environment *env;
public:
  Simulation( int nBeast){
      this->behaviourFactory = behaviourFactory->buildFactory();
      this->fac = fac->buildFactory(behaviourFactory);
      vector< Animal*> list = this->fac->newRandomPopulation( nBeast );
      this->env = new Environment( list );
  }
  void startCLI( ){
   for(int step = 1;; step++){
     printf("Running step #%d\n", step);
     this_thread::sleep_for(chrono::seconds(1));
     this->env->step();
   }
  }
  void startGUI(){
      this->q = new Aquarium(300, 300, env);
      this->q->run();
  }
};
#endif
