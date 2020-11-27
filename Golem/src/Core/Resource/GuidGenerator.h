/*
 * GuidGenerator.h
 *
 *  Created on: 20-Nov-2020
 *      Author: anantha
 */

#ifndef CORE_RESOURCE_GUIDGENERATOR_H_
#define CORE_RESOURCE_GUIDGENERATOR_H_

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.

namespace Golem {

class GuidGenerator {
public:
    GuidGenerator();
    ~GuidGenerator();

    boost::uuids::uuid getUUID(){
        return gen();
    }

private:
    boost::uuids::random_generator gen;

};

} /* namespace Golem */

#endif /* CORE_RESOURCE_GUIDGENERATOR_H_ */
