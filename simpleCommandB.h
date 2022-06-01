// Copyright 2022 Eric Jones

#ifndef SIMPLECOMMANDB_H_
#define SIMPLECOMMANDB_H_

#include <memory>
#include "./command.h"
#include "./receiver.h"

#pragma once

class simpleCommandB : public command {
 public:
    explicit simpleCommandB(std::shared_ptr<receiver>);
    ~simpleCommandB();

    void execute() override;
 private:
    std::shared_ptr<receiver> receiver_;
};

#endif  // SIMPLECOMMANDB_H_
