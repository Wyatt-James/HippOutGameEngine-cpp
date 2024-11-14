#include <iostream>
#include "hippoutgameengine/include/engine.h"

namespace HippOutTestGame {
    class TestEngine : public HippOutGameEngine::Engine
    {
        public:
            void run() {
                std::cout << "TestEngine\n";
            }
    };

    int engine_main(int argc, char **argv) {
        HippOutTestGame::TestEngine e;
        e.run();

        std::cout << "Hello, world!\n";
        return 0;
    }
}

int main(int argc, char **argv) {
    return HippOutTestGame::engine_main(argc, argv);
}
