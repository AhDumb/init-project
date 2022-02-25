/**
 * @author aaron
 * @version 1.0
 * @fileName read_config.cpp
 * @email wzj020109@163.com
 * @date 2022-02-23
 * @desc 读取配置文件
 */

#include "read_config.h"
#include "yaml-cpp/yaml.h"
#include <iostream>
#include <string>
#include <yaml-cpp/exceptions.h>

using namespace std;

/* 获取文件 */
string get_files(const string& lang)
{
  try {
    YAML::Node config = YAML::LoadFile(CONFIG_PATH);
    if ( config[lang].IsDefined() ) {
      return config[lang]["files"].as<string>();
    } else {
      return "为配置 " + lang + " 语言";
    }
  } catch (const YAML::Exception& e) {
    return "配置文件异常";
  }
}

/* 获取文件夹 */
string get_dirs(const string& lang)
{
  try {
    YAML::Node config = YAML::LoadFile(CONFIG_PATH);
    if ( config[lang].IsDefined() ) {
      return config[lang]["dirs"].as<string>();
    } else {
      return "为配置 " + lang + " 语言";
    }
  } catch ( const YAML::Exception& e ) {
    return "配置文件异常";
  }
}

/* 获取Git状态 */
bool get_git(const string &lang)
{
  try {
    YAML::Node config = YAML::LoadFile(CONFIG_PATH);
    if ( config[lang].IsDefined() ) {
      return config[lang]["git"].as<bool>();
    } else {
      return false;
    }
  } catch ( const YAML::Exception& e ) {
    return "配置文件异常";
  }
}
