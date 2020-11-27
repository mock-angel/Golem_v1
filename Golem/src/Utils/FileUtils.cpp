/*
 * FileUtils.cpp
 *
 *  Created on: 27-Nov-2020
 *      Author: anantha
 */

#include "FileUtils.h"

#include <filesystem>
#include <fstream>

#include "Debug.h"

namespace Golem {

void FileUtils::loadFile(const std::string& t_path, std::string* t_data){
    int size = std::filesystem::file_size(t_path);
    (*t_data).clear();
    (*t_data).reserve(size);

    std::ifstream ifile(t_path);

    Debug::log("File before-Loaded capacity:", std::to_string(t_data->capacity()));
    t_data->assign((std::istreambuf_iterator<char>(ifile)), std::istreambuf_iterator<char>());
    Debug::log("File Loaded capacity:", std::to_string(t_data->capacity()));
    Debug::log("File Loaded size:", std::to_string(t_data->size()));
}

} /* namespace Golem */
