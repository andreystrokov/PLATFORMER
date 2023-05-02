#version 450

layout(binding = 0) uniform COORDS_UBO {
    vec2 coords;
    vec3 texCoord;
} uboObj;

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inColor;
layout(location = 2) in vec2 inTexCoord;


layout(location = 0) out vec3 fragColor;
layout(location = 1) out vec2 fragTexCoord;

layout(location = 2) out vec2 texCoord;

void main() {
    gl_Position = vec4(inPosition, 1.0);
//    fragColor = inColor;
    fragTexCoord = inTexCoord+uboObj.coords;
}
