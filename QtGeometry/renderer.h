#pragma once
#include "vertexarray.h"
#include "indexbuffer.h"
#include "shader.h"
#include "texture.h"

#include <vector>

class Renderer {
public:
    void Clear() const;
    void DrawPoint(const VertexArray* vao, const IndexBuffer* ibo, Shader& pointShader);
    void DrawLine(const VertexArray* vao, const IndexBuffer* ibo, Shader& lineShader);
    void DrawPolygon(const VertexArray* vao, const IndexBuffer* ibo, Shader& polygonShader);
    void DrawPolygonBorder(const VertexArray* vao, Shader& borderShader);
    void DrawTexture(const VertexArray* vao, const IndexBuffer* ibo,
        const std::vector<Texture*>& texs, Shader& textureShader);
private:
};