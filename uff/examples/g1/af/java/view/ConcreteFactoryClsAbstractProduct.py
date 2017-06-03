#Factory
from ClsAbstractProduct import ClsAbstractProduct


class ConcreteFactoryClsAbstractProduct:
    def get_ball(self, dataModel):
        return ClsAbstractProduct(dataModel)

