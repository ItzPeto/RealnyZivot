#include <a_samp>

public OnPlayerUpdate(playerid)
{
	new string[4];
  	format(string,sizeof(string),"%d",GetServerTickRate());
  	SendClientMessage(playerid,-1,string);
	return 1;
}
