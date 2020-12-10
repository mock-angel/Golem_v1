/*
 * BatchRenderer.cpp
 *
 *  Created on: 08-Dec-2020
 *      Author: anantha
 */

#include "BatchRenderer.h"

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <glm/glm.hpp>
#include <SDL2/SDL_opengl.h>

#include "Core/Resource/ResourceManager.h"
#include "Debug.h"
#include "Game.h"

namespace Golem {

Batch::Batch(){
    _init();
}

void Batch::_init(){
    int offset = 0;
    for(int i = 0; i < m_MaxIndexCount; i+=6, offset+=4){
        m_IndexBuffer[i + 0] = offset + 0;
        m_IndexBuffer[i + 1] = offset + 1;
        m_IndexBuffer[i + 2] = offset + 2;
        m_IndexBuffer[i + 3] = offset + 2;
        m_IndexBuffer[i + 4] = offset + 3;
        m_IndexBuffer[i + 5] = offset + 0;
    }

    float vertices[] = {
            // positions          // colors                 // texture coords
             1.f,  1.f, 0.0f,   1.0f, 0.0f, 0.0f, 1.0f,   1.0f, 1.0f,   0.0f, // top right
             1.f, -1.f, 0.0f,   0.0f, 1.0f, 0.0f, 1.0f,   1.0f, 0.0f,   0.0f, // bottom right
            -1.f, -1.f, 0.0f,   0.0f, 0.0f, 1.0f, 1.0f,   0.0f, 0.0f,   0.0f, // bottom left
            -1.f,  1.f, 0.0f,   1.0f, 1.0f, 0.0f, 1.0f,   0.0f, 1.0f,   0.0f, // top left
    };

    Transform t1;
    //t1.position.Vector3(0, 0, 0);
    t1.scale = Vector3(0.2, 0.2, 0.2);
    t1.position = Vector3(-0.3, 0, 0);
    CreateSquare(t1, {1.0f, 0.0f, 0.0f, 1.0f,});

    //t1.scale = Vector3(0.2, 0.2, 0.2);
    t1.position = Vector3(0.3, 0, 0);
    CreateSquare(t1, {1.0f, 0.0f, 0.0f, 1.0f,});

    CreateSquare(t1, {1.0f, .5f, 0.0f, 1.0f,});

    glCreateVertexArrays(1, &m_VAO);
    glBindVertexArray(m_VAO);

    glCreateBuffers(1, &m_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(m_VertexBuffer), m_VertexBuffer.data(), GL_STATIC_DRAW);

    glEnableVertexArrayAttrib(m_VAO, 0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 10 * sizeof(float), (const void*) (offsetof(Vertex, Position)));
    //glEnableVertexAttribArray(0);

    glEnableVertexArrayAttrib(m_VAO, 1);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 10 * sizeof(float), (const void*) (offsetof(Vertex, Color)));
    //glEnableVertexAttribArray(1);

    uint32_t indices[] = {
            0, 1, 2, 2, 3, 0,
            4, 5, 6, 6, 7, 4,
            8, 9, 10, 10, 11, 8,
    };

    glCreateBuffers(1, &m_IBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_IndexBuffer), m_IndexBuffer, GL_STATIC_DRAW);

    m_Shader = ResourceManager::getInstance()->getResource<ShaderResource>("/home/anantha/Desktop/GitHub/Golem/Golem/src/Res/Shaders/DefaultShaderBatch.shader");
    //Debug::log("Batch Created");
}

void Batch::Render(){

    //glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(m_Shader->getShaderId());

    glm::mat4 projView_matrix = Game::getCamera().getClipMatrix();
    m_Shader->m_shader.setMat4("clip", projView_matrix );

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBindVertexArray(m_VAO);
    glDrawElements(GL_TRIANGLES, m_CurrentQuadCount*6, GL_UNSIGNED_INT, nullptr);
    //glBindVertexArray(0);
    //Debug::log("Batch Rendered");
}

BatchRenderer::BatchRenderer() {
    // TODO Auto-generated constructor stub

}

BatchRenderer::~BatchRenderer() {
    // TODO Auto-generated destructor stub
}

} /* namespace Golem */
