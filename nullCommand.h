// Copyright 2022 Eric Jones

#ifndef NULLCOMMAND_H_
#define NULLCOMMAND_H_

#include <memory>
#include "./command.h"
#include "./receiver.h"

#pragma once

class nullCommand : public command {
 public:
    nullCommand();
    ~nullCommand();

    void execute() override;
 private:
};

#endif  // NULLCOMMAND_H_
