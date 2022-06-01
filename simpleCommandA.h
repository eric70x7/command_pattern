// Copyright 2022 Eric Jones

#ifndef SIMPLECOMMANDA_H_
#define SIMPLECOMMANDA_H_

#include <memory>
#include "./command.h"
#include "./receiver.h"

#pragma once

class simpleCommandA : public command {
 public:
    explicit simpleCommandA(std::shared_ptr<receiver>);
    ~simpleCommandA();

    void execute() override;
 private:
    std::shared_ptr<receiver> receiver_;
};

#endif  // SIMPLECOMMANDA_H_
