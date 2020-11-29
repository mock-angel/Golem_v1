/*
 * ClassUtils.h
 *
 *  Created on: 28-Nov-2020
 *      Author: anantha
 */

#ifndef UTILS_CLASSUTILS_H_
#define UTILS_CLASSUTILS_H_

#include <type_traits>

namespace Golem {

class ClassUtils {
public:
    ClassUtils();
    ~ClassUtils();

    template<class Base, class T>
    static inline bool instanceof() {
       return std::is_base_of<Base, T>::value;
    }
    template<typename Base, typename T>
    static inline bool instanceof(const T*) {
       return std::is_base_of<Base, T>::value;
    }
};

} /* namespace Golem */

#endif /* UTILS_CLASSUTILS_H_ */
