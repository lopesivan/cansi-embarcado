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
    'Build': ConcreteFactoryClsBuild(),
    'Client': ConcreteFactoryClsClient(),
    'ConcreteFactory': ConcreteFactoryClsConcreteFactory(),
    'Family': ConcreteFactoryClsFamily(),
    'Makefile': ConcreteFactoryClsMakefile(),
    'Product': ConcreteFactoryClsProduct(),
}


class AbstractFactory:
    @staticmethod
    def get_factory(factory):
        return f[factory]
