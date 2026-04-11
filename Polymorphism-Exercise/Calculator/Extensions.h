#pragma once

#include <memory>
#include <stack>
#include <vector>
#include "Operation.h"
#include "CalculationEngine.h"
#include "InputInterpreter.h"

class DivisionOperation : public Operation {
    std::vector<int> operands;
    int result;
public:
    void addOperand(int operand) override {
        this->operands.push_back(operand);
        if (this->isCompleted()) {
            this->result = this->operands[0] / this->operands[1];
        }
    }

    bool isCompleted() override {
        return this->operands.size() == 2;
    }

    int getResult() override {
        return this->result;
    }
};

class MsOperation : public Operation {
    int result;
    bool completed;
    std::stack<int>& memory;
public:
    MsOperation(std::stack<int>& memory) : memory(memory), result(0), completed(false) {}

    void addOperand(int operand) override {
        this->result = operand;
        this->memory.push(operand);
        this->completed = true;
    }

    bool isCompleted() override {
        return this->completed;
    }

    int getResult() override {
        return this->result;
    }
};

class MrOperation : public Operation {
    int result;
public:
    MrOperation(std::stack<int>& memory) : result(0) {
        this->result = memory.top();
        memory.pop();
    }

    void addOperand(int operand) override {}

    bool isCompleted() override {
        return true;
    }

    int getResult() override {
        return this->result;
    }
};

class ExtendedInputInterpreter : public InputInterpreter {
    std::stack<int> memory;
public:
    ExtendedInputInterpreter(CalculationEngine& engine) : InputInterpreter(engine) {}

    std::shared_ptr<Operation> getOperation(std::string operation) override {
        if (operation == "/") {
            return std::make_shared<DivisionOperation>();
        }
        if (operation == "ms") {
            return std::make_shared<MsOperation>(this->memory);
        }
        if (operation == "mr") {
            return std::make_shared<MrOperation>(this->memory);
        }
        return InputInterpreter::getOperation(operation);
    }
};

std::shared_ptr<InputInterpreter> buildInterpreter(CalculationEngine& engine) {
    return std::make_shared<ExtendedInputInterpreter>(engine);
}
