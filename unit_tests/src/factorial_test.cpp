/*
 * factorial_test.cpp
 *
 *  Created on: 31-Oct-2020
 *      Author: anantha
 */

#include "factorial.h"
#include "gtest/gtest.h"
#include <string>
#include <filesystem>
#include <iostream>
#include <fstream>

#include "yaml-cpp/yaml.h"

TEST(IntegerFunctionTest, negative) {
    EXPECT_EQ(1, factorial(-5));
    EXPECT_EQ(1, factorial(-1));
    EXPECT_GT(factorial(-10), 0);
}

TEST(IntegerFunctionTest, zero) {
     EXPECT_EQ(1, factorial(0));

     std::vector<YAML::Node> first = YAML::LoadAllFromFile("dotext");
     //YAML::Node second;
     //first["fileID"] = second;
     //first["terror"] = "there i go";
     //second["fileID"] = first;
     std::cout<<first.size();
     for(auto& g:first){
         switch (g.Type()) {
           case YAML::NodeType::Null: // ...
               std::cout<<"Null TYPE";
               break;
           case YAML::NodeType::Scalar: // ...
               std::cout<<"Scalar TYPE";
               break;
           case YAML::NodeType::Sequence: // ...
               std::cout<<"Sequence TYPE";
               break;
           case YAML::NodeType::Map:
               std::cout<<"Map TYPE";
               break;
           case YAML::NodeType::Undefined:
               std::cout<<"Undefined TYPE";
               break;
           default:break;
         };
     }

     std::ofstream file("dotext");
     for(auto& node: first){
         file<<node<<std::endl;
     }
     //file<<second;
}

TEST(IntegerFunctionTest, postive) {
     EXPECT_EQ(1, factorial(1));
     EXPECT_EQ(2, factorial(2));
     EXPECT_EQ(6, factorial(3));
     EXPECT_EQ(40320, factorial(8));
}

class N{
public:
    std::string m_Name;
    std::list<int> m_Components;


};

void operator <<(N& n, YAML::Node str){
    n.m_Name = str["m_Name"].as<std::string>();
    n.m_Components = str["m_Components"].as<std::list<int>>();
}
void operator >>(N& n, YAML::Node& str){
    str["m_Name"] = n.m_Name;
    str["m_Components"] = n.m_Components;
}

TEST(MyTestSuitName, MyTestCaseName) {


    int actual = 1;
    EXPECT_GT(actual, 0);
    EXPECT_EQ(1, actual) << "Should be equal to one";

    /*
    YAML::Emitter theEmitter;
    for (int i = 0; i < 2; ++i)
    {
        theEmitter << YAML::BeginDoc;
        //theEmitter  << YAML::LocalTag("The_Tag_" + std::to_string(i));
        theEmitter  << YAML::BeginSeq;
        theEmitter  << ("Some Value" + std::to_string(i));
        theEmitter  << ("Some Value2" + std::to_string(i));
        theEmitter  << YAML::EndSeq;
        theEmitter  << YAML::EndDoc;
    }*/
    //std::cout << theEmitter.c_str() << std::endl;

    std::vector<YAML::Node> first = YAML::LoadAllFromFile("test.yaml");

    std::list<int> nodes_li;
    std::list<int> components_li;

    std::cout << "m_NodesList" << std::endl;
    N nw;
    YAML::Node nnn;

    nw<<first[0]["2001"];
    nw>>nnn;
    for (YAML::iterator it = first[0]["m_NodesList"].begin(); it != first[0]["m_NodesList"].end(); ++it) {
        const YAML::Node& node = *it;
        nodes_li.push_back(node.as<int>());
        std::cout << node << std::endl;
    }

    for (YAML::iterator it = first[0]["m_ComponentsList"].begin(); it != first[0]["m_ComponentsList"].end(); ++it) {
        const YAML::Node& node = *it;
        components_li.push_back(node.as<int>());
        std::cout << node << std::endl;
    }
    std::cout<<nnn<<std::endl;
/*
    std::vector<std::string> f= first[0]["m_NodesList"].IsSequence();
    for(int i = 0 ; f.size(); i++){
        std::string id = f[i];
        li.push_back(id);
        std::cout << id << std::endl;
    }*/
/*
    std::cout << "m_ComponentsList" << std::endl;
    for( std::string id: first[0]["m_ComponentsList"]){
        li.push_back(id);
        std::cout << id << std::endl;
    }*/

}
