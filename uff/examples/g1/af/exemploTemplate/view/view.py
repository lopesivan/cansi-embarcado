import yaml
from AbstractFactory import AbstractFactory


if __name__ == "__main__":

    config_file = file('af.yaml', 'r')
    dataModel = yaml.load(config_file)
    config_file.close()

    #
    # arquivo 1
    #
    factory = AbstractFactory.get_factory('Family')
    f = factory.get_ball(dataModel)
    f.put()

    #
    # arquivo 2
    #
    factory = AbstractFactory.get_factory('AbstractFactory')
    f = factory.get_ball(dataModel)
    f.put()

