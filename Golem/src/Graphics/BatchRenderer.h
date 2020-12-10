/*
 * BatchRenderer.h
 *
 *  Created on: 08-Dec-2020
 *      Author: anantha
 */

#ifndef GRAPHICS_BATCHRENDERER_H_
#define GRAPHICS_BATCHRENDERER_H_

#include <array>

#include "Core/Resource/ShaderResource.h"
#include "Graphics/Textures/Texture.h"
#include "Res/Scripts/Transform.h"

namespace Golem {

struct Vec2{
    float x, y;
};

struct Vec3{
    float x, y, z;
};

struct Vec4{
    float x, y, z, w;
};

struct Vertex{
    Vec3 Position;  //xyz
    Vec4 Color;     //Color RGBA
    Vec2 TexCoord;  //UV
    float TexIndex; //Texture
};



class Batch{

public:
    Batch();
    void Render();

    inline void SetShader(ShaderRef t_shader){ m_Shader = t_shader; }
    inline void CreateSquare(Transform& t_transform, Vec4 t_color){
        glm::mat4 matrixGen;
        matrixGen = {
                1.f,  1.f, 0.0f, 1.0f,
                1.f, -1.f, 0.0f, 1.0f,
               -1.f, -1.f, 0.0f, 1.0f,
               -1.f,  1.f, 0.0f, 1.0f,
        };
        glm::mat4 transformed = t_transform.getModelMatrix() * matrixGen;

        Vertex v0;
        v0.Position = {transformed[0][0], transformed[0][1], transformed[0][2]};
        v0.Color = t_color;
        v0.TexCoord = {1.0f, 1.0f,};
        v0.TexIndex = 0;

        Vertex v1;
        v1.Position = {transformed[1][0], transformed[1][1], transformed[1][2]};
        v1.Color = t_color;
        v1.TexCoord = {1.0f, 1.0f,};
        v1.TexIndex = 0;

        Vertex v2;
        v2.Position = {transformed[2][0], transformed[2][1], transformed[2][2]};
        v2.Color = t_color;
        v2.TexCoord = {1.0f, 1.0f,};
        v2.TexIndex = 0;

        Vertex v3;
        v3.Position = {transformed[3][0], transformed[3][1], transformed[3][2]};
        v3.Color = t_color;
        v3.TexCoord = {1.0f, 1.0f,};
        v3.TexIndex = 0;

        (m_VertexBuffer.at(m_CurrentVertexCount)) = v0;
        (m_VertexBuffer.at(m_CurrentVertexCount + 1)) = v1;
        (m_VertexBuffer.at(m_CurrentVertexCount + 2)) = v2;
        (m_VertexBuffer.at(m_CurrentVertexCount + 3)) = v3;

        m_CurrentVertexCount += 4;
        m_CurrentQuadCount++;
    }
private:
    static const int m_MaxQuadCount = 1000;
    static const int m_MaxVertexCount = m_MaxQuadCount * 4;
    static const int m_MaxIndexCount = m_MaxQuadCount * 6;

    uint32_t m_IndexBuffer[m_MaxIndexCount];
    std::array<Vertex, m_MaxIndexCount> m_VertexBuffer;
    int m_CurrentVertexCount = 0;
    int m_CurrentQuadCount = 0;

    unsigned int m_VAO;
    unsigned int m_VBO;
    unsigned int m_IBO;
    ShaderRef m_Shader;
    //Vertex m_VertexArray[m_MaxVertexCount];
    void _init();
};


class BatchRenderer {
public:
    BatchRenderer();
    ~BatchRenderer();

    void render();
};

} /* namespace Golem */

#endif /* GRAPHICS_BATCHRENDERER_H_ */
