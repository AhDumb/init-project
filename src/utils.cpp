/**
 * @author aaron
 * @version 1.0
 * @fileName utils.cpp
 * @email wzj020109@163.com
 * @date 2022-02-25
 * @desc 工具
 */


#include <cstddef>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <unistd.h>
#include "utils.h"

using namespace std;

/* 分割字符串 */
vector<string> split(const string &str, const string &pattern)
{
  vector<string> res;
  if ( str == "" ) {
    return res;
  }

  string strs = str + pattern;
  size_t pos = strs.find(pattern);

  while ( pos != strs.npos ) {
    string temp = strs.substr(0, pos);
    res.push_back(temp);
    strs = strs.substr(pos + 1, strs.size());
    pos = strs.find(pattern);
  }
  return res;
}
