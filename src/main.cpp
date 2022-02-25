/**
 * @author aaron
 * @version 1.0
 * @fileName main.cpp
 * @email wzj020109@163.com
 * @date 2022-02-23
 * @desc 主类
 */

#include <iostream>
#include "read_config.h"
#include "create.h"

using namespace std;

int main(int argc, char** argv)
{
  if ( argc < 2 ) {
    cout << "参数过少" << endl;
  } else if ( argc == 2 ) {
    char lang[50];
    char name[50];
    cout << "项目名: ";
    cin >> name;
    cout << "项目类型: ";
    cin >> lang;
    create(name, get_dirs(lang), get_files(lang), get_git(lang));
  } else if ( argc > 2 ) {
    cout << "参数过多" << endl;
  }
}
