public enum ${Family} {

	#for x in range(0, len($FamilyTypes)):
	#if x == len($FamilyTypes)-1:
	${FamilyTypes[x]}(${x});
	#else
	${FamilyTypes[x]}(${x}),
	#end if
	#end for

	private final int ${family}Type;

	${Family}(int ${family}Type)
	{
		this.${family}Type = ${family}Type;
	}

}
