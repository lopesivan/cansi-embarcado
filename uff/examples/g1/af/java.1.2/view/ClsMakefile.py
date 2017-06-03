# Makefile
from Java.af.Makefile import Makefile
from TemplateInterface import TemplateInterface


class ClsMakefile(TemplateInterface):
    def __init__(self, dataModel):
        self.__file = Makefile()
        self.__name = "Makefile"

        # Client
        client = dataModel['Client'][0]
        self.__file.Client = client

    def put(self):
        print (self.__file)

    def save(self):
        fileName = "%s" % self.__name
        open(fileName, 'w').write(str(self.__file))
