
# AbstractProduct_java
from Java.af.AbstractProduct_java import AbstractProduct_java
from TemplateInterface import TemplateInterface


class ClsAbstractProduct(TemplateInterface):
    def __init__(self, dataModel):

        # AbstractFactory
        abstract_factory = dataModel['AbstractFactory']
        AbstractFactory = abstract_factory[0].keys()[0]

        d = abstract_factory[0][AbstractFactory][1:]

        self.__files = []
        for index, item in enumerate(d):
            cp = item.keys()[0]
            abstract_product = item[cp][0].keys()[0]
            method = item[cp][0][abstract_product][0]

            self.__files.append(AbstractProduct_java())
            self.__files[index].AbstractProduct = abstract_product
            self.__files[index].doIt = method

    def put(self):
        for f in self.__files:
            fileName = "%s.java" % f.AbstractProduct
            print ("File: %s" % fileName)
            print (f)

    def save(self):
        for f in self.__files:
            fileName = "%s.java" % f.AbstractProduct
            open(fileName, 'w').write(str(f))
