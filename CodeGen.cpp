#include "llvm/ADT/ArrayRef.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Host.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"
#include <unordered_map>
#include <string>

using namespace llvm;
// llvm part
static LLVMContext context;
// one module for now and for test
static Module *module;
// ir builder
static IRBuilder<> builder(context);

class CodeGen {
    std::unordered_map <std::string, Value*> var_map;
public:	
    CodeGen(std::string module_name) {
        module = new Module(module_name, context);
    }

    void getFunction(std::string name) {
        if (name == "main") {
            getMainFunction();
        }
    }

    void getMainFunction() {
        auto funcType = FunctionType::get(builder.getVoidTy(), false);
        auto mainFunc = Function::Create(funcType, Function::ExternalLinkage, "main", module);
        auto entry = BasicBlock::Create(context, "entrypoint", mainFunc);
        builder.SetInsertPoint(entry);
    }

    void callFunction(std::string name, std::vector)

    void createRet(std::string retName) {
        if (retName == "void")
            builder.CreateRetVoid();
    }

    void createTempVar(int value, std::string name) {
        auto number = ConstantInt::get(Type::getInt32Ty(context), value);
        var_map[name] = builder.CreateAlloca(Type::getInt32Ty(context), NULL, name);
        builder.CreateStore(number, var_map[name]);
    }

    void createAssignVar(std::string leftName, std::string rightName) {
        var_map[leftName] = builder.CreateAlloca(Type::getInt32Ty(context), NULL, leftName);
        builder.CreateStore(var_map[rightName], var_map[leftName]);
    }

    void createBinOp(std::string leftName, std::string r1, std::string r2, std::string r3) {
        if (r2 == "+") {
            var_map[leftName] = builder.CreateAdd(var_map[r1], var_map[r3], leftName);
        }
        else if (r2 == "-") {
            var_map[leftName] = builder.CreateSub(var_map[r1], var_map[r3], leftName);
        }
        else if (r2 == "*") {
            var_map[leftName] = builder.CreateMul(var_map[r1], var_map[r3], leftName);
        }
        else if (r2 == "/") {
            var_map[leftName] = builder.CreateSDiv(var_map[r1], var_map[r3], leftName);
        }
        // ----todo----
    }
};