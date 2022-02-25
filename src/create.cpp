/**
 * @author aaron
 * @version 1.0
 * @fileName create.cpp
 * @email wzj020109@163.com
 * @date 2022-02-25
 * @desc 创建文件
 */

#include <cstdio>
#include <cstdlib>
#include <string>
#include <sys/stat.h>
#include <unistd.h>
#include <vector>
#include <fstream>
#include "create.h"
#include "utils.h"

bool create(const char *name, const string &dirs, const string &files, bool git)
{
  char* cwd = get_current_dir_name();
  char res[100];
  sprintf(res, "%s%s%s", cwd, "/", name);
  mkdir(res, MODE);
  chdir(res);
  vector<string> dir = split(dirs, " ");
  for (int i = 0; i < dir.size(); ++i) {
    mkdir((char*)dir[i].data(), MODE);
  }
  vector<string> file = split(files, " ");
  for (int j = 0; j < file.size(); ++j) {
    ofstream oFile;
    oFile.open(file[j], ios::app);
    oFile.close();
  }
  if ( git ) {
    system("git init");
    ofstream oFile;
    oFile.open(".gitignore");
    oFile.close();
  }
  return true;
}
