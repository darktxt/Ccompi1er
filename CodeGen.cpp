#include "llvm/ADT/ArrayRef.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Host.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"
// #include "llvm/Transforms/Scalar.h"
// #include "llvm/Transforms/Scalar/GVN.h"
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>

using namespace llvm;
// llvm part
static LLVMContext context;
// one module for now and for test
static std::unique_ptr<Module> module;
// ir builder
static IRBuilder<> builder(context);

// class FunctionExp {
//     std::unordered_map <std::string, Value*> var_map;
//     CodeGen()
// }

class CodeGen {
    std::unordered_map <std::string, Value*> var_map;
    // std::unordered_map <std::string, Value*> global_var;
    std::unordered_map <std::string, Value*> temp_var;
public:	
    CodeGen(std::string module_name) {
        module = llvm::make_unique<Module>(module_name, context);
    }

    void getFunction(std::string funcName, std::string retTypeName) {
        auto funcType = FunctionType::get(getType(retTypeName), false);
        auto func = Function::Create(funcType, Function::ExternalLinkage, funcName, module.get());
        auto entry = BasicBlock::Create(context, "entry", func);
        builder.SetInsertPoint(entry);
        verifyFunction(*func);
    }


    void createRet(std::string retTypeName, Value* val) {
        if (retTypeName == "void")
            builder.CreateRetVoid();
        else if (retTypeName == "int")
            builder.CreateRet(val);
        // -- todo --
    }

    Type* getType(std::string name) {
        Type* type = nullptr;
        if (name == "void") {
            type = Type::getVoidTy(context);
        }
        else if (name == "int"){
            type = Type::getInt32Ty(context);
        }
        // -- todo --
        return type;
    }

    void getMainFunction() {

    }

    Value* callFunction(std::string name, const std::vector<std::string>& args) {
        if (name == "print") {
            return callPrintFunction(args);
        }
        else {
            std::vector<Type *> argsType;
            std::vector<Value *> argsValue;
            for (auto arg: args) {
                auto value = getVarValue(arg);
                argsValue.push_back(value);
                argsType.push_back(value->getType());
            }
            ArrayRef<Type *> argsRef(argsType);
            auto funcType = FunctionType::get(builder.getInt32Ty(), argsRef, false);
            auto funcFunc = module->getOrInsertFunction(name, funcType);
            return builder.CreateCall(funcFunc, argsValue);
        }
    }

    Value* callPrintFunction(const std::vector<std::string>& args) {
        std::vector<Type *> argsType;
        std::vector<Value *> argsValue;
        auto formatString = builder.CreateGlobalStringPtr("%d\n");
        argsValue.push_back(formatString);
        argsType.push_back(formatString->getType());
        for (auto arg: args) {
            auto value = getVarValue(arg);
            argsValue.push_back(value);
            argsType.push_back(value->getType());
        }
        ArrayRef<Type *> argsRef(argsType);
        auto printfType = FunctionType::get(builder.getInt32Ty(), argsRef, false);
        auto printfFunc = module->getOrInsertFunction("printf", printfType);
        return builder.CreateCall(printfFunc, argsValue);
    }

    void createTempVar(int value, std::string name) {
        temp_var[name] = ConstantInt::get(Type::getInt32Ty(context), value);
    }

    void createAssignVar(std::string leftName, std::string rightName) {
        var_map[leftName] = builder.CreateAlloca(Type::getInt32Ty(context), NULL, leftName);
        auto temp = getVarValue(rightName);
        builder.CreateStore(temp, var_map[leftName]);
    }

    void createAssignVar(std::string name, Value* val) {
        var_map[name] = builder.CreateAlloca(Type::getInt32Ty(context), NULL, name);
        builder.CreateStore(val, var_map[name]);
    } 

    Value* getVarValue(std::string name) {
        Value* temp = nullptr;
        auto search = var_map.find(name);
        if (search != var_map.end()) {
            temp = builder.CreateLoad(var_map[name], "loadtemp");
        }
        else {
             temp = temp_var[name];
        }
        return temp;
    }

    void createBinOp(std::string leftName, std::string r1, std::string r2, std::string r3) {
        auto tempLeft = getVarValue(r1);
        auto tempRight = getVarValue(r3);
        Value* result = nullptr;
        if (r2 == "+") {
            result = builder.CreateAdd(tempLeft, tempRight, "binoptemp");
        }
        else if (r2 == "-") {
            result = builder.CreateSub(tempLeft, tempRight, "binoptemp");
        }
        else if (r2 == "*") {
            result = builder.CreateMul(tempLeft, tempRight, "binoptemp");
        }
        else if (r2 == "/") {
            result = builder.CreateSDiv(tempLeft, tempRight, "binoptemp");
        }
        else if (r2 == "==") {
            result = builder.CreateICmpEQ(tempLeft, tempRight, "binoptemp");
        }
        else if (r2 == "!=") {
            result = builder.CreateICmpNE(tempLeft, tempRight, "binoptemp");
        }
        // ----todo----
        var_map[leftName] = builder.CreateAlloca(Type::getInt32Ty(context), NULL, leftName);
        builder.CreateStore(result, var_map[leftName]);
    }

    int generateObjectCode() {
        // Initialize the target registry etc.
        InitializeAllTargetInfos();
        InitializeAllTargets();
        InitializeAllTargetMCs();
        InitializeAllAsmParsers();
        InitializeAllAsmPrinters();

        auto TargetTriple = sys::getDefaultTargetTriple();
        module->setTargetTriple(TargetTriple);

        std::string Error;
        auto Target = TargetRegistry::lookupTarget(TargetTriple, Error);

        // Print an error and exit if we couldn't find the requested target.
        // This generally occurs if we've forgotten to initialise the
        // TargetRegistry or we have a bogus target triple.
        if (!Target) {
            errs() << Error;
            return 1;
        }

        auto CPU = "generic";
        auto Features = "";

        TargetOptions opt;
        auto RM = Optional<Reloc::Model>();
        auto TheTargetMachine =
            Target->createTargetMachine(TargetTriple, CPU, Features, opt, RM);

        module->setDataLayout(TheTargetMachine->createDataLayout());

        auto Filename = "output.o";
        std::error_code EC;
        raw_fd_ostream dest(Filename, EC, sys::fs::F_None);

        if (EC) {
            errs() << "Could not open file: " << EC.message();
            return 1;
        }

        legacy::PassManager pass;
        auto FileType = TargetMachine::CGFT_ObjectFile;

        if (TheTargetMachine->addPassesToEmitFile(pass, dest, FileType)) {
            errs() << "TheTargetMachine can't emit a file of this type";
            return 1;
        }

        pass.run(*module);
        dest.flush();

        outs() << "Wrote " << Filename << "\n";
        return 0;
    }

    void eraseTempVar(std::string key) {
        auto search = temp_var.find(key);
        if (search != temp_var.end()) {
            temp_var.erase(key);
        }
        else {
            if (key.find("Temp") != std::string::npos) {
                var_map.erase(key);
            }
        }
    }

};