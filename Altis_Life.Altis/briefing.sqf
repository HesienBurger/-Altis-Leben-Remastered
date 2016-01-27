waitUntil {!isNull player && player == player};
if(player diarySubjectExists "rules")exitwith{};

player createDiarySubject ["serverinfo","Server Information"];
player createDiarySubject ["credits","Credits"];

/*  Example
	player createDiaryRecord ["", //Container
		[
			"", //Subsection
				"
				TEXT HERE<br/><br/>
				"
		]
	];
*/
	player createDiaryRecord["serverinfo",
		[
			"Server Information",
				"
					Altis Life Remastered/Modded | Teamspeak IP: 000:000:000:2302 | Server #1 IP: 000:000:000:2302 
				"
		]
	];
	
	player createDiaryRecord["credits",
		[
			"Credits",
				"
					Altis Life Remastered/Modded | Teamspeak IP: 000:000:000:2302 | Server #1 IP: 000:000:000:2302 
				"
		]
	];