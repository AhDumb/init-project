/**
 * @author aaron
 * @version 1.0
 * @fileName create.cpp
 * @email wzj020109@163.com
 * @date 2022-02-25
 * @desc 创建文件
 */

#include "include/create.h"
#include "include/utils.h"
#include <cstdio>
#include <cstdlib>
#include <fmt/color.h>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <unistd.h>
#include <vector>

/* 判断文件夹是否存在 */
bool is_exist(const char* name)
{
  if (access(name, 0) == -1) {
    return true;
  }
  return false;
}

bool create(const char* name, const string& dirs, const string& files, bool git)
{
  char* cwd = get_current_dir_name();
  char res[100];
  // 拼接文件地址
  sprintf(res, "%s%s%s", cwd, "/", name);

  // 文件夹不存在
  if (is_exist(name)) {
    mkdir(res, MODE);
    chdir(res);

    /**
     * 循环创建文件夹
     */
    vector<string> dir = split(dirs, " ");
    for (int i = 0; i < dir.size(); ++i) {
      mkdir((char*)dir[i].data(), MODE);
    }

    /**
     * 循环创建文件
     */
    vector<string> file = split(files, " ");
    for (int j = 0; j < file.size(); ++j) {
      ofstream oFile;
      oFile.open(file[j], ios::app);
      oFile.close();
    }

    /**
     * 是否启用 Git
     */
    if (git) {
      system("git init");
      ofstream oFile;
      oFile.open(".gitignore");
      oFile.close();
    }
    // 文件夹存在
  } else {
    fmt::print(
        fg(fmt::color::floral_white),
        "项目以存在\n");
  }
  return true;
}
