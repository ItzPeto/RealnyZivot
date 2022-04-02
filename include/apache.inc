/*

    Apache INCLUDE made by MaverickCZE 2007-2008 (c) ARR

*/

//                  [ INDEX ]

#if defined _apache_included
	#endinput
#endif

#define _apache_included
#pragma library apache


#define TYPE_AIRPLANE   0
#define TYPE_TRAIN      1
#define TYPE_BIKES      2
#define TYPE_BOATS      3
#define TYPE_CAR        4
#define TYPE_RC         5
#define TYPE_BICYCLES   6
#define TYPE_TRAILERS   7
#define TYPE_PLANE   	8
#define TYPE_HELICOPTER 9
#define TYPE_BIGPLANE	10
#define TYPE_TRUCKS	11
#define TYPE_BUSES	12
#define TYPE_POLICEVEHICLELV       13
#define TYPE_POLICEVEHICLESF       14
#define TYPE_POLICEVEHICLELS       15
#define TYPE_ARMYHELI              16
#define TYPE_ARMYCAR               17

//                  [ BODY ]


stock A_SPMI(playerid,iconid,Float:x,Float:y,Float:z,typ)
{
  if(IsPlayerConnected(playerid)) SetPlayerMapIcon(playerid,iconid,x,y,z,typ,0);
}

stock GetFreeServerSlots() // new pocet = GetFreeServerSlots(); printf( "Na serveru je:%d volnych slotu" ,pocet);
{
	new a = 0;
	for(new i=0;i<MAX_PLAYERS;i++) if(IsPlayerConnected(i)) a++;
	a = GetMaxPlayers() - a;
	return a;
}

stock chrfind2(n,h[],s=0)
{
	new l=strlen(h);
	while(s<l)
	{
		if(h[s]==n)
		return s;s++;
	}
	return -1;
}

stock DistanceToPoint(playerid,Float:x,Float:y,Float:z)
{
	new Float:x1,Float:y1,Float:z1,Float:tmpdis;
	GetPlayerPos(playerid,x1,y1,z1);
	tmpdis = floatsqroot(floatpower(floatabs(floatsub(x,x1)),2)+floatpower(floatabs(floatsub(y,y1)),2)+floatpower(floatabs(floatsub(z,z1)),2));
	return floatround(tmpdis);
}

stock GetFullServerSlots() // new pocet = GetFullServerSlots(); printf( "Na serveru je:%d hracu on-line" ,pocet);
{
	new a = 0;
	for(new i=0;i<MAX_PLAYERS;i++) if(IsPlayerConnected(i) && !IsPlayerNPC(i)) a++; return a;
}

stock GetVehiclesCount() // new pocet = GetVehiclesCount(); printf( "Pocet aut:%d" ,pocet);
{
	new c, a = 0;
	c = CreateVehicle(411, 0, 0, 0, 0, 1, 1, 4000);
	a = c--;

	DestroyVehicle(c);
	return a;
}

stock GetObjectsCount() // new pocet = GetObjectsCount(); printf( "Pocet objektu:%d" ,pocet);
{
	new o, a = 0;
	o = CreateObject(8481,0,0,0,0,0,0);
	a = o--;

	DestroyObject(o);
	return a;
}

stock GetVehicleModelCount() // new pocet = GetVehicleModelCount(); printf( "Pocet modelu:%d" ,pocet);
{
	bool:m[220];
	new i,a = 0;
	for(i=0;i<220;i++) m[i] = false;

	for(i=0;i<GetVehiclesCount();i++)
	{
		new model = GetVehicleModel(i);
		if(model != 0)
		{
		    m[i-400] = true;
		}
	}
	
	for(i=0;i<220;i++) if(m[i]) a++;
	return a;
}

stock GetVehicleType(vehicleid,model = 0)
{
	if(model == 0) model = GetVehicleModel(vehicleid);

	if(model > 399 && model < 613)
	{
	switch(model)
	{
  case 590,569,537,538,570,449: return TYPE_TRAIN;
	case 581,462,521,463,522,461,448,468,586: return TYPE_BIKES;
	case 481,509,510: return TYPE_BICYCLES;
	case 511,548,512,593,553,497,476,447,519,460,513,520: return TYPE_PLANE;
	case 472,473,493,595,484,430,453,452,446,454: return TYPE_BOATS;
	case 441,464,594,465,501,564: return TYPE_RC;
	case 417,487,488,563,469,425: return TYPE_HELICOPTER;
	case 592,577: return TYPE_BIGPLANE;
	case 403,514,515,432: return TYPE_TRUCKS;
	case 431,437: return TYPE_BUSES;
	default: return TYPE_CAR;
	}
	}
	return false;
}

