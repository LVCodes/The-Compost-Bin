#ifndef __GRITVM_H_
#define __GRITVM_H_
#include <list>
#include "GritVMBase.hpp"


class GritVM : public GritVMInterface{
public:
  GritVM();
  STATUS load(const std::string filename, const std::vector<long> &initialMemory);
  STATUS run();
  std::vector<long> getDataMem(){return DataMem;}
  STATUS reset();
  void printVM(bool printData, bool printInstruct);


private:
  std::vector<long> DataMem;
  std::list<Instruction> InstructMem;
  std::list<Instruction>::iterator currInstruct;
  STATUS machineStatus;
  long accumulator;
  long evaluate(Instruction currInstruct);
  void advance(long jumpDistance);

};

#endif // __GRITVM_H_
