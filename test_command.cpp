// Copyright 2022 Eric Jones

#include "./test_command.h"
#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include "./invoker.h"
#include "./receiver.h"
#include "./simpleCommandA.h"
#include "./simpleCommandB.h"

test_command::test_command() {
}

test_command::~test_command() {
}

TEST(CommandSuite, TestSingleCommandInvoker) {
    invoker<1> inv;
    std::shared_ptr<receiver> rec(new receiver());

    std::shared_ptr<simpleCommandA> cA(new simpleCommandA(rec));

    inv.invoke(0);
    ASSERT_EQ(rec->getResult(), "");

    // Ensure no crash with out of range invoker slot
    inv.invoke(1);

    inv.setCommand(0, cA);
    inv.invoke(0);
    ASSERT_EQ(rec->getResult(), "Executed simpleCommandA");
}

TEST(CommandSuite, TestMultipleCommandInvoker) {
    invoker<3> inv;
    std::shared_ptr<receiver> rec(new receiver());

    // test code serves as the client
    std::shared_ptr<simpleCommandA> cA(new simpleCommandA(rec));
    std::shared_ptr<simpleCommandB> cB(new simpleCommandB(rec));

    inv.setCommand(0, cA);
    inv.setCommand(1, cB);

    inv.invoke(0);
    ASSERT_EQ(rec->getResult(), "Executed simpleCommandA");
    inv.invoke(1);
    ASSERT_EQ(rec->getResult(), "Executed simpleCommandB");
    inv.invoke(2);
    ASSERT_EQ(rec->getResult(), "");
    inv.invoke(3);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
