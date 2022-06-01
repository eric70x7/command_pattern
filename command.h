// Copyright 2022 Eric Jones

#ifndef COMMAND_H_
#define COMMAND_H_

#include <string>

#pragma once

class command {
 public:
    command();
    ~command();

    virtual void execute() = 0;

    virtual std::string prompt() { return prompt_; }

 protected:
    std::string prompt_;
};

#endif  // COMMAND_H_
