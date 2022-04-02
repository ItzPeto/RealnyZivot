/*
    defines.inc
    Používáno pro definici veškerých èísel, hodnot atp.
*/

/*
    Sekce: help/ ===========================================================================
*/

#define HELP_PATH "../sources/help/texts/help_text_%s.txt"
#define HELP_MAINDIALOGID 3
#define HELP_SUBDIALOGID 4
#define HELP_TEXTDIALOGID 5

/*
    Sekce: houses/ =========================================================================
*/

#define WEAPON 0
#define AMMO 1
#define HW_MAIN 320
#define HW_HOUSE 321
#define HW_PLAYER 322
#define HW_HOUSESEL 323
#define HW_PLAYERSEL 324

/*
    Sekce: admin/ =========================================================================
*/

#define TABLE_ADMINLOG "rz_adminlog2"
#define TABLE_TRESTLOG "rz_vars2"

#define isAdmin Informace[playerid][AdminLevel]
#define isModerator Informace[playerid][Moderator]
#define isValidCmdid IsPlayerConnected(cmdid) || !IsPlayerNPC(cmdid)

#define TYPE_VAR 0
