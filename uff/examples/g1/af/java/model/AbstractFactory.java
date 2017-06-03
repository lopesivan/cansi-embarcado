public abstract class ${AbstractFactory} {
	public static ${AbstractFactory} ${Get}(${Family} ${Family}Type)
	{
		#if len($ConcreteFactory) == 1:
		return new ${ConcreteFactory[0]}();
		#else


		if (${Family}Type == ${Family}.${FamilyTypes[0]}) {
			return new ${ConcreteFactory[0]}();
		}
		
		#for x in range(1, len($FamilyTypes)-1):
		else if (${Family}Type == ${Family}.${FamilyTypes[x]}) {
			return new ${ConcreteFactory[x]}();
		}
		#end for

		else {
			// ${FamilyTypes[-1]}
			return new ${ConcreteFactory[-1]}();
		}
		#end if
	}

	#for x in range(0, len($AbstractMethod)):
	public abstract ${AbstractProduct[x]} ${AbstractMethod[x]}();
	#end for
}

