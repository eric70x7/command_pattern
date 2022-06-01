// Copyright 2022 Eric Jones

#include "./simpleCommandB.h"
#include <iostream>

simpleCommandB::simpleCommandB(std::shared_ptr<receiver> r) :
    receiver_(r) {
    prompt_ = "Run simple command B.";
}

simpleCommandB::~simpleCommandB() {
}

void simpleCommandB::execute() {
    receiver_->action("Executed simpleCommandB");
}