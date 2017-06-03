# Product_java

from Java.af.Product_java import Product_java
from TemplateInterface import TemplateInterface


class ClsProduct(TemplateInterface):
    def __init__(self, dataModel):

        # AbstractFactory
        abstract_factory = dataModel['AbstractFactory']
        AbstractFactory = abstract_factory[0].keys()[0]

        d = abstract_factory[0][AbstractFactory][1:]

        self.__files = []
        idx = 0

        for item in d:
            cp = item.keys()[0]
            abstract_product = item[cp][0].keys()[0]
            doIt = item[cp][0][abstract_product][0]

            for product in item[cp][0][abstract_product][1:]:
                self.__files.append(Product_java())
                self.__files[idx].AbstractProduct = abstract_product
                self.__files[idx].Product = product
                self.__files[idx].doIt = doIt

                idx = idx + 1

    def put(self):
        for f in self.__files:
            fileName = "%s.java" % f.Product
            print ("File: %s" % fileName)
            print (f)

    def save(self):
        for f in self.__files:
            fileName = "%s.java" % f.Product
            open(fileName, 'w').write(str(f))
