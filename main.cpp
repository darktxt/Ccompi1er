#include"node.h"
#include"compiler.hpp"
#include<iostream>
#include <vector>
#include <string>
#include "RGenerator.cpp"

extern FILE *yyin;
using namespace std;
extern node* root;
int yyparse();
int main()
{
	yyin = fopen("test.c","r");
	yyparse();
	root->debugInfo(true,true); //show info all the instructions following,no extand
	cout<<endl<<endl;
	//root->next->next->debugInfo(false,true);//only show this instruction,extand
	std::cout << endl << "中间树" << endl;
	RGenerator translator(root);

	// static LLVMContext myGlobalContext;
    // LLVMContext &context = myGlobalContext;
    // Module *module = new Module("asdf", context);
    // IRBuilder<> builder(context);

    // FunctionType *funcType = FunctionType::get(builder.getVoidTy(), false);
    // Function *mainFunc =
    //     Function::Create(funcType, Function::ExternalLinkage, "main", module);
    // BasicBlock *entry = BasicBlock::Create(context, "entrypoint", mainFunc);
    // builder.SetInsertPoint(entry);

    // auto L = ConstantInt::get(Type::getInt32Ty(myGlobalContext), 1);
    // auto R = ConstantInt::get(Type::getInt32Ty(myGlobalContext), 2);
    // auto A = builder.CreateAlloca(Type::getInt32Ty(myGlobalContext), NULL, "A");
    // auto B = builder.CreateAlloca(Type::getInt32Ty(myGlobalContext), NULL, "B");
    // builder.CreateStore (L, A, /*isVolatile=*/false);   // A = 1
    // builder.CreateStore (R, B, /*isVolatile=*/false);   // B = 2
    // builder.CreateAdd(A, L, "addtmp");      // addtmp = A + 1
    // builder.CreateAdd(A, B, "addtmp");      // addtmp = A + B
    // builder.CreateRetVoid();

    // module->print(errs(), nullptr);

    // // Initialize the target registry etc.
    // InitializeAllTargetInfos();
    // InitializeAllTargets();
    // InitializeAllTargetMCs();
    // InitializeAllAsmParsers();
    // InitializeAllAsmPrinters();

    // auto TargetTriple = sys::getDefaultTargetTriple();
    // module->setTargetTriple(TargetTriple);

    // std::string Error;
    // auto Target = TargetRegistry::lookupTarget(TargetTriple, Error);

    // // Print an error and exit if we couldn't find the requested target.
    // // This generally occurs if we've forgotten to initialise the
    // // TargetRegistry or we have a bogus target triple.
    // if (!Target) {
    //     errs() << Error;
    //     return 1;
    // }

    // auto CPU = "generic";
    // auto Features = "";

    // TargetOptions opt;
    // auto RM = Optional<Reloc::Model>();
    // auto TheTargetMachine =
    //     Target->createTargetMachine(TargetTriple, CPU, Features, opt, RM);

    // module->setDataLayout(TheTargetMachine->createDataLayout());

    // auto Filename = "output.o";
    // std::error_code EC;
    // raw_fd_ostream dest(Filename, EC, sys::fs::F_None);

    // if (EC) {
    //     errs() << "Could not open file: " << EC.message();
    //     return 1;
    // }

    // legacy::PassManager pass;
    // auto FileType = TargetMachine::CGFT_ObjectFile;

    // if (TheTargetMachine->addPassesToEmitFile(pass, dest, FileType)) {
    //     errs() << "TheTargetMachine can't emit a file of this type";
    //     return 1;
    // }

    // pass.run(*module);
    // dest.flush();

    // outs() << "Wrote " << Filename << "\n";

	return 0;
}
