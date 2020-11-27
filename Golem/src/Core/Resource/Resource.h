/*
 * Resource.h
 *
 *  Created on: 22-Nov-2020
 *      Author: anantha
 */

#ifndef CORE_RESOURCE_RESOURCE_H_
#define CORE_RESOURCE_RESOURCE_H_

#include "../LooseRef.h"
#include <fstream>
#include "Debug.h"
#include <filesystem>



namespace Golem {

enum LoadState{
    LOADSTATE_UNLOADED,
    LOADSTATE_PREPARED,
    LOADSTATE_LOADED,
};

class Resource;
//using ResourceRef = LooseRef<Resource>;
using ResourceRef = std::shared_ptr<Resource>;



class Resource {

public:
    Resource(const std::string& t_path){
        m_path = t_path;
    }
    Resource(){}
    virtual ~Resource(){

    }

    void prepare();

    void load(){
        if(m_loadState == LOADSTATE_LOADED) return;
        if(m_loadState == LOADSTATE_UNLOADED) prepare();
        if(m_loadState == LOADSTATE_PREPARED) {
            if(onLoad()){
                m_loadState = LOADSTATE_LOADED;
                m_data.clear();
            }

        }
    }

    virtual void unload(){
        onUnload();
        m_data.clear();

        m_loadState = LOADSTATE_UNLOADED;
    }

    virtual void onPrepare(){ }
    virtual bool onLoad(){ return true; }
    virtual void onUnload(){ }

protected:
    inline const std::string& getData(){
        return m_data;
    }
    inline const std::string& getPath(){
        return m_path;
    }
private:
    std::string m_path;
    std::string m_data;
    LoadState m_loadState = LOADSTATE_UNLOADED;


};

} /* namespace Golem */

#endif /* CORE_RESOURCE_RESOURCE_H_ */
