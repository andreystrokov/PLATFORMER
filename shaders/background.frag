#version 450

layout(location = 0) in vec3 fragColor;
layout(location = 1) in vec2 fragTexCoord;

layout(binding = 1) uniform sampler2D texSampler;

layout(location = 0) out vec4 outColor;
layout(location = 2) in vec2 texCoord;


void main() {

    vec4 FragColour = texture(texSampler, fragTexCoord);
    if (FragColour.rgba == vec4(0.0f,0.0f,0.0f,0.0f) || FragColour.a < 1.0f) discard;
//    if(FragColour.rgb == vec3(1.0,1.0,1.0)) discard;

    outColor = texture(texSampler, fragTexCoord);
}
