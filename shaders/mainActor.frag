#version 450

layout(location = 0) in vec3 fragColor;
layout(location = 1) in vec2 fragTexCoord;
layout(location = 2) in vec2 texCoord;
layout(binding = 1) uniform sampler2D texSampler;
layout(binding = 2) uniform sampler2D texIdle;
layout(binding = 3) uniform sampler2D texRun;
layout(binding = 3) uniform sampler2D texAttacks;
layout(location = 0) out vec4 outColor;

void main() {


    vec2 newCoords = fragTexCoord;

    newCoords += texCoord;

    newCoords.y *= 0.15;
    newCoords.x *= 0.09;

//    vec4 FragColour = texture(texSampler, newCoords);
    if (FragColour.rgba == vec4(0.0f,0.0f,0.0f,0.0f) || FragColour.a < 1.0f) discard;

    outColor = texture(texSampler, newCoords);

}
