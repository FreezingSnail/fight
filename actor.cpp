#include "actor.h"
#include "images.h"


actor::actor()  {
  
  hp;
  weapon;
  level=1;
  type;
}
  
 

 

uint16_t actor::damage(){
    return (getStat(pgm_read_word(&type->statSeed.strength)) / 2);
}


void actor::takeDamage(actor attacker, uint16_t modifier){
  
     int damageval = ((((attacker.damage())/*+attacker.weapon.atkMod*/) - ((getStat(pgm_read_word(&type->statSeed.defense)))/2)/*-weapon.defMod*/) - modifier);
      if (damageval > 0){
        hp -= damageval;
      }
      else{
        hp -= 1;
      }
}

void actor::takeSpecial(actor attacker){
  
  int damageval = (((getStat(pgm_read_word(pgm_read_word(&attacker.type->statSeed.special))))/2)/*+weapon.spcMod*/-((getStat(pgm_read_word(&type->statSeed.special)))/2)/*-weapon.spcMod*/) ;
      if (damageval > 0){
        hp -= damageval;
      }
      else{
      }
}

void actor::levelUp(){
  level++;
  hp = getStat(pgm_read_word(&type->statSeed.totalHP));
  
  
}

uint16_t actor::getStat(uint8_t stat){
  //=(((3 * B1))/4)+1
  return ((((stat* level)/4)) +level);
  
}


uint16_t actor::expDrop(){
  return level*2;
}

//warrior::warrior{
  //weapon sword(1, 0, "sword");
//}


  

//damage formula
// ((strength/2)+ weapon atk) - ((def/2) +weapon def mod) + modifier
//ie if opponet defends mod = -2

