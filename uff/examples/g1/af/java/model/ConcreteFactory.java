public class ${ConcreteFactory} extends ${AbstractFactory} {
	#for x in range(0, len($AbstractProduct)):
	@Override
	public ${AbstractProduct[x]} ${AbstractMethod[x]}()
	{
		return new  ${Product[x]}();
	}
	#end for
}
