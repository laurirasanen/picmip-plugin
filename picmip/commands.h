#pragma once

#define COMMANDS
#include "picmip.h"
#undef COMMANDS

class CommandHandler {
public:
	CommandHandler();
	~CommandHandler();

	void HandleCommand(edict_t *pEntity, const CCommand &args);

	void HandleCmdPicmip(edict_t *pEntity, const CCommand &args);
	void HandleNoCmd(edict_t *pEntity, const CCommand &args);
};
