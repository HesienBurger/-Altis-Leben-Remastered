// By: Heisen

class life_admin_menu {
	idd = 2900;
	name= "life_admin_menu";
	movingEnable = false;
	enableSimulation = true;
	onLoad = "[] spawn life_fnc_adminMenu;";

	class controlsBackground {
			class back: Life_RscText
			{
				idc = 1000;
				x = 6.5 * GUI_GRID_W + GUI_GRID_X;
				y = 6.5 * GUI_GRID_H + GUI_GRID_Y;
				w = 26.5 * GUI_GRID_W;
				h = 11 * GUI_GRID_H;
				colorBackground[] = {0,0,0,0.7};
			};
			class back_top: Life_RscText
			{
				idc = 1001;
				x = 6.5 * GUI_GRID_W + GUI_GRID_X;
				y = 5.5 * GUI_GRID_H + GUI_GRID_Y;
				w = 26.5 * GUI_GRID_W;
				h = 1 * GUI_GRID_H;
				colorBackground[] = {45,0,0,0.7};
			};
	};

	class controls {


				class text: Life_RscText
				{
					idc = 1002;
					text = "Admin Panel"; //--- ToDo: Localize;
					x = 16.4 * GUI_GRID_W + GUI_GRID_X;
					y = 5.3 * GUI_GRID_H + GUI_GRID_Y;
					w = 11 * GUI_GRID_W;
					h = 1.5 * GUI_GRID_H;
				};
				class PlayerList_Admin: Life_RscListbox
				{
					idc = 1500;
					x = 7.5 * GUI_GRID_W + GUI_GRID_X;
					y = 7 * GUI_GRID_H + GUI_GRID_Y;
					w = 8.5 * GUI_GRID_W;
					h = 10 * GUI_GRID_H;
					colorBackground[] = {0,0,0,0.7};
					onLBSelChanged = "[_this] spawn life_fnc_adminQuery";
				};
				class PlayerBInfo: Life_RscStructuredText
				{
					idc = 1100;
					x = 16.5 * GUI_GRID_W + GUI_GRID_X;
					y = 7 * GUI_GRID_H + GUI_GRID_Y;
					w = 16 * GUI_GRID_W;
					h = 10 * GUI_GRID_H;
					colorBackground[] = {0,0,0,0.7};
				};
				class left_back: Life_RscText
				{
					idc = 1003;
					x = -3 * GUI_GRID_W + GUI_GRID_X;
					y = 6.5 * GUI_GRID_H + GUI_GRID_Y;
					w = 9 * GUI_GRID_W;
					h = 11 * GUI_GRID_H;
					colorBackground[] = {0,0,0,0.7};
				};
				class right_back: Life_RscText
				{
					idc = 1004;
					x = 33.5 * GUI_GRID_W + GUI_GRID_X;
					y = 6.5 * GUI_GRID_H + GUI_GRID_Y;
					w = 9 * GUI_GRID_W;
					h = 11 * GUI_GRID_H;
					colorBackground[] = {0,0,0,0.7};
				};
				class left_top_back: Life_RscText
				{
					idc = 1005;
					text = "Player Functions"; //--- ToDo: Localize;
					x = -3 * GUI_GRID_W + GUI_GRID_X;
					y = 5.5 * GUI_GRID_H + GUI_GRID_Y;
					w = 9 * GUI_GRID_W;
					h = 1 * GUI_GRID_H;
					colorBackground[] = {45,0,0,0.7};
				};
				class right_top_back: Life_RscText
				{
					idc = 1006;
					text = "Your Functions"; //--- ToDo: Localize;
					x = 33.5 * GUI_GRID_W + GUI_GRID_X;
					y = 5.5 * GUI_GRID_H + GUI_GRID_Y;
					w = 9 * GUI_GRID_W;
					h = 1 * GUI_GRID_H;
					colorBackground[] = {45,0,0,0.7};
				};
				class Compensate: Life_RscButtonMenu
				{
					idc = 2400;
					text = "Compensate"; //--- ToDo: Localize;
					x = -2.5 * GUI_GRID_W + GUI_GRID_X;
					y = 7 * GUI_GRID_H + GUI_GRID_Y;
					w = 8 * GUI_GRID_W;
					h = 1 * GUI_GRID_H;
					onButtonClick = "createDialog ""Life_Admin_Compensate"";";
				};
				class Spectate: Life_RscButtonMenu
				{
					idc = 2401;
					text = "Spectate"; //--- ToDo: Localize;
					x = -2.5 * GUI_GRID_W + GUI_GRID_X;
					y = 8.5 * GUI_GRID_H + GUI_GRID_Y;
					w = 8 * GUI_GRID_W;
					h = 1 * GUI_GRID_H;
					onButtonClick = "[] call life_fnc_adminSpectate;";
				};
				class Freeze: Life_RscButtonMenu
				{
					idc = 2402;
					text = "Freeze"; //--- ToDo: Localize;
					x = -2.5 * GUI_GRID_W + GUI_GRID_X;
					y = 10 * GUI_GRID_H + GUI_GRID_Y;
					w = 8 * GUI_GRID_W;
					h = 1 * GUI_GRID_H;
					onButtonClick = "[] call life_fnc_adminFreeze;";
				};
				class AdminID: Life_RscButtonMenu
				{
					idc = 2403;
					text = "AdminID"; //--- ToDo: Localize;
					x = -2.5 * GUI_GRID_W + GUI_GRID_X;
					y = 11.5 * GUI_GRID_H + GUI_GRID_Y;
					w = 8 * GUI_GRID_W;
					h = 1 * GUI_GRID_H;
					onButtonClick = "[] call life_fnc_admingetID;";
				};
				class extra_left_1: Life_RscButtonMenu
				{
					idc = 2404;
					x = -2.5 * GUI_GRID_W + GUI_GRID_X;
					y = 13 * GUI_GRID_H + GUI_GRID_Y;
					w = 8 * GUI_GRID_W;
					h = 1 * GUI_GRID_H;
				};
				class extra_left_2: Life_RscButtonMenu
				{
					idc = 2405;
					x = -2.5 * GUI_GRID_W + GUI_GRID_X;
					y = 14.5 * GUI_GRID_H + GUI_GRID_Y;
					w = 8 * GUI_GRID_W;
					h = 1 * GUI_GRID_H;
				};
				class extra_left_3: Life_RscButtonMenu
				{
					idc = 2406;
					x = -2.5 * GUI_GRID_W + GUI_GRID_X;
					y = 16 * GUI_GRID_H + GUI_GRID_Y;
					w = 8 * GUI_GRID_W;
					h = 1 * GUI_GRID_H;
				};
				class God: Life_RscButtonMenu
				{
					idc = 2407;
					text = "God [On/Off]"; //--- ToDo: Localize;
					x = 34 * GUI_GRID_W + GUI_GRID_X;
					y = 7 * GUI_GRID_H + GUI_GRID_Y;
					w = 8 * GUI_GRID_W;
					h = 1 * GUI_GRID_H;
					onButtonClick = "[] call life_fnc_adminGodMode;";
				};
				class Markers: Life_RscButtonMenu
				{
					idc = 2408;
					text = "Markers"; //--- ToDo: Localize;
					x = 34 * GUI_GRID_W + GUI_GRID_X;
					y = 8.5 * GUI_GRID_H + GUI_GRID_Y;
					w = 8 * GUI_GRID_W;
					h = 1 * GUI_GRID_H;
					onButtonClick = "[] spawn life_fnc_adminMarkers;";
				};
				class Teleport: Life_RscButtonMenu
				{
					idc = 2409;
					text = "Teleport"; //--- ToDo: Localize;
					x = 34 * GUI_GRID_W + GUI_GRID_X;
					y = 10 * GUI_GRID_H + GUI_GRID_Y;
					w = 8 * GUI_GRID_W;
					h = 1 * GUI_GRID_H;
					onButtonClick = "[] call life_fnc_adminTeleport; hint 'Select where you would like to teleport';";
				};
				class TeleportHere: Life_RscButtonMenu
				{
					idc = 2410;
					text = "Teleport Here"; //--- ToDo: Localize;
					x = 34 * GUI_GRID_W + GUI_GRID_X;
					y = 11.5 * GUI_GRID_H + GUI_GRID_Y;
					w = 8 * GUI_GRID_W;
					h = 1 * GUI_GRID_H;
					onButtonClick = "[] call life_fnc_adminTpHere;";
				};
				class extra_right_1: Life_RscButtonMenu
				{
					idc = 2411;
					x = 34 * GUI_GRID_W + GUI_GRID_X;
					y = 13 * GUI_GRID_H + GUI_GRID_Y;
					w = 8 * GUI_GRID_W;
					h = 1 * GUI_GRID_H;
				};
				class extra_right_2: Life_RscButtonMenu
				{
					idc = 2412;
					x = 34 * GUI_GRID_W + GUI_GRID_X;
					y = 14.5 * GUI_GRID_H + GUI_GRID_Y;
					w = 8 * GUI_GRID_W;
					h = 1 * GUI_GRID_H;
				};
				class Debug: Life_RscButtonMenu
				{
					idc = 2413;
					text = "Debug"; //--- ToDo: Localize;
					x = 34 * GUI_GRID_W + GUI_GRID_X;
					y = 16 * GUI_GRID_H + GUI_GRID_Y;
					w = 8 * GUI_GRID_W;
					h = 1 * GUI_GRID_H;
					onButtonClick = "[] call life_fnc_adminDebugCon;";
				};
	};
};



