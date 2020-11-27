/*
 * MetaManager.h
 *
 *  Created on: 22-Nov-2020
 *      Author: anantha
 */

#ifndef CORE_RESOURCE_METAMANAGER_H_
#define CORE_RESOURCE_METAMANAGER_H_

#include <unordered_map>
#include <fstream>

#include "GuidGenerator.h"
#include "yaml-cpp/yaml.h"

namespace Golem {


class MetaData{
public:
    void load(const std::string& t_path){
        m_node = YAML::Load(t_path);

        m_UUID = m_node["UUID"].as<std::string>();
        m_loaded = true;
    }

    void create(const std::string& t_path){
        m_node = YAML::Node();
        m_node["UUID"] = "555";
        m_loaded = true;

        std::ofstream ofile;
        ofile<<m_node;
    }

    bool isLoaded(){
        return m_loaded;
    }
private:
    bool m_loaded = false;
    std::string m_fieldPath = nullptr;
    std::string m_metaPath = nullptr;

    std::string m_UUID = nullptr;
    YAML::Node m_node;
};

class MetaManager {
public:
    MetaManager();
    ~MetaManager();

    void checkAll();
    MetaData getMetaData(const std::string& t_uuid){

        if(m_metaMap.find(t_uuid)==m_metaMap.end())
            return MetaData();
        return m_metaMap[t_uuid];
    }
private:
    GuidGenerator m_GUIDgenerator;
    std::unordered_map<std::string, MetaData> m_metaMap;
};

} /* namespace Golem */

#endif /* CORE_RESOURCE_METAMANAGER_H_ */
