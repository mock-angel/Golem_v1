/*
 * ShaderResource.cpp
 *
 *  Created on: 26-Nov-2020
 *      Author: anantha
 */

#include "ShaderResource.h"

#include <map>

#include <nlohmann/json.hpp>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/error/en.h"
#include "Graphics/Shader/ShaderData.h"
#include "Utils/FileUtils.h"

using namespace nlohmann;

namespace Golem {

ShaderResource::ShaderResource() {
    // TODO Auto-generated constructor stub

}

ShaderResource::ShaderResource(const std::string& str) : Resource(str){

}

ShaderResource::~ShaderResource() {
    // TODO Auto-generated destructor stub
}

void ShaderResource::onPrepare() {
    const char* data = getData().c_str();

    //replace_all(jsonString, "\n", "");
    //replace_all(jsonString, "\t", "");
    json j = json::parse(data);
    const std::string& vshaderPath = j["v_shader"];
    const std::string& fshaderPath = j["f_shader"];
    const std::string& gshaderPath = j["g_shader"];
    m_vshaderData.clear();
    m_fshaderData.clear();
    m_gshaderData.clear();
    FileUtils::loadFile(vshaderPath, &m_vshaderData);
    FileUtils::loadFile(fshaderPath, &m_fshaderData);


}

bool ShaderResource::onLoad() {
    m_shader = Shader(m_vshaderData.c_str(), m_fshaderData.c_str());
    return true;
}

} /* namespace Golem */