/*
class life_admin_menu {
	idd = 2900;
	name= "life_admin_menu";
	movingEnable = false;
	enableSimulation = true;
	onLoad = "[] spawn life_fnc_adminMenu;";

	class controlsBackground {
		class Life_RscTitleBackground:Life_RscText {
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
			idc = -1;
			x = 0.1;
			y = 0.2;
			w = 0.8;
			h = (1 / 25);
		};

		class MainBackground:Life_RscText {
			colorBackground[] = {0, 0, 0, 0.7};
			idc = -1;
			x = 0.1;
			y = 0.2 + (11 / 250);
			w = 0.8;
			h = 0.6 - (2 / 250);
		};
	};

	class controls {


		class Title : Life_RscTitle {
			colorBackground[] = {0, 0, 0, 0};
			idc = 2901;
			text = "$STR_Admin_Title";
			x = 0.1;
			y = 0.2;
			w = 0.6;
			h = (1 / 25);
		};

		class PlayerList_Admin : Life_RscListBox
		{
			idc = 2902;
			text = "";
			sizeEx = 0.035;
			//colorBackground[] = {0,0,0,0};
			onLBSelChanged = "[_this] spawn life_fnc_adminQuery";

			x = 0.12; y = 0.26;
			w = 0.30; h = 0.4;
		};

		class PlayerBInfo : Life_RscStructuredText
		{
			idc = 2903;
			text = "";
			x = 0.42;
			y = 0.25;
			w = 0.35;
			h = 0.6;
		};

		class CloseButtonKey : Life_RscButtonMenu {
			idc = -1;
			text = "$STR_Global_Close";
			onButtonClick = "closeDialog 0;";
			x = -0.06 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
			y = 0.88 - (1 / 25);
			w = (6.25 / 40);
			h = (1 / 25);
		};

		class AdminID : Life_RscButtonMenu {
			idc = -1;
			text = "$STR_Admin_GetID";
			onButtonClick = "[] call life_fnc_admingetID;";
			x = 0.1 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
			y = 0.88 - (1 / 25);
			w = (6.25 / 40);
			h = (1 / 25);
		};

		class Compensate : Life_RscButtonMenu {
			idc = 2904;
			text = "$STR_Admin_Compensate";
			onButtonClick = "createDialog ""Life_Admin_Compensate"";";
			x = 0.26 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
			y = 0.88 - (1 / 25);
			w = (6.25 / 40);
			h = (1 / 25);
		};

		class Spectate : Life_RscButtonMenu {
			idc = 2905;
			text = "$STR_Admin_Spectate";
			onButtonClick = "[] call life_fnc_adminSpectate;";
			x = 0.42 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
			y = 0.88 - (1 / 25);
			w = (6.25 / 40);
			h = (1 / 25);
		};

		class Teleport : Life_RscButtonMenu {
			idc = 2906;
			text = "$STR_Admin_Teleport";
			onButtonClick = "[] call life_fnc_adminTeleport; hint 'Select where you would like to teleport';";
			x = 0.58 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
			y = 0.88 - (1 / 25);
			w = (6.25 / 40);
			h = (1 / 25);
		};

		class TeleportHere : Life_RscButtonMenu {
			idc = 2907;
			text = "$STR_Admin_TpHere";
			onButtonClick = "[] call life_fnc_adminTpHere;";
			x = -0.06 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
			y = 0.885;
			w = (6.25 / 40);
			h = (1 / 25);
		};

		class God : Life_RscButtonMenu {
			idc = 2908;
			text = "$STR_Admin_God";
			onButtonClick = "[] call life_fnc_adminGodMode;";
			x = 0.1 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
			y = 0.885;
			w = (6.25 / 40);
			h = (1 / 25);
		};

		class Freeze : Life_RscButtonMenu {
			idc = 2909;
			text = "$STR_Admin_Freeze";
			onButtonClick = "[] call life_fnc_adminFreeze;";
			x = 0.26 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
			y = 0.885;
			w = (6.25 / 40);
			h = (1 / 25);
		};

		class Markers : Life_RscButtonMenu {
			idc = 2910;
			text = "$STR_Admin_Markers";
			onButtonClick = "[] spawn life_fnc_adminMarkers;";
			x = 0.42 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
			y = 0.885;
			w = (6.25 / 40);
			h = (1 / 25);
		};

		class Debug : Life_RscButtonMenu {
			idc = 2911;
			text = "$STR_Admin_Debug";
			onButtonClick = "[] call life_fnc_adminDebugCon;";
			x = 0.58 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
			y = 0.885;
			w = (6.25 / 40);
			h = (1 / 25);
		};
	};
};
