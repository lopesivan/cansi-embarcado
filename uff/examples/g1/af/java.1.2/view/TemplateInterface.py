# Product Interface
from abc import ABCMeta, abstractmethod

class TemplateInterface:
    __metaclass__ = ABCMeta

    @abstractmethod
    def put(self):
        pass

    @abstractmethod
    def save(self):
        pass
