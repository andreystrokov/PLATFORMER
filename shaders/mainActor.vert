#version 450

//layout(binding = 0) uniform UniformBufferObject {
//    mat4 model;
//    mat4 view;
//    mat4 proj;
//} ubo;

layout(binding = 0) uniform COORDS_UBO {
    vec2 coords;
    vec2 texCoord;
} uboObj;

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inColor;
layout(location = 2) in vec2 inTexCoord;


layout(location = 0) out vec3 fragColor;
layout(location = 1) out vec2 fragTexCoord;

layout(location = 2) out vec2 texCoord;

void main() {
//    vec2 coords = uboObj.coords;
//    if(uboObj.texCoord == vec2(1.0,1.0))
//    {
        gl_Position = /*ubo.proj * ubo.view * ubo.model **/ vec4(inPosition+vec3(uboObj.coords,0.0), 1.0);
//        fragColor = inColor;
        fragTexCoord = inTexCoord;
        texCoord = uboObj.texCoord;
//    }
}
