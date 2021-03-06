/*
 * Part of Wal Commander GitHub Edition
 * https://github.com/corporateshark/WalCommander
 * walcommander@linderdaum.com
 */

#pragma once

#ifndef _WIN32

#include "wal.h"

using namespace wal;

class Shell
{
	pid_t pid;
	int in, out;

	void Stop();
	void Run();
	std::vector<char> slaveName;
public:
	Shell( const char* slave );

	pid_t Exec( const char* cmd );
	int Wait( pid_t pid, int* pStatus );
	int CD( const char* path );

	~Shell();
};

#endif
