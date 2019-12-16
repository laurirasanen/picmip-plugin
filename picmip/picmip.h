/**
 *
 * This software is provided 'as-is', without any express or implied warranty.
 * In no event will the authors be held liable for any damages arising from
 * the use of this software.
 *
 */

#ifndef _INCLUDE_METAMOD_SOURCE_PICMIP_PLUGIN_H_
#define _INCLUDE_METAMOD_SOURCE_PICMIP_PLUGIN_H_

#include <ISmmPlugin.h>
#include <sourcehook.h>
#include <edict.h>

#include "commands.h"

#if defined WIN32 && !defined snprintf
#define snprintf _snprintf
#endif

class PicmipPlugin : public ISmmPlugin
{
public:
	bool Load( PluginId id, ISmmAPI* ismm, char* error, size_t maxlen, bool late );
	bool Unload( char* error, size_t maxlen );
	bool Pause( char* error, size_t maxlen );
	bool Unpause( char* error, size_t maxlen );
	void AllPluginsLoaded();

	void Hook_ClientCommand( edict_t* pEntity, const CCommand& args );

	const char* GetAuthor();
	const char* GetName();
	const char* GetDescription();
	const char* GetURL();
	const char* GetLicense();
	const char* GetVersion();
	const char* GetDate();
	const char* GetLogTag();
};

extern PicmipPlugin g_PicmipPlugin;

#ifndef COMMANDS
extern CommandHandler commandHandler;
#endif

PLUGIN_GLOBALVARS();

#endif //_INCLUDE_METAMOD_SOURCE_PICMIP_PLUGIN_H_
