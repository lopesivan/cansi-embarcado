# ConcreteFactory_java
from Java.af.ConcreteFactory_java import ConcreteFactory_java
from TemplateInterface import TemplateInterface


class ClsConcreteFactory(TemplateInterface):
    def __init__(self, dataModel):

        # ConcreteFactory
        concrete_factory = dataModel['ConcreteFactory']

        # AbstractFactory
        abstract_factory = dataModel['AbstractFactory']
        AbstractFactory = abstract_factory[0].keys()[0]

        self.__files = []
        idx = 1
        for index, item in enumerate(concrete_factory):

            self.__files.append(ConcreteFactory_java())
            self.__files[index].ConcreteFactory = item
            self.__files[index].AbstractFactory = AbstractFactory

            d = abstract_factory[0][AbstractFactory][1:]

            AbstractProduct = []
            method = []
            Product = []

            for item in d:
                cp = item.keys()[0]
                method.append(cp)

                ap = item[cp][0].keys()[0]
                AbstractProduct.append(ap)

                p = item[cp][0][ap][idx]
                Product.append(p)

            idx = idx + 1
            self.__files[index].AbstractProduct = AbstractProduct
            self.__files[index].AbstractMethod = method
            self.__files[index].Product = Product

    def put(self):
        for f in self.__files:
            fileName = "%s.java" % f.ConcreteFactory
            print ("File: %s" % fileName)
            print (f)

    def save(self):
        for f in self.__files:
            fileName = "%s.java" % f.ConcreteFactory
            open(fileName, 'w').write(str(f))

