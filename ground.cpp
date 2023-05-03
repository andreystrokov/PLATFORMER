#include "ground.h"


void Ground::move()
{
    static int countSkippedFrames = 0;
    ++countSkippedFrames;
//    if((countSkippedFrames % 2) == 1)
//    {
        coords -= glm::vec2{0.003,0.0};
        COORDS_UBO ubo{coords,glm::vec3(0.0,0.0,0.0f)};

        for(int i = 0; i < 2; ++i)
        memcpy(this->uniformBuffersMapped[i],&ubo,sizeof(ubo));
}

void Ground::stay()
{
    COORDS_UBO ubo{coords,glm::vec3(0.0,1.2,0.0f)};
    for(int i = 0; i < 2; ++i)
        memcpy(this->uniformBuffersMapped[i],&ubo,sizeof(ubo));
}
