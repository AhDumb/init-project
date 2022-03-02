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

/**
 * 长命令
 */
#define LONG_CMD_INIT "init"
#define LONG_CMD_EDIT "edit"
#define LONG_CMD_HELP "--help"
#define LONG_CMD_VERSION "--version"
/**
 * 短命令
 */
#define SHORT_CMD_INIT "i"
#define SHORT_CMD_EDIT "e"
#define SHORT_CMD_HELP "-h"
#define SHORT_CMD_VERSION "-v"

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

void print_help()
{
  fmt::print("\t\t\t\t初始化项目\n");
  fmt::print("用法:\n");
  fmt::print("code \t初始化项目\n");
  fmt::print("短命令: \n");
  fmt::print("  code i \t\t初始化项目\n");
  fmt::print("  code e \t\t编辑配置文件\n");
  fmt::print("  code -h \t\t查看帮助文档\n");
  fmt::print("  code -v \t\t查看版本\n");
  fmt::print("长命令: \n");
  fmt::print("  code init \t\t初始化项目\n");
  fmt::print("  code edit \t\t编辑配置文件\n");
  fmt::print("  code --help \t\t查看帮助文档\n");
  fmt::print("  code --version \t\t查看版本\n");
}

int main(int argc, char** argv)
{

  if (argc == 1) {
    get_out();
  } else if (argc == 2) {
    // 把命令参数转成 string 型
    string cmd = argv[1];

    if (cmd == LONG_CMD_INIT || cmd == SHORT_CMD_INIT) {
      get_out();
    } else if (cmd == LONG_CMD_EDIT || cmd == SHORT_CMD_EDIT) {
      string edit = get_edit();
      edit.append(" ");
      edit.append(CONFIG_PATH);
      system(edit.data());
    } else if (cmd == LONG_CMD_HELP || cmd == SHORT_CMD_HELP) {
      print_help();
    } else if (cmd == LONG_CMD_VERSION || cmd == SHORT_CMD_VERSION) {
      fmt::print(
          fg(fmt::color::light_green),
          "版本: {:.1f}\n", 1.0);
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
  } else {
    fmt::print("请输入 code -help\n");
  }

  return EXIT_SUCCESS;
}