stock GetVehicleType2(vehicleid)
{
	new model = GetVehicleModel(vehicleid);

	if(model > 399 && model < 613)
	{
	switch(model)
	{
	case 590,569,537,538,570,449: return TYPE_TRAIN;
	case 581,462,521,463,522,461,448,468,586: return TYPE_BIKES;
	case 481,509,510: return TYPE_BICYCLES;
	case 511,548,512,593,553,497,476,447,519,460,513,520: return TYPE_PLANE;
	case 472,473,493,595,484,430,453,452,446,454: return TYPE_BOATS;
	case 441,464,594,465,501,564: return TYPE_RC;
	case 417,487,488,563,469,425: return TYPE_HELICOPTER;
	case 592,577: return TYPE_BIGPLANE;
	case 403,514,515,432: return TYPE_TRUCKS;
	case 431,437: return TYPE_BUSES;
	default: return TYPE_CAR;
	}
	}
	return false;
}

stock ChooseOneNumber(...) // new cislo = ChooseOneNumber(12,344,711); ... pote vybere jedno z cisel a ulozi do hodnoty "cislo"
{
    new meta = random(numargs());
	meta = getarg(meta);
	return meta;
}

stock ShutdownServer(bool:logit) // ShutdownServer(1); || ShutdownServer(0); - bez logu
{
	if(logit)
	{
		new h,m,s,r,mes,d;
		getdate(r,mes,d);
		gettime(h,m,s);
		#pragma unused s
		printf("   [%d|%d|%d   |   %d:%d]  :-:-:  Server restarted by local function.",d,mes,r,h,m);
	}

	for(new i=0;i<GetVehiclesCount();i++) if(i) if(GetVehicleModel(i) > 399 && GetVehicleModel(i) < 613) DestroyVehicle(i);
	for(new i=0;i<GetObjectsCount();i++)  if(i) DestroyObject(i);
	SendClientMessageToAll(0xFF12FFAA, " Server restarted by called a local function in gamemode.");
}

stock IsPlayerInInterior(playerid) // if(!IsPlayerInInterior(playerid)) SendClientMessage(playerid, BARVA, "Nejsi v interieru.");
{
	if(IsPlayerConnected(playerid)) if(GetPlayerInterior(playerid) > 0) return true;
	return false;
}

stock GetRandomNumber(min, max) // new cislo = GetRandomNumber(12, 36); Cislo bude vybrane od 12 do 36 treba "32"
{
	max -= min;
	return random(max+1) + min;
}

stock CrashMyServer() // CrashMyServer();  --- Vsem hracum na serveru spadne hra
{
	for(new i=0;i<MAX_PLAYERS;i++)
	{
	    if(IsPlayerConnected(i))
		{
			new Float:P[3];
			GetPlayerPos(i,P[0],P[1],P[2]);
			CreatePlayerObject(i, 999999999, P[0],P[1],P[2], 0, 0, 0);
		}
	}
}

stock GiveMoneyTo(moneys, ...) // GiveMoneyTo(1200,playerid,giveplayerid,sender); ... odevzda penize hracum
{
	for(new i=1;i<numargs()-1;i++) new hrac = getarg(i); if(IsPlayerConnected(hrac)) GivePlayerMoney(hrac, moneys);
}

