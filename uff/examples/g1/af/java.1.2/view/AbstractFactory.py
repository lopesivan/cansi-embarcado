#Abstract Factory
from ConcreteFactoryFamily import ConcreteFactoryFamily

f = {
    'Family': ConcreteFactoryFamily()
}

class AbstractFactory:
    @staticmethod
    def get_factory(factory):
        return f[factory]
