#ifndef INTERPRET_H
#define INTERPRET_H

#include "instruction.h"
#include "stackframe.h"
#include "classloader.h"
#include "memory.h"

class Interpret
{
public:
	Interpret(ClassLoader * classLoader);
	~Interpret();
	int run(const char * className, const char * methodName);
	
private:
	int run();
	void doAritmetics(INSTRUCTION i);
	void doRealAritmetics(Object * op1, Object * op2, INSTRUCTION i);
	void doIntAritmetics(Object * op1, Object * op2, INSTRUCTION i);
	void addConst(int c);
	void callMethod(Class * cls, Method * m);
	void doJump();
	Object * fetchObject();
	int32_t fetchInteger();
	void checkNumber(Object * o) const;
	void checkInteger(Object * o) const;

	StackFrame * currentFrame;
	ClassLoader * classLoader;
	Memory * heap;
};

#endif // INTERPRET_H