/**
 *
 * This software is provided 'as-is', without any express or implied warranty.
 * In no event will the authors be held liable for any damages arising from
 * the use of this software.
 *
 */

#include "picmip.h"

SH_DECL_HOOK2_void( IServerGameClients, ClientCommand, SH_NOATTRIB, 0, edict_t*, const CCommand& );

PicmipPlugin g_PicmipPlugin;

ICvar* icvar = NULL;
IServerGameClients* gameclients = NULL;

CommandHandler commandHandler;

PLUGIN_EXPOSE( PicmipPlugin, g_PicmipPlugin );
bool PicmipPlugin::Load( PluginId id, ISmmAPI* ismm, char* error, size_t maxlen, bool late )
{
	PLUGIN_SAVEVARS();

	commandHandler = CommandHandler();

	GET_V_IFACE_CURRENT( GetEngineFactory, icvar, ICvar, CVAR_INTERFACE_VERSION );
	GET_V_IFACE_ANY( GetServerFactory, gameclients, IServerGameClients, INTERFACEVERSION_SERVERGAMECLIENTS );

	SH_ADD_HOOK( IServerGameClients, ClientCommand, gameclients, SH_MEMBER( this, &PicmipPlugin::Hook_ClientCommand ), true );

	g_pCVar = icvar;

	return true;
}

bool PicmipPlugin::Unload( char* error, size_t maxlen )
{
	SH_REMOVE_HOOK( IServerGameClients, ClientCommand, gameclients, SH_MEMBER( this, &PicmipPlugin::Hook_ClientCommand ), true );

	return true;
}

void PicmipPlugin::AllPluginsLoaded()
{
	/* This is where we'd do stuff that relies on the mod or other plugins
	* being initialized (for example, cvars added and events registered).
	*/
}

void PicmipPlugin::Hook_ClientCommand( edict_t* pEntity, const CCommand& args )
{
	if ( !pEntity || pEntity->IsFree() )
	{
		return;
	}

	commandHandler.HandleCommand( pEntity, args );
}

bool PicmipPlugin::Pause( char* error, size_t maxlen )
{
	return true;
}

bool PicmipPlugin::Unpause( char* error, size_t maxlen )
{
	return true;
}

const char* PicmipPlugin::GetLicense()
{
	return "Public Domain";
}

const char* PicmipPlugin::GetVersion()
{
	return "1.0.0.0";
}

const char* PicmipPlugin::GetDate()
{
	return __DATE__;
}

const char* PicmipPlugin::GetLogTag()
{
	return "PICMIP";
}

const char* PicmipPlugin::GetAuthor()
{
	return "laurirasanen";
}

const char* PicmipPlugin::GetDescription()
{
	return "Unlocks mat_picmip to range from -10 to 10.";
}

const char* PicmipPlugin::GetName()
{
	return "Picmip Plugin";
}

const char* PicmipPlugin::GetURL()
{
	return "https://github.com/laurirasanen/picmip-plugin";
}
