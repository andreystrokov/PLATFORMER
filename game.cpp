#include "game.h"

GAME::GAME()
{

}

void GAME::init()
{
      initObjects();
      rnd.setObjectsPtr(objects,characters);
      rnd.init();


//      rnd.createMainMenu(&mainMenu);


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
    characters = new std::vector<VulkanCharacterObject*>;


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

    ground = new Ground(verticesGround,
                        indicesGround,
                        "./textures/background/groundNew.png",
                        "./shaders/background_vert.spv",
                        "./shaders/background_frag.spv");
    objects->push_back(ground);


    std::vector<std::string> texturesMainActor =
    {
        "./textures/character/Idle.png",
        "./textures/character/Run.png",
        "./textures/character/Jump.png",
        "./textures/character/Attacks.png",
        "./textures/character/Death.png"
    };

    mainActor = new MainActor(verticesMainActor,
                              indicesMainActor,
                              texturesMainActor,
                              "./shaders/mainActor_vert.spv",
                              "./shaders/mainActor_frag.spv");
    characters->push_back(mainActor);



}
void GAME::GameLoop()
{
    while(true)
    {
        auto start = std::chrono::high_resolution_clock::now();
        auto key = keyController->getCurrentKeyPressed();

        for(auto& i : *key)
        {
            if(i == GLFW_KEY_ESCAPE)
            {
                if(isPaused)
                {
                    isPaused = false;
                }
                else
                {
                    isPaused = true;
                }
                std::cout << i << std::endl;
            }

             if(!isPaused)
             {
                 if (i == GLFW_KEY_W) {
                      mainActor->jump();
                 }
                 else if (i == GLFW_KEY_A) {
                     std::cout << "A key pressed" << std::endl;
                 }
                 else if (i == GLFW_KEY_S) {
                     std::cout << "S key pressed" << std::endl;
                 }
                 else if (i == GLFW_KEY_D) {
                     if(!mainActor->getAttackState())
                     {
                         farTrees->runFar();
                         midTrees->runMid();
                         closeTrees->runClose();
                         mainActor->runRight();
                         ground->move();

                         levelGameXCoord+= 0.1;
                     }
                 }
                 else if(i == GLFW_KEY_SPACE)
                 {
                     mainActor->attack();
                 }
             }
        }
        if(!isPaused)
        {
            mainActor->computeXY();

            if(key->size()==0)
            {
                mainActor->stay();
                farTrees->stay();
                midTrees->stay();
                closeTrees->stay();
                ground->stay();
            }
        }

        rnd.drawFrame();
        std::this_thread::sleep_for(0.16ms);
    }
}

void GAME::drawPause()
{

}


