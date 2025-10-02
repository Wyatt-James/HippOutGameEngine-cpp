#pragma once

#include <string>
#include <vector>

namespace HippOutGameEngine {

    typedef enum {
        SUCCESS, SYNTAX_ERROR, KNOWN_ERROR, UNKNOWN_ERROR
    } CommandResultType;

    typedef struct {
        CommandResultType type;
        std::string message;
    } CommandResult;

    class Command
    {
        public:
            virtual HippOutGameEngine::CommandResult execute(std::string label, std::vector<std::string> parts) = 0;
    };
}
