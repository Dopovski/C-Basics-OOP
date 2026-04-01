#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Defines.h"

ErrorCode executeCommand(const std::string& command, std::vector<MemoryNode>& memory)
{
    std::istringstream ss(command);
    std::string action, type;
    int index;
    ss >> action >> type >> index;

    bool isAllocate = (action == "Allocate");
    bool isSingle   = (type == "Single");

    MemoryNode& node = memory[index];

    if (isAllocate)
    {
        if (node.rawMemory != nullptr)
            return MEMORY_LEAK;

        if (isSingle)
        {
            node.rawMemory  = new int(0);
            node.memoryType = MemoryType::SINGLE;
        }
        else
        {
            node.rawMemory  = new int[ALLOCATION_MULTIPLE_SIZE]();
            node.memoryType = MemoryType::MULTIPLE;
        }
        return EXECUTE_SUCCESS;
    }
    else
    {
        if (node.rawMemory == nullptr)
            return DOUBLE_FREE;

        if ((isSingle  && node.memoryType == MemoryType::MULTIPLE) ||
            (!isSingle && node.memoryType == MemoryType::SINGLE))
            return ALLOCATE_DEALLOCATE_MISMATCH;

        if (isSingle)
            delete node.rawMemory;
        else
            delete[] node.rawMemory;

        node.rawMemory  = nullptr;
        node.memoryType = MemoryType::UNKNOWN;
        return EXECUTE_SUCCESS;
    }
}

void printResult(const ErrorCode errorCode, const std::string& command)
{
    switch (errorCode)
    {
        case EXECUTE_SUCCESS:
            std::cout << command << " - success";
            break;
        case MEMORY_LEAK:
            std::cout << command << " - memory leak prevented, will not make allocation";
            break;
        case DOUBLE_FREE:
            std::cout << command << " - system crash prevented, will skip this deallocation";
            break;
        case ALLOCATE_DEALLOCATE_MISMATCH:
            std::cout << command << " - Warning allocate/deallocate mismatch, will skip this deallocation";
            break;
    }
    std::cout << "\n";
}
