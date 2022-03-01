/**
 * @author aaron
 * @version 1.0
 * @fileName main.cpp
 * @email wzj020109@163.com
 * @date 2022-02-23
 * @desc 主类
 */

#include "include/create.h"
#include "include/read_config.h"
#include <cstdlib>
#include <fmt/color.h>
#include <fmt/core.h>
#include <iostream>
#include <string>

#define LONG_CMD_INIT "init"
#define SHORT_CMD_INIT "i"

#define LONG_CMD_EDIT "edit"
#define SHORT_CMD_EDIT "e"

using namespace std;

void get_out()
{
  // 项目名
  char name[50];
  cout << "项目名: ";
  cin >> name;

  // 编程语言
  char lang[50];
  cout << "项目类型: ";
  cin >> lang;

  // 创建项目
  create(name, get_dirs(lang), get_files(lang), get_git(lang));
}

int main(int argc, char** argv)
{
  // 把命令参数转成 string 型
  string cmd = argv[1];

  if (argc == 2) {
    if (cmd == LONG_CMD_INIT || cmd == SHORT_CMD_INIT) {
      get_out();
    } else if (cmd == LONG_CMD_EDIT || cmd == SHORT_CMD_EDIT) {
      string edit = get_edit();
      edit.append(" ");
      edit.append(CONFIG_PATH);
      system(edit.data());
    } else {
      fmt::print(
          fg(fmt::color::crimson) | fmt::emphasis::bold,
          "参数无效\n");
    }
  } else if (argc > 2) {
    fmt::print(
        fg(fmt::color::ghost_white),
        "参数过多\n");
    exit(EXIT_SUCCESS);
  }
  return EXIT_SUCCESS;
}
