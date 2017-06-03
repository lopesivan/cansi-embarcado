public class ${Client} {
	public static void main(String[] args)
	{

		#for x in range(0, len($FamilyTypes)):
		//${Family} ${Family}Type = ${Family}.${FamilyTypes[x]};
		#end for
		${Family} ${Family}Type = ${Family}.${FamilyTypes[0]};

		${AbstractFactory} factory = ${AbstractFactory}.${Get}(${Family}Type);

		#for x in range(0, len($AbstractProduct)):
		${AbstractProduct[x]} obj_${x} = factory.${AbstractMethod[x]}();
		obj_${x}.${doIt[x]}();

		#end for
	}

}
