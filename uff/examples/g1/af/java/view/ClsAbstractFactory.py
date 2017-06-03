# AbstractFactory_java

from Java.af.AbstractFactory_java import AbstractFactory_java
from TemplateInterface import TemplateInterface


class ClsAbstractFactory(TemplateInterface):
    def __init__(self, dataModel):
        self.__file = AbstractFactory_java()

        # Family
        family = dataModel['Family']
        self.__file.Family = family[0]
        FamilyTypes = family[1].keys()[0]
        self.__file.FamilyTypes = family[1][FamilyTypes]

        # ConcreteFactory
        concrete_factory = dataModel['ConcreteFactory']
        self.__file.ConcreteFactory = concrete_factory

        # AbstractFactory
        abstract_factory = dataModel['AbstractFactory']
        AbstractFactory = abstract_factory[0].keys()[0]
        self.__file.AbstractFactory = AbstractFactory

        get = abstract_factory[0][AbstractFactory][0]
        self.__file.Get = get

        d = abstract_factory[0][AbstractFactory][1:]

        AbstractProduct = []
        method = []

        for item in d:
            cp = item.keys()[0]
            method.append(cp)

            ap = item[cp][0].keys()[0]
            AbstractProduct.append(ap)

        self.__file.AbstractProduct = AbstractProduct
        self.__file.AbstractMethod = method

    def put(self):
        fileName = "%s.java" % self.__file.AbstractFactory
        print ("File: %s" % fileName)
        print (self.__file)

    def save(self):
        fileName = "%s.java" % self.__file.AbstractFactory
        open(fileName, 'w').write(str(self.__file))
