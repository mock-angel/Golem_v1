/*
 * ShaderResource.h
 *
 *  Created on: 26-Nov-2020
 *      Author: anantha
 */

#ifndef CORE_RESOURCE_SHADERRESOURCE_H_
#define CORE_RESOURCE_SHADERRESOURCE_H_

#include "Resource.h"
#include "Graphics/Shader/Shader.h"

namespace Golem {

class ShaderResource : public Resource{
public:

    Shader m_shader;
    ShaderResource();
    ~ShaderResource();

    virtual void onPrepare() override;
    virtual bool onLoad() override;
public:
    std::string m_vshaderData;
    std::string m_fshaderData;
    std::string m_gshaderData;

    int getShaderId(){
        return m_shader.getID();
    }
};

} /* namespace Golem */

#endif /* CORE_RESOURCE_SHADERRESOURCE_H_ */