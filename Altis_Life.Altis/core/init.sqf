#include "..\script_macros.hpp"
/*
	Master client initialization file
*/
life_firstSpawn = true;
life_session_completed = false;
private["_handle","_timeStamp"];

_LoadMsg = {
	[
		format["<t size='1.3' color='#5600FF'>%1</t><br/>%2",_this select 0, _this select 1],
		0,
		0.2,
		99999999999999,
		0,
		0,
		8
	] spawn BIS_fnc_dynamicText;
};

// 0 cutText["Setting up client, please wait...","BLACK FADED"];
// 0 cutFadeOut 9999999;

5 cutRsc ["SplashNoise","BLACK"];

["Setting up client","Your client is currently loading ArmA RPG. Please wait..."] call _LoadMsg;



_timeStamp = diag_tickTime;
diag_log "------------------------------------------------------------------------------------------------------";
diag_log "--------------------------------- Starting Altis Life Client Init ----------------------------------";
diag_log "------------------------------------------------------------------------------------------------------";
waitUntil {!isNull player && player == player}; //Wait till the player is ready
[] call compile PreprocessFileLineNumbers "core\clientValidator.sqf";

//Setup initial client core functions
diag_log "::Life Client:: Initialization Variables";
[] call compile PreprocessFileLineNumbers "core\configuration.sqf";

//Set bank amount for new players
switch (playerSide) do {
	case west: {
		BANK = LIFE_SETTINGS(getNumber,"bank_cop");
		life_paycheck = LIFE_SETTINGS(getNumber,"paycheck_cop");
	};
	case civilian: {
		BANK = LIFE_SETTINGS(getNumber,"bank_civ");
		life_paycheck = LIFE_SETTINGS(getNumber,"paycheck_civ");
	};
	case independent: {
		BANK = LIFE_SETTINGS(getNumber,"bank_med");
		life_paycheck = LIFE_SETTINGS(getNumber,"paycheck_med");
	};
};
diag_log "::Life Client:: Variables initialized";
diag_log "::Life Client:: Setting up Eventhandlers";
["Setting up Event Handlers","Creating essential event handlers to operation."] call _LoadMsg;
[] call life_fnc_setupEVH;

diag_log "::Life Client:: Eventhandlers completed";
diag_log "::Life Client:: Setting up user actions";
["Setting up Actions","Creating essential actions. Please wait..."] call _LoadMsg;
[] call life_fnc_setupActions;

diag_log "::Life Client:: User actions completed";
diag_log "::Life Client:: Waiting for server functions to transfer..";

["Receiving serverside functions.","Your client is downloading functions from the server."] call _LoadMsg;

waitUntil {(!isNil {TON_fnc_clientGangLeader})};

diag_log "::Life Client:: Received server functions.";
["Waiting for server...","The server is still setting up, please wait."] call _LoadMsg;
//0 cutText ["Waiting for the server to be ready...","BLACK FADED"];
//0 cutFadeOut 99999999;

diag_log "::Life Client:: Waiting for the server to be ready..";
waitUntil{!isNil "life_server_isReady"};
waitUntil{(life_server_isReady OR !isNil "life_server_extDB_notLoaded")};

if(!isNil "life_server_extDB_notLoaded" && {life_server_extDB_notLoaded != ""}) exitWith {
	diag_log life_server_extDB_notLoaded;
	999999 cutText [life_server_extDB_notLoaded,"BLACK FADED"];
	999999 cutFadeOut 99999999;
};
["Loading gear from server...","You are currently in the login queue, this should not take too long. Please wait..."] call _LoadMsg;
[] call SOCK_fnc_dataQuery;
waitUntil {life_session_completed};
["Finished Receiving Data","Data received, Welcome to ArmA RPG!"] call _LoadMsg;
5 cutFadeOut 5;
sleep 2;
["",""] call _LoadMsg;
// LoadMsg text finishes here
//0 cutText["Finishing client setup procedure","BLACK FADED"];
//0 cutFadeOut 9999999;

//diag_log "::Life Client:: Group Base Execution";
[] spawn life_fnc_escInterupt;

switch (playerSide) do {
	case west: {
		_handle = [] spawn life_fnc_initCop;
		waitUntil {scriptDone _handle};
	};
	case civilian: {
		//Initialize Civilian Settings
		_handle = [] spawn life_fnc_initCiv;
		waitUntil {scriptDone _handle};
	};
	case independent: {
		//Initialize Medics and blah
		_handle = [] spawn life_fnc_initMedic;
		waitUntil {scriptDone _handle};
	};
};

player SVAR ["restrained",false,true];
player SVAR ["Escorting",false,true];
player SVAR ["transporting",false,true];

diag_log "Past Settings Init";
[] execFSM "core\fsm\client.fsm";

diag_log "Executing client.fsm";
waitUntil {!(isNull (findDisplay 46))};

diag_log "Display 46 Found";
(findDisplay 46) displayAddEventHandler ["KeyDown", "_this call life_fnc_keyHandler"];
player addRating 99999999;
diag_log "------------------------------------------------------------------------------------------------------";
diag_log format["                End of Altis Life Client Init :: Total Execution Time %1 seconds ",(diag_tickTime) - _timeStamp];
diag_log "------------------------------------------------------------------------------------------------------";

life_sidechat = true;
[player,life_sidechat,playerSide] remoteExecCall ["TON_fnc_managesc",RSERV];
0 cutText ["","BLACK IN"];
[] call life_fnc_hudSetup;

/* Set up frame-by-frame handlers */
LIFE_ID_PlayerTags = ["LIFE_PlayerTags","onEachFrame","life_fnc_playerTags"] call BIS_fnc_addStackedEventHandler;
LIFE_ID_RevealObjects = ["LIFE_RevealObjects","onEachFrame","life_fnc_revealObjects"] call BIS_fnc_addStackedEventHandler;

player SVAR ["steam64ID",steamid];
player SVAR ["realname",profileName,true];

life_fnc_moveIn = compileFinal
"
	player moveInCargo (_this select 0);
";

[] spawn life_fnc_survival;

CONSTVAR(life_paycheck); //Make the paycheck static.
if(EQUAL(LIFE_SETTINGS(getNumber,"enable_fatigue"),0)) then {player enableFatigue false;};