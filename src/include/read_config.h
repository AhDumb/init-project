#include <iostream>
#include <string>
//#define CONFIG_PATH "/home/aaron/Source-Codes/CppLang/init-project/config.yaml"
#define CONFIG_PATH "/home/aaron/.config/init-project/config.yaml"

using namespace std;

/* 获取文件 */
string get_files(const string& lang);

/* 获取文件夹 */
string get_dirs(const string& lang);

/* 获取Git状态 */
bool get_git(const string& lang);

/* 获取编辑器 */
string get_edit();
