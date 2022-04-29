#include "GritVM.hpp"
#include <fstream>
#include <exception>
#include <iostream>


GritVM :: GritVM(){
  accumulator = 0;
  machineStatus = WAITING;
}

STATUS GritVM :: load(const std::string filename,
                      const std::vector<long> &initialMemory){
  DataMem = initialMemory;

  std::fstream input(filename, std::fstream::in); //opens file stream for filename to read

  if(!input.is_open()) //make sure file opens
    throw std::exception();

  while(!input.eof() && !input.bad()){ //checking file content to make sure its useable
    std::string line;
    getline(input, line);

    if(line != "" && line[0] != ' ' && line[0] != '#'){ //makes sure line isn't white space or a comment
      Instruction temp = GVMHelper::parseInstruction(line);
      if(temp.operation == UNKNOWN_INSTRUCTION){
        machineStatus = ERRORED;//AND THATS THAT ON THAT
        return machineStatus;
      }
      InstructMem.push_back(temp);
    }
  }
  currInstruct = InstructMem.begin();
  machineStatus = READY;
  input.close();
  return machineStatus;
}



long GritVM :: evaluate(Instruction currInstruct){
  long jumpDistance = 1;
  switch (currInstruct.operation) {
    case CLEAR:
      accumulator = 0;
      break;
    case AT:
      accumulator = DataMem.at(currInstruct.argument);
      break;
    case SET:
      DataMem.at(currInstruct.argument) = accumulator;
      break;
    case INSERT:
      DataMem.insert((DataMem.begin() + currInstruct.argument), accumulator);
      break;
    case ERASE:
      DataMem.erase(DataMem.begin() + currInstruct.argument);
      break;
    case ADDCONST:
      accumulator += currInstruct.argument;
      break;
    case SUBCONST:
      accumulator -= currInstruct.argument;
      break;
    case MULCONST:
      accumulator *= currInstruct.argument;
      break;
    case DIVCONST:
      if(currInstruct.argument != 0)
        accumulator /= currInstruct.argument;
      else
        machineStatus = ERRORED;
      break;
    case ADDMEM:
      accumulator += DataMem.at(currInstruct.argument);
      break;
    case SUBMEM:
      accumulator -= DataMem.at(currInstruct.argument);
      break;
    case MULMEM:
      accumulator *= DataMem.at(currInstruct.argument);
      break;
    case DIVMEM:
      if(DataMem.at(currInstruct.argument) != 0)
        accumulator /= DataMem.at(currInstruct.argument);
      else
        machineStatus = ERRORED;
      break;
    case JUMPREL:
      jumpDistance = currInstruct.argument;
      break;
    case JUMPZERO:
      if(accumulator == 0)
        jumpDistance = currInstruct.argument;
      break;
    case JUMPNZERO:
      if(accumulator != 0)
        jumpDistance = currInstruct.argument;
      break;
    case NOOP:
      break;
    case HALT:
      machineStatus = HALTED;
      break;
    case OUTPUT:
      std::cout << accumulator << std::endl;
      break;
    case CHECKMEM:
      if(DataMem.size() >= currInstruct.argument)
        break;
      machineStatus = ERRORED;
      break;
    default:
      machineStatus = ERRORED;
      break;
  }
  return jumpDistance;
}



void GritVM :: advance(long jumpDistance){
  if(jumpDistance == 0)
    machineStatus = ERRORED;
  else {
    // Set jumped to |jumpDistance|
    for(long jumped = (jumpDistance > 0 ? jumpDistance : -1 * jumpDistance);
        jumped > 0;
        (jumpDistance > 0 ? ++currInstruct : --currInstruct)) { //"Conceptually, is a little strange"
      --jumped; // Decrement each time to ensure we actually jumped enough times
    }
  }
}


STATUS GritVM :: run(){
  if (machineStatus == READY)
    machineStatus = RUNNING;
  while(machineStatus == RUNNING){
    long jumpDistance = evaluate(*currInstruct);
    advance(jumpDistance);
    if (currInstruct == InstructMem.end())
      machineStatus = HALTED;
  }
  return machineStatus;
}


STATUS GritVM :: reset(){

  machineStatus = WAITING;
  accumulator = 0;

  DataMem.clear();
  InstructMem.clear();

  return machineStatus;
}

void GritVM :: printVM(bool printData, bool printInstruct){
  std::cout << "*** Output Dump ***" << std::endl;
  std::cout << "Status: " << GVMHelper::statusToString(machineStatus) << std::endl;
  std::cout << "Accumulator: " << accumulator << std::endl;

  if(printData){
    std::cout << "*** Data Memory ***" << std::endl;
    int index = 0;
    std::vector<long>::iterator it = DataMem.begin();
    while(it != DataMem.end()){
      long item = (*it);
      std::cout << "Location " << index++ << ": " << item << std::endl;
      it++;
    }
  }

  if(printInstruct){
    std::cout << "*** Instruction Memory ***" << std::endl;
    int index = 0;
    std::list<Instruction>::iterator it = InstructMem.begin();
    while(it != InstructMem.end()){
      Instruction item = (*it);
      std::cout << "Instruction " << index++ <<
        ": " << GVMHelper::instructionToString(item.operation) <<
        " " << item.argument << std::endl;
      it++;
    }
  }

}
