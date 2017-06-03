# build_haml

from Java.af.build_haml import build_haml as build
from TemplateInterface import TemplateInterface


class ClsBuild(TemplateInterface):
    def __init__(self, name):
        self.__file = build()
        self.__name = name

    def put(self):
        print (self.__file)

    def save(self):
        fileName = "%s.haml" % self.__name
        open(fileName, 'w').write(str(self.__file))