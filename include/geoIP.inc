/*
           _.-,=_""""--,_
        .-" =/7"   _  .3#"=.
      ,#7  " "  ,//)#d#######=.		GEO-IP Lite
    ,/ "      # ,i-/###########= 		Version 2.1
   /         _)#sm###=#=# #######\
  /         (#/"_`;\//#=#\-#######\ 		FEATURES :
 /         ,d####-_.._.)##P########\		+ Gets Country of any IP Address
|       .d##############b\##P'   V  |       + SQLite Database
|\      '#################!",       |       + Faster Operation
|C.       \###=############7        |       + Uses No Plugins
'###.           )#########/         '
 \#(             \#######|         /        CREDITS :
  \B             /#######7 /      /         Database (CSV) : http://db-ip.com
   \             \######" /"     /          Script By : Abhinav Dabral
    `.            \###7'       ,'                       (abhinavdabral)
      "-_          `"'      ,-'                         ALIAS : Code Wave
         "-._           _.-"                Facebook : fb.me/codewave
             """"---""""
*/
#define IP_CZ 1
#define IP_SK 2
#define IP_NONE 0
stock GetIntegerIP(IP[]){
	new iPos = -1,iIP;
	for(new i=24;i >= 0;i-=8){
		iIP |= (strval(IP[++iPos]) << i);
		if(i && -1 == (iPos = strfind(IP,".",_,iPos))) return 0;
	}
	return iIP;
}
stock GetIPLocation(ip[]){
   	static DB:IPDB,DBResult:query,integerIP;
   	new country = IP_NONE;
   	integerIP = GetIntegerIP(ip);
   	IPDB = db_open("IPList.db");
   	static string[128];
   	format(string,sizeof(string),"SELECT country FROM 'IPTable' WHERE start <= %d AND end >= %d",integerIP,integerIP);
	query = db_query(IPDB,string);
	if(db_num_rows(query) == 1) db_get_field(query,0,string,2);
	if(strcmp(string,"CZ",false) == 0) country = IP_CZ;
	else if(strcmp(string,"SK",false) == 0) country = IP_SK;
	db_free_result(query);
	db_close(IPDB);
	return country;
}
