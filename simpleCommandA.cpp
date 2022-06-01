// Copyright 2022 Eric Jones

#include "./simpleCommandA.h"
#include <iostream>

simpleCommandA::simpleCommandA(std::shared_ptr<receiver> r) :
    receiver_(r) {
    prompt_ = "Run simple command A.";
}

simpleCommandA::~simpleCommandA() {
}

void simpleCommandA::execute() {
    receiver_->action("Executed simpleCommandA");
}