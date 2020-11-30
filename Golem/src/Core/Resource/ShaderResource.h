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
    ShaderResource(const std::string& str);
    ~ShaderResource();

    virtual void onPrepare() override;
    virtual bool onLoad() override;
public:
    std::string m_vshaderData;
    std::string m_fshaderData;
    std::string m_gshaderData;

    inline int getShaderId(){
        return m_shader.getID();
    }
};

using ShaderRef = std::shared_ptr<ShaderResource>;

} /* namespace Golem */

#endif /* CORE_RESOURCE_SHADERRESOURCE_H_ */
