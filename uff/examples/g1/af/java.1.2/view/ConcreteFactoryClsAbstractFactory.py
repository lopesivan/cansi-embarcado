from ClsAbstractFactory import ClsAbstractFactory


class ConcreteFactoryClsAbstractFactory:
    def get_ball(self, dataModel):
        return ClsAbstractFactory(dataModel)
