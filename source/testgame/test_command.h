#pragma once

#include <vector>

#include "hippoutgameengine/include/command/command.h"

namespace HippOutTestGame {
    class TestCommand : public HippOutGameEngine::Command {
        public:
            HippOutGameEngine::CommandResult execute(std::string label, std::vector<std::string> parts) {
                std::cout << "CMD (" << parts.size() << "):";

                for (std::string str : parts)
                    std::cout << ' ' << str;

                std::cout << '\n';

                return (HippOutGameEngine::CommandResult) {.type = HippOutGameEngine::CommandResultType::SUCCESS, .message = "Success!"};
            }
    };
};
