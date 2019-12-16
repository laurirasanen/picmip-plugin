#include "commands.h"

struct ConCommandBaseData
{
	void*				pVMTBase;
	ConCommandBase*		m_pNext;
	bool				m_bRegistered;
	const char*			m_pszName;
	const char*			m_pszHelpString;
	int					m_nFlags;
};

struct ConVarData : ConCommandBaseData
{
	void*				pVMT;
	ConVar*				m_pParent;
	const char*			m_pszDefaultValue;
	char*				m_pszString;
	int					m_StringLength;
	float				m_fValue;
	int					m_nValue;
	bool				m_bHasMin;
	float				m_fMinVal;
	bool				m_bHasMax;
	float				m_fMaxVal;
	FnChangeCallback_t	m_fnChangeCallback;
};

void CommandHandler::HandleCommand( edict_t* pEntity, const CCommand& args )
{
	const char* cmd = args.Arg( 0 );

	if ( strcmp( cmd, "picmip" ) == 0 )
	{
		const char* cmd1 = args.Arg( 1 );

		if ( strcmp( cmd1, "set" ) == 0 )
		{
			HandleCmdPicmip( pEntity, args );
		}
		else
		{
			HandleNoCmd( pEntity, args );
		}
		RETURN_META( MRES_SUPERCEDE );
	}

	RETURN_META( MRES_IGNORED );
}

// https://github.com/momentum-mod/game/issues/495
void CommandHandler::HandleCmdPicmip( edict_t* pEntity, const CCommand& args )
{
	int iPicmip = atoi( args.Arg( 2 ) );

	ConVar* mat_picmip = g_pCVar->FindVar( "mat_picmip" );

	if ( mat_picmip )
	{
		if ( iPicmip < -10 )
			iPicmip = -10;
		else if ( iPicmip > 10 )
			iPicmip = 10;

		ConVarData* ptrData = ( ConVarData* )( mat_picmip );

		ConColorMsg( { 255, 150, 0, 255 }, "Hijacking mat_picmip with a value of % i...\n", iPicmip );

		ptrData->m_fMinVal = -10.0f;
		ptrData->m_fMaxVal = 10.0f;

		mat_picmip->SetValue( iPicmip );

		// delete the convar
		g_pCVar->UnregisterConCommand( mat_picmip );
		g_pCVar->UnregisterConCommand( ptrData->m_pParent );
	}
	else
	{
		ConColorMsg( { 255, 0, 0, 255 }, "Could not find ConVar 'mat_picmip'. If you have already used 'picmip set <value>' you need to restart the game." );
	}
}

void CommandHandler::HandleNoCmd( edict_t* pEntity, const CCommand& args )
{
	Msg( "\n" );
	Msg( "\n" );
	Msg( "picmip\n" );
	Msg( "    set <value>\n" );
	Msg( "\n" );
	Msg( "\n" );
}

CommandHandler::CommandHandler()
{

}

CommandHandler::~CommandHandler()
{

}
