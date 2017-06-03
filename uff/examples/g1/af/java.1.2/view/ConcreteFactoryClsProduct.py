from ClsProduct import ClsProduct


class ConcreteFactoryClsProduct:
    def get_ball(self, dataModel):
        return ClsProduct(dataModel)