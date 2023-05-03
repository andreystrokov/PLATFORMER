#include "background.h"
#include <string.h>

void Background::run()
{
    static int countSkippedFrames = 0;
    ++countSkippedFrames;
    if((countSkippedFrames % 3) == 1)
    {
        coords -= glm::vec2{0.01,0.0};
        COORDS_UBO ubo{coords,glm::vec3(0.0,0.0,0.0f)};

        for(int i = 0; i < 2; ++i)
        memcpy(this->uniformBuffersMapped[i],&ubo,sizeof(ubo));
//        std::cout << countSkippedFrames << std::endl;
    }
}

void Background::runFar()
{
    static int countSkippedFrames = 0;
    ++countSkippedFrames;
//    if((countSkippedFrames % 2) == 1)
//    {
        coords -= glm::vec2{0.001,0.0};
        COORDS_UBO ubo{coords,glm::vec3(0.0,0.0,0.0f)};

        for(int i = 0; i < 2; ++i)
        memcpy(this->uniformBuffersMapped[i],&ubo,sizeof(ubo));
//        std::cout << countSkippedFrames << std::endl;
//    }
}

void Background::runMid()
{
    static int countSkippedFrames = 0;
    ++countSkippedFrames;
//    if((countSkippedFrames % 2) == 1)
//    {
        coords -= glm::vec2{0.002,0.0};
        COORDS_UBO ubo{coords,glm::vec3(0.0,0.0,0.0f),0,0};

        for(int i = 0; i < 2; ++i)
        memcpy(this->uniformBuffersMapped[i],&ubo,sizeof(ubo));
//        std::cout << countSkippedFrames << std::endl;
//    }
}

void Background::runClose()
{
    static int countSkippedFrames = 0;
    ++countSkippedFrames;
//    if((countSkippedFrames % 2) == 1)
//    {
        coords -= glm::vec2{0.003,0.0};
        COORDS_UBO ubo{coords,glm::vec3(0.0,0.0,0.0f),0,0};

        for(int i = 0; i < 2; ++i)
        memcpy(this->uniformBuffersMapped[i],&ubo,sizeof(ubo));
//        std::cout << countSkippedFrames << std::endl;
//    }
}

void Background::stay()
{
    COORDS_UBO ubo{coords,glm::vec3(0.0,1.2,0.0f),0,0};
    for(int i = 0; i < 2; ++i)
        memcpy(this->uniformBuffersMapped[i],&ubo,sizeof(ubo));
}
