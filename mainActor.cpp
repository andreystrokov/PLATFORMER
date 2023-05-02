#include "mainActor.h"
#include <string.h>
#include <iostream>

void MainActor::runRight()
{
    static int countSkippedFrames = 0;
    ++countSkippedFrames;
    if((countSkippedFrames % 5) == 1)
    {
//        coords += glm::vec3{0.01,0.0,0.0};
            COORDS_UBO ubo{coords,glm::vec3(0.0,1.2,0.0f)};

            switch(currentFrameRun)
            {
                case 0:
                {
                    ubo.texCoord = glm::vec3(0.0,2.7,0.0f);
                    ++currentFrameRun;
                    break;
                }
                case 1:
                {
                    ubo.texCoord = glm::vec3(1.3,2.7,0.0f);
                    ++currentFrameRun;
                    break;
                }
                case 2:
                {
                    ubo.texCoord = glm::vec3(2.5,2.7,0.0f);
                    ++currentFrameRun;
                    break;
                }
                case 3:
                {
                    ubo.texCoord = glm::vec3(3.6,2.7,0.0f);
                    ++currentFrameRun;
                    break;
                }
                case 4:
                {
                    ubo.texCoord = glm::vec3(4.7,2.7,0.0f);
                    ++currentFrameRun;
                    break;
                }
                case 5:
                {
                    ubo.texCoord = glm::vec3(5.8,2.7,0.0f);
                    ++currentFrameRun;
                    break;
                }
                case 6:
                {
                    ubo.texCoord = glm::vec3(7.0,2.75,0.0f);
                    ++currentFrameRun;
                    break;
                }
                case 7:
                {
                    ubo.texCoord = glm::vec3(8.2,2.75,0.0f);
                    ++currentFrameRun;
                    break;
                }
                case 8:
                {
                    ubo.texCoord = glm::vec3(9.3,2.75,0.0f);
                    ++currentFrameRun;
                    break;
                }
                case 9:
                {
                    ubo.texCoord = glm::vec3(10.4,2.7,0.0f);
                    currentFrameRun = 0;
                    break;
                }
            }
    //        }
    //        else
    //        {
    //            ubo.texCoord = glm::vec2(0.0,1.2);
    //            changed = 0;
    //        }

        for(int i = 0; i < 2; ++i)
        memcpy(this->uniformBuffersMapped[i],&ubo,sizeof(ubo));
        std::cout << countSkippedFrames << std::endl;
    }

}

void MainActor::stay()
{
    if(onFlight)
    {
        static int countSkippedFrames = 0;
        ++countSkippedFrames;
        if((countSkippedFrames % 25) == 1)
        {
            COORDS_UBO ubo{coords,glm::vec3(0.0,1.2,0.0f)};
            switch(currentFrameJump)
            {
            case 0:
            {
                ubo.texCoord = glm::vec2(0.0,1.2);
                ++currentFrameJump;
                break;
            }
            case 1:
            {
                ubo.texCoord = glm::vec2(0.8,1.2);
                ++currentFrameJump;
                break;
            }
            case 2:
            {
                ubo.texCoord = glm::vec2(1.7,1.2);
                ++currentFrameJump;
                break;
            }
            case 3:
            {
                ubo.texCoord = glm::vec2(2.58,1.2);
                ++currentFrameJump;
                break;
            }
            case 4:
            {
                ubo.texCoord = glm::vec2(3.5,1.25);
                ++currentFrameJump;
                break;
            }
            case 5:
            {
                ubo.texCoord = glm::vec2(4.4,1.2);
                ++currentFrameJump;
                break;
            }
            case 6:
            {
                ubo.texCoord = glm::vec2(5.245,1.2);
                ++currentFrameJump;
                break;
            }
            case 7:
            {
                ubo.texCoord = glm::vec2(6.1,1.2);
                ++currentFrameJump;

                break;
            }
            case 8:
            {
                ubo.texCoord = glm::vec2(7.0,1.31);
                ++currentFrameJump;
                currentFrameJump=0;
                onFlight = false;
                break;
            }
            case 9:
            {
                ubo.texCoord = glm::vec2(8.0,1.3);
                ++currentFrameJump;
                break;
            }
            case 10:
            {
                ubo.texCoord = glm::vec2(8.8,1.2);
                ++currentFrameJump;
                break;
            }
            case 11:
            {
                ubo.texCoord = glm::vec2(0.0,1.2);
                currentFrameJump=0;
                onFlight = false;
                break;
            }
        }
        for(int i = 0; i < 2; ++i)
            memcpy(this->uniformBuffersMapped[i],&ubo,sizeof(ubo));
        }
        std::cout << currentFrameJump << std::endl;
        return;
    }
    currentFrameRun = 0;
    COORDS_UBO ubo{coords,glm::vec3(0.0,1.2,0.0f)};

    for(int i = 0; i < 2; ++i)
        memcpy(this->uniformBuffersMapped[i],&ubo,sizeof(ubo));

}

void MainActor::jump()
{
    onFlight = true;

}
