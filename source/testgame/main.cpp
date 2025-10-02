#include <iostream>
#include <vector>


#include "hippoutgameengine/include/engine.h"
#include "hippoutgameengine/include/command/command.h"
#include "test_command.h"

namespace HippOutTestGame {

    std::vector<std::string> split(std::string s, std::string delimiter)
    {
        std::vector<std::string> strs;
        for (size_t index = s.find(delimiter); index != std::string::npos; index = s.find(delimiter)) {
            strs.push_back(s.substr(0, index));
            s.erase(0, index + delimiter.length());
        }

        strs.push_back(s);

        return strs;
    }

    class TestEngine : public HippOutGameEngine::Engine
    {
        public:
            void run() {
                std::cout << "TestEngine\n";

                HippOutGameEngine::Command * cmd;
                {
                    HippOutTestGame::TestCommand tcmd;
                    cmd = &tcmd;
                }

                while (1) {
                    std::cout << "> ";

                    std::string line;
                    std::getline(std::cin, line);

                    std::vector<std::string> parts = split(line, " ");

                    if (parts.size() == 0) {
                        std::cout << "Could not split line. Was it empty?";
                        continue;
                    }

                    cmd->execute(parts[0], parts);

                    std::cout << "Line was: " << line << '\n';
                }
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
