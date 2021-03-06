#ifndef _Character_h
#define _Character_h 

#include <nlohmann/json.hpp>
#include <SDL_mixer.h>
#include "game_objects/GameObject.h"
#include "character_state/StateDef.h"
#include "domain_language/VirtualMachine.h"
#include "domain_language/Script.h"
#include "input/VirtualController.h"
#include "graphics/Animation.h"

// TODO: base class for this n entity
class Entity;
class Character : public GameObject {
public:
  Character(std::pair<int, int> position, int playerNum);
  Character(std::pair<int, int> position);
  void init();

  ~Character();

  void compileScript(const char* path, Script* script, const char* scriptTag);
  void loadStates();
  void refresh();
  void changeState(int stateDefNum);
  void cancelState(int stateDefNum);

  void handleInput();
  void update();
  void draw();

  // position stuff
  std::pair<int,int> getPos();
  void setXPos(int x);
  void setYPos(int y);
  void setX(int x);
  void setY(int y);
  void updateFaceRight();
  void updatePosition();
  void updateCollisionBoxPositions();
  void updateCollisionBoxes();
  StateDef* getCurrentState();
  Mix_Chunk* getSoundWithId(int id);

  // getters for these guys

  int width = 100;
  int control = 1;
  int hitstun = 0;
  int blockstun = 0;
  int hitStop = 0;
  int pushTime = 0;
  int pushBackVelocity = 0;
  int maxHealth = 100;
  int hasAirAction = 0;
  int comboCounter = 0;
  int cancelPointer = 0;
  int noGravityCounter = 0;
  long frameLastAttackConnected = 0;
  bool inCorner = false;
  bool inHitStop = false;
  bool gravity = true;
  bool isDead = false;
  int velocityX = 0;
  int velocityY = 0;
  bool hitsparkRectDisabled = true;
  int currentHurtSoundID = 0;
  int health;
  int playerNum;
  bool faceRight;
  bool inputFaceRight;
  CollisionRect hitsparkIntersect;

  void _changeState(int stateNum);
  void _cancelState(int stateNum);
  void _velSetX(int ammount);
  void _negVelSetX(int ammount);
  void _velSetY(int ammount);
  void _moveForward(int ammount);
  void _moveBack(int ammount);
  void _moveUp(int ammount);
  void _moveDown(int ammount);
  void _setControl(int val);
  void _setCombo(int val);
  void _setHitStun(int val);
  void _setBlockstun(int val);
  void _setNoGravityCounter(int count);
  void _setGravity(int set);
  void _setAirAction(int set);
  void _resetAnim();
  void _activateEntity(int entityID);
  void _deactivateEntity(int entityID);
  void _snapToOpponent(int offset);

  int _getHitStun();
  int _getBlockStun();
  int _getAnimTime();
  int _getStateTime();
  int _getYPos();
  int _getStateNum();
  int _getControl();
  int _getCombo();
  int _getAirActions();
  int _getIsAlive();
  int _getInput(int input);
  int _wasPressed(int input);
  int _checkCommand(int commandIndex);

  VirtualController* virtualController;
  StateDef* currentState;
  Character* otherChar;
  Script inputScript;
  VirtualMachine virtualMachine;
  std::vector<uint8_t> inputByteCode;
  std::vector<Entity> entityList;
  std::vector<Animation> animList;
  std::vector<Mix_Chunk*> soundList;
  std::vector<Mix_Chunk*> hurtSoundList;
private:
  nlohmann::json stateJson;
  std::vector<StateDef> stateList;
  std::pair<int, int> position;
};

#endif
