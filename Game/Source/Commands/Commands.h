#pragma once
#include "Command.hpp"

// DONT NEED COMMANDS!!??
class JumpCommand : public Command
{
public:
	void Execute() override;
};


class AttackCommand : public Command
{
public:
	void Execute() override;
};