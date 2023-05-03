#version 450

//layout(binding = 0) uniform UniformBufferObject {
//    mat4 model;
//    mat4 view;
//    mat4 proj;
//} ubo;

layout(binding = 0) uniform COORDS_UBO {
    vec2 coords;
    vec2 texCoord;
    int currentFrame;
    int currentAction;
} uboObj;

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inColor;
layout(location = 2) in vec2 inTexCoord;


layout(location = 0) out vec3 fragColor;
layout(location = 1) out vec2 fragTexCoord;

layout(location = 2) out vec2 texCoord;
layout(location = 3) out int currentFrame;
layout(location = 4) out int currentAction;

void main() {
//    vec2 coords = uboObj.coords;
//    if(uboObj.texCoord == vec2(1.0,1.0))
//    {
        gl_Position = vec4(inPosition+vec3(uboObj.coords,0.0), 1.0);
//        fragColor = inColor;
        fragTexCoord = inTexCoord;
        texCoord = uboObj.texCoord;
        currentFrame = uboObj.currentFrame;
        currentAction = uboObj.currentAction;

//    }
}

