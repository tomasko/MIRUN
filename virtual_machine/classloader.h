#ifndef CLASSLOADER_H
#define CLASSLOADER_H

#include <string>
#include <fstream>
#include <vector>
#include <string>
#include "class.h"
#include "method.h"
#include "constantpool.h"

class ClassLoader
{
public:
	ClassLoader(const char * folder);
	~ClassLoader();
	Class * loadClass(const char * className);

private:
	Method * loadMethod();
	ConstantPool * loadConstantPool();
	std::string getFileName(const char * className);

	std::string folder;
	std::fstream file;

};

#endif // CLASSLOADER_H
