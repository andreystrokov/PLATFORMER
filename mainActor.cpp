#include "mainActor.h"
#include <string.h>
#include <iostream>

void MainActor::runRight()
{
    isIdle = false;
    isRun = true;
}

void MainActor::computeXY()
{
    if(!isOnGround)
    {
        static int countSkippedFrames = 0;
        ++countSkippedFrames;
        if((countSkippedFrames % 3) == 1)
        {
    //        coords += glm::vec3{0.01,0.0,0.0};
            coords.y += velocityY;
            velocityY += GRAVITY;
            if(coords.y > ground)
            {
                isOnGround = true;
                coords.y = ground;
                currentFrameJump = 0;
                COORDS_UBO ubo{coords,glm::vec3(0.0,1.2,0.0f),currentFrameJump,MainActor::JUMP};
                for(int i = 0; i < 2; ++i)
                memcpy(this->uniformBuffersMapped[i],&ubo,sizeof(ubo));
                return;
            }

            COORDS_UBO ubo{coords,glm::vec3(0.0,1.2,0.0f),currentFrameJump,MainActor::JUMP};
            if(currentFrameJump < 7)
            {

                this->currentFrameJump++;
            }
            else
            {
                this->currentFrameJump = 0;
            }
            for(int i = 0; i < 2; ++i)
            memcpy(this->uniformBuffersMapped[i],&ubo,sizeof(ubo));
//            std::cout << countSkippedFrames << std::endl;
        }
        return;
    }
    if(isAttack)
    {
        static int countSkippedFrames = 0;
        ++countSkippedFrames;
        if((countSkippedFrames % 5) == 1)
        {
    //        coords += glm::vec3{0.01,0.0,0.0};
            COORDS_UBO ubo{coords,glm::vec3(0.0,1.2,0.0f),currentFrameAttack,MainActor::ATTACK};
            if(currentFrameAttack < 7)
            {
                ++this->currentFrameAttack;
            }
            else
            {
                isAttack = false;
                this->currentFrameAttack = 0;
            }

            for(int i = 0; i < 2; ++i)
            memcpy(this->uniformBuffersMapped[i],&ubo,sizeof(ubo));
//            std::cout << countSkippedFrames << std::endl;
        }
        return;
    }
    if(isRun && isOnGround && !isAttack)
    {
        static int countSkippedFrames = 0;
        ++countSkippedFrames;
        if((countSkippedFrames % 5) == 1)
        {
    //        coords += glm::vec3{0.01,0.0,0.0};
            COORDS_UBO ubo{coords,glm::vec3(0.0,1.2,0.0f),currentFrameRun,MainActor::RUN};
            if(currentFrameRun < 7)
                ++this->currentFrameRun;
            else
                this->currentFrameRun = 0;

            for(int i = 0; i < 2; ++i)
            memcpy(this->uniformBuffersMapped[i],&ubo,sizeof(ubo));
//            std::cout << countSkippedFrames << std::endl;
        }
    }
    if(isIdle)
    {
        COORDS_UBO ubo{coords,glm::vec3(0.0,1.2,0.0f),currentFrameIdle,MainActor::IDLE};
        if(isIdle)
        {
            static int countSkippedFrames = 0;
            ++countSkippedFrames;
            if((countSkippedFrames % 5) == 1)
            {
                if(currentFrameIdle < 7)
                    ++this->currentFrameIdle;
                else
                    this->currentFrameIdle = 0;
            }
//            std::cout << currentFrameIdle << std::endl;
        }

        for(int i = 0; i < 2; ++i)
            memcpy(this->uniformBuffersMapped[i],&ubo,sizeof(ubo));
    }
}

void MainActor::stay()
{
    if(isOnGround)
       isIdle = true;
}

void MainActor::jump()
{
    if(isOnGround)
    {
        isIdle = false;
        isOnGround = false;
        velocityY = JUMP_VELOCITY;
    }
}

void MainActor::attack()
{
    if(!isAttack)
    {
        isIdle = false;
        isRun = false;
        isAttack = true;
    }
}
