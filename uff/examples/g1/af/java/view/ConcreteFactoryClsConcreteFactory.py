from ClsConcreteFactory import ClsConcreteFactory


class ConcreteFactoryClsConcreteFactory:
    def get_ball(self, dataModel):
        return ClsConcreteFactory(dataModel)