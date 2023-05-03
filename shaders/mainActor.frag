#version 450

#define IDLE 0
#define RUN 1
#define ATTACK 2
#define DEATH 3

layout(location = 0) in vec3 fragColor;
layout(location = 1) in vec2 fragTexCoord;
layout(location = 2) in vec2 texCoord;
layout(location = 3) flat in int currentFrame;
layout(location = 4) flat in int currentAction;


layout(binding = 1) uniform sampler2D texIdle;
layout(binding = 2) uniform sampler2D texRun;
layout(binding = 3) uniform sampler2D texJump;
layout(binding = 4) uniform sampler2D texAttacks;
layout(binding = 5) uniform sampler2D texDeath;
layout(location = 0) out vec4 outColor;

float u_stretch_x = 0.5f;
float u_stretch_y = 0.25f;

const int idle = 0;
const int run = 1;
const int jump = 2;
const int attack = 3;
const int death = 4;

void main() {

    vec2 texCoordNew = vec2(fragTexCoord.x * u_stretch_x , fragTexCoord.y * u_stretch_y);

    switch(currentAction)
    {
        case idle:
        {
            switch(currentFrame)
            {
                case 0:
                {
                    // texCoordNew.xy += vec2(0.0f,0.0f);
                    break;
                }
                case 1:
                {
                    texCoordNew.xy += vec2(0.5f,0.0f);
                    break;
                }
                case 2:
                {
                    texCoordNew.xy += vec2(0.0f,0.25f);
                    break;
                }
                case 3:
                {
                    texCoordNew.xy += vec2(0.5f,0.25f);
                    break;
                }
                case 4:
                {
                    texCoordNew.xy += vec2(0.0f,0.5f);
                    break;
                }
                case 5:
                {
                    texCoordNew.xy += vec2(0.5f,0.5f);
                    break;
                }
                case 6:
                {
                    texCoordNew.xy += vec2(0.0f,0.75f);
                    break;
                }
                case 7:
                {
                    texCoordNew.xy += vec2(0.5f,0.75f);
                    break;
                }
            }
            vec4 FragColour = texture(texIdle, texCoordNew);
            if (/*FragColour.rgba == vec4(1.0f,1.0f,1.0f,1.0f) || */FragColour.a < 1.0f) discard;
            outColor = texture(texIdle, texCoordNew);
            break;
        }
        case run:
        {
            switch(currentFrame)
            {
                case 0:
                {
                    // texCoordNew.xy += vec2(0.0f,0.0f);
                    break;
                }
                case 1:
                {
                    texCoordNew.xy += vec2(0.5f,0.0f);
                    break;
                }
                case 2:
                {
                    texCoordNew.xy += vec2(0.0f,0.25f);
                    break;
                }
                case 3:
                {
                    texCoordNew.xy += vec2(0.5f,0.25f);
                    break;
                }
                case 4:
                {
                    texCoordNew.xy += vec2(0.0f,0.5f);
                    break;
                }
                case 5:
                {
                    texCoordNew.xy += vec2(0.5f,0.5f);
                    break;
                }
                case 6:
                {
                    texCoordNew.xy += vec2(0.0f,0.75f);
                    break;
                }
                case 7:
                {
                    texCoordNew.xy += vec2(0.5f,0.75f);
                    break;
                }
            }
            vec4 FragColour = texture(texRun, texCoordNew);
            if (FragColour.rgba == vec4(1.0f,1.0f,1.0f,1.0f) || FragColour.a < 1.0f) discard;
            outColor = texture(texRun, texCoordNew);
            break;
        }
        case jump:
        {
            switch(currentFrame)
            {
                case 0:
                {
                    // texCoordNew.xy += vec2(0.0f,0.0f);
                    break;
                }
                case 1:
                {
                    texCoordNew.xy += vec2(0.5f,0.0f);
                    break;
                }
                case 2:
                {
                    texCoordNew.xy += vec2(0.0f,0.25f);
                    break;
                }
                case 3:
                {
                    texCoordNew.xy += vec2(0.5f,0.25f);
                    break;
                }
                case 4:
                {
                    texCoordNew.xy += vec2(0.0f,0.5f);
                    break;
                }
                case 5:
                {
                    texCoordNew.xy += vec2(0.5f,0.5f);
                    break;
                }
                case 6:
                {
                    texCoordNew.xy += vec2(0.0f,0.75f);
                    break;
                }
                case 7:
                {
                    texCoordNew.xy += vec2(0.5f,0.75f);
                    break;
                }
            }
            vec4 FragColour = texture(texJump, texCoordNew);
            if (FragColour.rgba == vec4(1.0f,1.0f,1.0f,1.0f) || FragColour.a < 1.0f) discard;
            outColor = texture(texJump, texCoordNew);
            break;
        }
        case attack:
        {
            texCoordNew = vec2(fragTexCoord.x * 0.125 , fragTexCoord.y * 0.2);
        switch(currentFrame)
        {
            case 0:
            {
                // texCoordNew.xy += vec2(0.0f,0.0f);
                break;
            }
            case 1:
            {
                texCoordNew.xy += vec2(0.125f,0.0f);
                break;
            }
            case 2:
            {
                texCoordNew.xy += vec2(0.25f,0.0f);
                break;
            }
            case 3:
            {
                texCoordNew.xy += vec2(0.375f,0.0f);
                break;
            }
            case 4:
            {
                texCoordNew.xy += vec2(0.5f,0.0f);
                break;
            }
            case 5:
            {
                texCoordNew.xy += vec2(0.625f,0.0f);
                break;
            }
            case 6:
            {
                texCoordNew.xy += vec2(0.750f,0.0f);
                break;
            }
            case 7:
            {
                texCoordNew.xy += vec2(0.875f,0.0f);
                break;
            }
        }
        vec4 FragColour = texture(texAttacks, texCoordNew);
        if (FragColour.rgba == vec4(1.0f,1.0f,1.0f,1.0f) || FragColour.a < 1.0f) discard;
        outColor = texture(texAttacks, texCoordNew);
        break;
            break;
        }
        case death:
        {
            break;
        }
    }





}
