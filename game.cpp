#include "game.h"

GAME::GAME()
{

}

void GAME::init()
{
      initObjects();
      rnd.setObjectsPtr(objects);
      rnd.init();
      keyController = controller::Ref();
      audioModule = new audio;
      audioThread = new QThread;
      QObject::connect(audioThread,&QThread::started,audioModule,&audio::play);
      audioModule->moveToThread(audioThread);
//      audioThread->start();
}
void GAME::initObjects()
{

    objects = new std::vector<VulkanObject*>;

    background = new Background(verticesWall,
                                indicesWall,
                                "./textures/background/parallax-demon-woods-bg.png",
                                "./shaders/background_vert.spv",
                                "./shaders/background_frag.spv");
    objects->push_back(background);
    farTrees = new Background(verticesFarTrees,
                                indicesWall,
                                "./textures/background/parallax-demon-woods-far-trees.png",
                                "./shaders/background_vert.spv",
                                "./shaders/background_frag.spv");
    objects->push_back(farTrees);
    midTrees = new Background(verticesMidTrees,
                                indicesWall,
                                "./textures/background/parallax-demon-woods-mid-trees.png",
                                "./shaders/background_vert.spv",
                                "./shaders/background_frag.spv");
    objects->push_back(midTrees);
    closeTrees = new Background(verticesCloseTrees,
                                indicesWall,
                                "./textures/background/parallax-demon-woods-close-trees.png",
                                "./shaders/background_vert.spv",
                                "./shaders/background_frag.spv");
    objects->push_back(closeTrees);
//    background = new Background(verticesWall,
//                                indicesWall,
//                                "./textures/wall.jpg",
//                                "./shaders/background_vert.spv",
//                                "./shaders/background_frag.spv");
//    background = new Background(verticesWall,
//                                indicesWall,
//                                "./textures/wall.jpg",
//                                "./shaders/background_vert.spv",
//                                "./shaders/background_frag.spv");
//    background = new Background(verticesWall,
//                                indicesWall,
//                                "./textures/wall.jpg",
//                                "./shaders/background_vert.spv",
//                                "./shaders/background_frag.spv");
//    objects->push_back(background);

    mainActor = new MainActor(verticesMainActor,
                              indicesMainActor,
                              "./textures/muzzle.png",
                              "./shaders/mainActor_vert.spv",
                              "./shaders/mainActor_frag.spv");
    objects->push_back(mainActor);



}
void GAME::GameLoop()
{
    while(true)
    {
//        auto start = std::chrono::high_resolution_clock::now();
        auto key = keyController->getCurrentKeyPressed();


        if(key->size()==0)
        {
            mainActor->stay();
            farTrees->stay();
            midTrees->stay();
            closeTrees->stay();
        }
        for(auto& i : *key)
        {
            if (i == GLFW_KEY_W) {
                if(!mainActor->getJumpState())
                 mainActor->jump();
            }
            else if (i == GLFW_KEY_A) {
                std::cout << "A key pressed" << std::endl;
            }
            else if (i == GLFW_KEY_S) {
                std::cout << "S key pressed" << std::endl;
            }
            else if (i == GLFW_KEY_D) {
                farTrees->runFar();
                midTrees->runMid();
                closeTrees->runClose();
                mainActor->runRight();
            }
        }
        rnd.drawFrame();
        std::this_thread::sleep_for(0.16ms);
        qDebug() << closeTrees->coords.x;
    }
}


