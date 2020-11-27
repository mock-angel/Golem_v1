/*
 * DirectoryScanner.h
 *
 *  Created on: 24-Nov-2020
 *      Author: anantha
 */

#ifndef CORE_RESOURCE_DIRECTORYSCANNER_H_
#define CORE_RESOURCE_DIRECTORYSCANNER_H_

#include <filesystem>

namespace Golem {

class DirectoryTree;

class DirectoryScanner {
public:
    DirectoryScanner();
    ~DirectoryScanner();

    void scan(const std::filesystem::path& path, const DirectoryTree& dirTree);
};

} /* namespace Golem */

#endif /* CORE_RESOURCE_DIRECTORYSCANNER_H_ */
