#include"node.h"
#include"compiler.hpp"
#include<iostream>
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
#include <vector>
#include <string>
#include "RGenerator.cpp"

extern FILE *yyin;
using namespace std;
using namespace llvm;
extern node* root;
int yyparse();
int main()
{
	yyin = fopen("test.c","r");
	yyparse();
	//root->debugInfo(false,true); //show info all the instructions following,no extand
	cout<<endl<<endl;
	//root->next->next->debugInfo(false,true);//only show this instruction,extand
	cout << endl << "中间树" << endl;
	RGenerator translator(root);

	static llvm::LLVMContext myGlobalContext;
    llvm::LLVMContext &context = myGlobalContext;
    llvm::Module *module = new llvm::Module("asdf", context);
    llvm::IRBuilder<> builder(context);

    llvm::FunctionType *funcType = llvm::FunctionType::get(builder.getVoidTy(), false);
    llvm::Function *mainFunc =
        llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, "main", module);
    llvm::BasicBlock *entry = llvm::BasicBlock::Create(context, "entrypoint", mainFunc);
    builder.SetInsertPoint(entry);

    llvm::Value *helloWorld = builder.CreateGlobalStringPtr("hello world!\n");

    std::vector<llvm::Type *> putsArgs;
    putsArgs.push_back(builder.getInt8Ty()->getPointerTo());
    llvm::ArrayRef<llvm::Type *> argsRef(putsArgs);

    llvm::FunctionType *putsType =
        llvm::FunctionType::get(builder.getInt32Ty(), argsRef, false);
    llvm::Constant *putsFunc = module->getOrInsertFunction("puts", putsType);

    builder.CreateCall(putsFunc, helloWorld);
    builder.CreateRetVoid();

    module->print(llvm::errs(), nullptr);

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
