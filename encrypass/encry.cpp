#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"

#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"

using namespace llvm;

namespace {
    struct Encry : public FunctionPass {
        static char ID;
        Encry() : FunctionPass(ID) {}
        bool runOnFunction(Function &F) override {
            errs() << "encrypt: " << F.getName() << " -> ";
            if (F.getName().compare("main") != 0){
                F.setName("encry" + F.getName());
            }

            errs().write_escaped(F.getName()) << '\n';

            return false;
        }
    };
}

char Encry::ID = 0;
static RegisterPass<Encry> X("encrypt", "encrypt function name Pass",
                             false /* Only looks at CFG */,
                             false /* Analysis Pass */);
static llvm::RegisterStandardPasses Y(
        llvm::PassManagerBuilder::EP_EarlyAsPossible,
[](const llvm::PassManagerBuilder &Builder,
   llvm::legacy::PassManagerBase &PM) { PM.add(new Encry()); });