stock DestroyVehiclesModels(...) // DestroyVehiclesModels(411,422,512,602); ... znici dane modely vozidel
{
	for(new i=0;i<numargs();i++)
	{
		new arg = getarg(i);
		if(arg > 399 && arg < 613)
		{
		    for(new c=0;c<MAX_VEHICLE_EX;c++)
			{
			    if(GetVehicleModel(c) == arg)
				{
				    new lidi = 0;
				    for(new b=0;b<MAX_PLAYERS;b++) if(IsPlayerConnected(b)) if(IsPlayerInVehicle(i,c) lidi++;
				    if(lidi == 0) DestroyVehicle(c);
				}
			}
		}
	}
}

stock IsSomeoneOnServer() // if(IsSomeoneOnServer()) ... Na serveru je nejmene jeden hrac
{
	if(GetFullServerSlots() > 0) return true;
	return false;
}

stock IsNightTime() // if(IsNightTime()) ... Na serveru je noc ---- if(!IsNightTime()) ... Na serveru je den
{
	new h,m,s;
	gettime(h,m,s);
	#pragma unused m,s
	switch (h)
	{
	case 20,21,22,23,0,1,2,3,4,5,6,7: return true;
	default: return false;
	}
}

stock ResetPlayer(playerid)
{
	if(IsPlayerConnected(playerid))
	{
	    ResetPlayerMoney(playerid);
	    SetPlayerWantedLevel(playerid, 0);
	    ResetPlayerWeapons(playerid);
	    SetPlayerScore(playerid, 0);
	    SetPlayerHealth(playerid, 100.0);
	    SetPlayerArmour(playerid, 0.0);
	    SetPlayerWeather(playerid, 10);
	    DisablePlayerCheckpoint(playerid);
	    DisablePlayerRaceCheckpoint(playerid);
	    ClearAnimations(playerid);
	    SetCameraBehindPlayer(playerid);
	    SetPlayerVirtualWorld(playerid, 0);
	    TogglePlayerSpectating(playerid, 0);
	}
}

stock WeaponName(weapon)
{
	new Nazev[40];

	if	   (weapon ==  0) Nazev = "Pest";
	else if(weapon ==  1) Nazev = "Boxer";
	else if(weapon ==  2) Nazev = "Golfova hul";
	else if(weapon ==  3) Nazev = "Hul";
	else if(weapon ==  4) Nazev = "Nuz";
	else if(weapon ==  5) Nazev = "Baseballka";
	else if(weapon ==  6) Nazev = "Maceta";
	else if(weapon ==  7) Nazev = "Kulecnikova hul";
	else if(weapon ==  8) Nazev = "Katana";
	else if(weapon ==  9) Nazev = "Motorovka";
	else if(weapon == 10) Nazev = "Dildo";
	else if(weapon == 11) Nazev = "Dildo2";
	else if(weapon == 12) Nazev = "Vibrator";
	else if(weapon == 13) Nazev = "Vibrator2";
	else if(weapon == 14) Nazev = "Kvetiny";
	else if(weapon == 15) Nazev = "Cane";
	else if(weapon == 16) Nazev = "Granat";
	else if(weapon == 17) Nazev = "Slzny plyn";
	else if(weapon == 18) Nazev = "Molotovuv koktejl";
	else if(weapon == 22) Nazev = "Kolt45";
	else if(weapon == 23) Nazev = "Pistole s tlumicem";
	else if(weapon == 24) Nazev = "Desert Eagle";
	else if(weapon == 25) Nazev = "Brokovnice";
	else if(weapon == 26) Nazev = "Upilovana brokovnice";
	else if(weapon == 27) Nazev = "Utocna brokovnice";
	else if(weapon == 28) Nazev = "Uzi";
	else if(weapon == 29) Nazev = "Mp5";
	else if(weapon == 30) Nazev = "AK47";
	else if(weapon == 31) Nazev = "M4";
	else if(weapon == 32) Nazev = "Tec9";
	else if(weapon == 33) Nazev = "Puska";
	else if(weapon == 34) Nazev = "Sniperka";
	else if(weapon == 35) Nazev = "Raketomet";
	else if(weapon == 36) Nazev = "Teplonavadeci Raketomet";
	else if(weapon == 37) Nazev = "Plamenomet";
	else if(weapon == 38) Nazev = "Minigun";
	else if(weapon == 39) Nazev = "C4";
	else if(weapon == 40) Nazev = "Bomba";
	else if(weapon == 41) Nazev = "Sprej";
	else if(weapon == 42) Nazev = "Hasicak";
	else if(weapon == 43) Nazev = "Fotak";
	else if(weapon == 46) Nazev = "Padak";

	return Nazev;
}

stock file_GetKey(line[])
{
	new keyRes[256];
	keyRes[0] = 0;
    if(strfind(line,"=",true) == -1) return keyRes;
    strmid(keyRes,line,0,strfind(line,"=",true),sizeof(keyRes));
    return keyRes;
}

stock file_GetValue(line[])
{
	new valRes[256];
	valRes[0]=0;
	if(strfind(line,"=",true) == -1) return valRes;
	strmid(valRes,line,strfind(line,"=",true)+1,strlen(line),sizeof(valRes));
	return valRes;
}



