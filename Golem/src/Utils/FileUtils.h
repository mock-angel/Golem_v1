/*
 * FileUtils.h
 *
 *  Created on: 27-Nov-2020
 *      Author: anantha
 */

#ifndef UTILS_FILEUTILS_H_
#define UTILS_FILEUTILS_H_

#include <string>

namespace Golem {


class FileUtils{
public:
    static void loadFile(const std::string& t_path, std::string* t_data);

private:
};

} /* namespace Golem */

#endif /* UTILS_FILEUTILS_H_ */
