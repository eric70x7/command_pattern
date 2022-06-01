// Copyright 2022 Eric Jones

#include "./nullCommand.h"
#include <iostream>

nullCommand::nullCommand() {
    prompt_ = "Null command.";
}

nullCommand::~nullCommand() {
}

void nullCommand::execute() {
    // do nothing
}
