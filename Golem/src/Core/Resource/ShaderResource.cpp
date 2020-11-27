/*
 * ShaderResource.cpp
 *
 *  Created on: 26-Nov-2020
 *      Author: anantha
 */

#include "ShaderResource.h"

#include <map>


#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/error/en.h"


#include <nlohmann/json.hpp>

using namespace nlohmann;
#include "Graphics/Shader/ShaderData.h"

namespace Golem {

ShaderResource::ShaderResource() {
    // TODO Auto-generated constructor stub

}

ShaderResource::~ShaderResource() {
    // TODO Auto-generated destructor stub
}

void ShaderResource::onPrepare() {
    const char* data = getData().c_str();

    //replace_all(jsonString, "\n", "");
    //replace_all(jsonString, "\t", "");
    json j = json::parse(data);

    m_vshaderData = j["v_shader"];
    m_fshaderData = j["f_shader"];
    m_gshaderData = j["g_shader"];
    //ShaderInfo shaderInfo(filename, path, shader);
}
bool ShaderResource::onLoad() {
    m_shader = Shader(m_vshaderData.c_str(), m_fshaderData.c_str());
    return true;
}

} /* namespace Golem */
