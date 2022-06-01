// Copyright 2022 Eric Jones

#ifndef INVOKER_H_
#define INVOKER_H_

#include <array>
#include <memory>
#include <vector>
#include "./command.h"
#include "./nullCommand.h"

#pragma once

template<std::size_t slots>
class invoker {
 public:
    invoker() {
        for (int32_t i=0; i < slots; i++) {
            slots_[i] = std::shared_ptr<command>(new nullCommand());
        }
    }

    ~invoker() {}

    void setCommand(int slot, std::shared_ptr<command> command) {
        if (slot < slots) {
            slots_[slot] = command;
        }
    }

    void invoke(int slot) {
        if (slot < slots) {
            slots_[slot]->execute();
        }
    }

 private:
    std::array<std::shared_ptr<command>, slots> slots_;
};

#endif  // INVOKER_H_
