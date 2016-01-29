/*
	File: fn_abortEnabled.sqf
	Author: John "Paratus" VanderZwet
	
	Description:
	Enables or disables abort and respawn buttons based on restrain status
*/

private["_display","_btnRespawn","_btnAbort","_last","_time"];
disableSerialization;

while {true} do
{
	waitUntil{!isNull(findDisplay 49)}; //Wait for ESC menu to be opened
	_time = time;
	_display = findDisplay 49;
	_btnRespawn = _display displayCtrl 1010;
	_btnAbort = _display displayCtrl 104;

	if (life_is_arrested) then
	{
		_btnRespawn ctrlEnable false;
		_btnRespawn ctrlSetText "Cannot Suicide";
	}
	else
	{
		if ((player getVariable ["restrained",false]) || !life_abort_enabled) then
		{
			_btnRespawn ctrlEnable false;
			_btnAbort ctrlEnable false;
			_btnRespawn ctrlSetText "Cannot Suicide";
			_btnAbort ctrlSetText "Cannot Abort";
		}
		else
		{
			while {!isNull(findDisplay 49)} do
			{
				_btnRespawn ctrlEnable true;
				_btnRespawn ctrlSetText "Suicide";
				if (time - _time < 15 && life_adminlevel < 1) then
				{
					_btnAbort ctrlEnable false;
					_btnAbort ctrlSetText format["Quit ASGLife.co.uk [%1]", ceil (15 - (time - _time))];
				}
				else
				{
					_btnAbort ctrlEnable true;
					_btnAbort ctrlSetText "Quit ASGLife.co.uk";
				};
			};
		};
	};
	//_last = life_abort_enabled;
	//waitUntil{isNull (findDisplay 49) || _last != life_abort_enabled};
};