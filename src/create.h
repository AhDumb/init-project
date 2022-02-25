#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MODE (S_IRWXU | S_IRWXG | S_IRWXO)

using namespace std;

bool create(const char* name, const string& dirs, const string& files, bool git);
