# Client_java

from Java.af.Client_java import Client_java
from TemplateInterface import TemplateInterface


class ClsClient(TemplateInterface):
    def __init__(self, dataModel):
        self.__file = Client_java()

        # Client
        client = dataModel['Client'][0]
        self.__file.Client = client

        # Family
        family = dataModel['Family']
        self.__file.Family = family[0]
        FamilyTypes = family[1].keys()[0]
        self.__file.FamilyTypes = family[1][FamilyTypes]

        # AbstractFactory
        abstract_factory = dataModel['AbstractFactory']
        AbstractFactory = abstract_factory[0].keys()[0]
        self.__file.AbstractFactory = AbstractFactory

        get = abstract_factory[0][AbstractFactory][0]
        self.__file.Get = get

        d = abstract_factory[0][AbstractFactory][1:]

        AbstractProduct = []
        method = []
        doIt = []

        for item in d:
            cp = item.keys()[0]
            method.append(cp)

            ap = item[cp][0].keys()[0]
            AbstractProduct.append(ap)
            #m= item[cp][0][ap][0]
            doit = item[cp][0][ap][0]
            doIt.append(doit)

        self.__file.AbstractProduct = AbstractProduct
        self.__file.AbstractMethod = method
        self.__file.doIt = doIt

    def put(self):
        fileName = "%s.java" % self.__file.Client
        print ("File: %s" % fileName)
        print (self.__file)

    def save(self):
        fileName = "%s.java" % self.__file.Client
        open(fileName, 'w').write(str(self.__file))
