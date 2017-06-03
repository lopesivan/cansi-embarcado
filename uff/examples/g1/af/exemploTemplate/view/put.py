import yaml
from AbstractFactory import AbstractFactory


if __name__ == "__main__":

    config_file = file('af.yaml', 'r')
    dataModel = yaml.load(config_file)
    config_file.close()

    #
    # Family
    #
    factory = AbstractFactory.get_factory('Family')
    f = factory.get_ball(dataModel)
    f.put()

    #
    # AbstractFactory
    #
    factory = AbstractFactory.get_factory('AbstractFactory')
    f = factory.get_ball(dataModel)
    f.put()

    #
    # AbstractProduct
    #
    factory = AbstractFactory.get_factory('AbstractProduct')
    f = factory.get_ball(dataModel)
    f.put()

    #
    # ConcreteFactory
    #
    factory = AbstractFactory.get_factory('ConcreteFactory')
    f = factory.get_ball(dataModel)
    f.put()

    #
    # Product
    #
    factory = AbstractFactory.get_factory('Product')
    f = factory.get_ball(dataModel)
    f.put()

    #
    # Client
    #
    factory = AbstractFactory.get_factory('Client')
    f = factory.get_ball(dataModel)
    f.put()

    #
    # Build
    #
    factory = AbstractFactory.get_factory('Build')
    f = factory.get_ball("build")
    f.put()

    #
    # Makefile
    #
    factory = AbstractFactory.get_factory('Makefile')
    f = factory.get_ball(dataModel)
    f.put()
