#pragma once
#include <string>
#include <unordered_map>
#include <glm/glm.hpp>   //glm中包含矩阵变换

/*OpenGL着色器内容*/

class Shader   
{
public:
    ~Shader();
    void Bind() const;  //绑定
    void Unbind() const;

    void create(const std::string vsPath, const std::string fsPath);

    //uniform变量
    void SetUniform1i(const std::string& name, int value);
    void SetUniform1f(const std::string& name, float value);
    void SetUniform3f(const std::string& name, float v0, float v1, float v2);
    void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
    void SetUniformMat4f(const std::string& name, const glm::mat4& matrix);

private:
    std::string parseShader(const std::string& filepath);
    unsigned int compileShader(unsigned int type, const std::string& source);  //编译着色器
    unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader);  //创建着色器对象
    int GetUniformLocation(const std::string& name);
private:
    unsigned int rendererID;

    // Cache uniform variable's location
    // Get the location from GPU is comparatively time-consuming
    std::unordered_map<std::string, int> uniformLocationCache;
};