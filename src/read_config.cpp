/**
 * @author aaron
 * @version 1.0
 * @fileName read_config.cpp
 * @email wzj020109@163.com
 * @date 2022-02-23
 * @desc 读取配置文件
 */

#include "include/read_config.h"
#include <cstdlib>
#include <fmt/color.h>
#include <iostream>
#include <string>
#include <yaml-cpp/exceptions.h>
#include <yaml-cpp/yaml.h>

using namespace std;

/* 获取文件 */
string get_files(const string& lang)
{
  try {
    YAML::Node config = YAML::LoadFile(CONFIG_PATH);
    if (config[lang].IsDefined()) {
      return config[lang]["files"].as<string>();
    } else {
      fmt::print(
          fg(fmt::color::steel_blue),
          "为配置 {} 模板 \n", lang);
      fmt::print(
          fg(fmt::color::green),
          "配置文件在 ~/.config/init-project/config.yaml\n");
      exit(EXIT_SUCCESS);
    }
  } catch (const YAML::Exception& e) {
    fmt::print(
        fg(fmt::color::crimson) | fmt::emphasis::bold,
        "配置文件异常\n");
    exit(EXIT_SUCCESS);
  }
}

/* 获取文件夹 */
string get_dirs(const string& lang)
{
  try {
    YAML::Node config = YAML::LoadFile(CONFIG_PATH);
    if (config[lang].IsDefined()) {
      return config[lang]["dirs"].as<string>();
    } else {
      fmt::print(
          fg(fmt::color::steel_blue),
          "为配置 {}\n", lang);
      fmt::print(
          fg(fmt::color::green),
          "配置文件在 ~/.config/init-project/config.yaml\n");
      exit(EXIT_SUCCESS);
    }
  } catch (const YAML::Exception& e) {
    fmt::print(
        fg(fmt::color::crimson) | fmt::emphasis::bold,
        "配置文件异常\n");
    exit(EXIT_SUCCESS);
  }
}

/* 获取Git状态 */
bool get_git(const string& lang)
{
  try {
    YAML::Node config = YAML::LoadFile(CONFIG_PATH);
    if (config[lang].IsDefined()) {
      return config[lang]["git"].as<bool>();
    } else {
      return false;
    }
  } catch (const YAML::Exception& e) {
    fmt::print(
        fg(fmt::color::crimson) | fmt::emphasis::bold,
        "配置文件异常");
    exit(EXIT_SUCCESS);
  }
}

/* 获取编辑器 */
string get_edit()
{
  try {
    YAML::Node config = YAML::LoadFile(CONFIG_PATH);
    if (config["os"]["edit"].IsDefined()) {
      return config["os"]["edit"].as<string>();
    } else {
      return "vim";
    }
  } catch (const YAML::Exception& e) {
    fmt::print(
        fg(fmt::color::crimson) | fmt::emphasis::bold,
        "配置文件异常\n");
    exit(EXIT_SUCCESS);
  }
}
