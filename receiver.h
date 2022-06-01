// Copyright 2022 Eric Jones

#ifndef RECEIVER_H_
#define RECEIVER_H_

#include <string>

#pragma once

// Receiver just logs the string given by the command
class receiver {
 public:
    receiver() {}
    ~receiver() {}

    void action(std::string r) {
        result_ = r;
    }

    std::string getResult() {
        std::string rval = result_;
        result_ = "";
        return rval;
    }

 private:
    std::string result_;
};

#endif  // RECEIVER_H_
