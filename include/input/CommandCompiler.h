#ifndef _CommandCompiler_h
#define _CommandCompiler_h

#include <string>
#include <vector>
#include "input/CommandScanner.h"
#include "input/VirtualController.h"
#include <functional>

typedef std::function<bool(int, bool)> CommandFunction;
class CommandCompiler {
public:

  CommandCompiler();
  ~CommandCompiler();

  void init();
  void compile(const char* inputString);

  CommandFunction compileNode();
  CommandFunction binaryCommand(CommandFunction currentFunc, CommandTokenType type);

  static std::vector<std::string> commandStrings;
  std::vector<std::vector<CommandFunction>> commandFunctionList;
  VirtualController* controllerPointer;
private:
  CommandScanner commandScanner;
  CommandToken* currentToken;
};

#endif /* _CommandCompiler_h */
