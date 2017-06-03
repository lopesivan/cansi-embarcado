#Abstract Factory
from ConcreteFactoryClsAbstractFactory import ConcreteFactoryClsAbstractFactory
from ConcreteFactoryClsAbstractProduct import ConcreteFactoryClsAbstractProduct
from ConcreteFactoryClsBuild import ConcreteFactoryClsBuild
from ConcreteFactoryClsClient import ConcreteFactoryClsClient
from ConcreteFactoryClsConcreteFactory import ConcreteFactoryClsConcreteFactory
from ConcreteFactoryClsFamily import ConcreteFactoryClsFamily
from ConcreteFactoryClsMakefile import ConcreteFactoryClsMakefile
from ConcreteFactoryClsProduct import ConcreteFactoryClsProduct

f = {
    'AbstractFactory': ConcreteFactoryClsAbstractFactory(),
    'AbstractProduct': ConcreteFactoryClsAbstractProduct(),
    'Family': ConcreteFactoryClsFamily(),
    'ConcreteFactory': ConcreteFactoryClsConcreteFactory(),
    'Product': ConcreteFactoryClsProduct(),
    'Client': ConcreteFactoryClsClient(),
    'Build': ConcreteFactoryClsBuild(),
    'Makefile': ConcreteFactoryClsMakefile()
}


class AbstractFactory:
    @staticmethod
    def get_factory(factory):
        return f[factory]
